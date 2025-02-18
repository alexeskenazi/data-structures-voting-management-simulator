#!/usr/bin/env bash

# HOW TO RUN:
# 
# 1. Copy the bash file (cp4_test_helper.sh) and the expect file (interaction.exp) to the same directory as your executable (e.g., bin directory).
# 2. cd to the directory of your executable (e.g., bin directory).
# 3. Execute the following command: 
#    "bash cp4_test_helper.sh ./<executable> <testcase-number>"
# 4. Check if your program's output align with the 'EXPECTED OUTPUTS' output.

if [ $# -ne 2 ]; then
	echo "bash cp4_test_helper.sh ./<executable> <testcase-number>"
	exit 1
fi


# ================================================================================================
# Following are simple test cases for testing your program's overall functionality.

declare -A tests

# Test-case 1 : Add voter, call voted and support on the added voter
tests[1]="
voter Renolds Ryan 45
voter Renolds Ryan 45
voter Bird Earl 87
voted Bird Earl 87
support Renolds Ryan 25
quit
"

# Test-case 2 : voter, voted, and support
tests[2]="
voter Lai Tulsi 16
voter Renolds Ryan 45
voter Bird Earl 87
voted Bird Earl 87
voted Bird Earl 87
support Renolds Ryan 25
quit
"

# Test-case 3 : support, reduce-likelihood, show-impact, chauffeur
tests[3]="
voter Brown Bob 20
voter Adams Alice 45
voter Clark Charlie 44
support Brown Bob 20
support Adams Alice 20
show-impact
reduce-likelihood Brown Bob 10
chauffeur
chauffeur
chauffeur
show-impact
quit
"


# ================================================================================================
# Expected outputs of above test-commands
declare -A expected_outputs

expected_outputs[1]="
[ Test-case 1 : Add voter, call voted and support on the added voter ]

New voter Ryan Renolds, age 45, added
Voter Ryan Renolds, age 45, already exists
New voter Earl Bird, age 87, added
Voter Earl Bird, age 87, voted
Support from Ryan Renolds increased by 25 strength points
"

expected_outputs[2]="
[ Test-case 2 : Incorrect inputs testing for a voter]

Voter age should be between 18 and 118
New voter Ryan Renolds, age 45, added
New voter Earl Bird, age 87, added
Voter Earl Bird, age 87, voted
Earl Bird already voted
Support from Ryan Renolds increased by 25 strength points
"


expected_outputs[3]="
[ Test-case 3 : support, reduce-likelihood, show-impact, chauffeur ]

New voter Bob Brown, age 20, added
New voter Alice Adams, age 45, added
New voter Charlie Clark, age 44, added
Support from Bob Brown increased by 20 strength points.
Support from Alice Adams increased by 20 strength points.
Bob Brown (20): strength of support: 95, likelihood: 75, impact: 1.27
Charlie Clark (44): strength of support: 75, likelihood: 75, impact: 1.00
Alice Adams (45); strength of support: 95, likelihood: 75, impact: 1.27
Voting likelihood of Bob Brown decreased by 10%%.
Driving Bob Brown (20): strength of support: 95, likelihood: 67.5, impact: 1.41
Driving Alice Adams (45): strength of support: 95, likelihood: 75, impact: 1.27
Driving Charlie Clark (44): strength of support: 75, likelihood: 75, impact: 1.00
"
# The last "show-impact", which is called after all voters have already voted, should not output anything. 
# > Q4. For the show-impact function should we show all voters including ones that have already voted? Or just the voters that have not voted yet.
# > A4. If a voter votes, they should be removed from all the data structures and so the ones who already voted should NOT be shown for show-impact.
#
# Reason for "10%%" Instead of "%" in "Voting likelihood of Bob Brown decreased by 10%%."
# > In printf, % is a format specifier (e.g., %d, %s). To print a literal %, use %%.


# INTERACTION
clear 
expect interaction.exp "$1" "${tests[$2]}" 2>&1

printf "\n\n--------- EXPECTED OUTPUTS (Don't have to be an exact match) --------- \n\n${expected_outputs[$2]}\n\n\n"
exit 0


