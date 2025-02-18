# cs310-fall2024-cp4-group-assignment

Full Names: Alex Eskenazi, Vishil Patel

GitHub IDs: alexeskenazi, vishilpatel1

Binghamton CS userids: aeskena1, vpatel57

Discord names: palexxx, vishilpatel

Please type or copy the CS 310 honesty statement here:
I have worked on this project individually, and have not given or received too much help. In particular, I have not gained access to any other students' repositories, files, or code, nor have I given any other students access to mine. I have not used generative AI, including but not limited to chatGPT, unless explicitly authorized for this assignment. I understand that my code will be run through a very effective similarity checker, and that academic honesty violations are taken seriously.

With respect to the honesty statement, if you have any doubts whatsoever about whether you have completed the assignment appropriately, please describe briefly here:

CS310 - Demo Notes

How do you maintain links between your data structures?
Memory Management:
Voter objects are owned by the BST which deletes them in its destructor.
The MaxHeap and the Age Vector hold pointers to the Voter objects.

How are memory leaks prevented? Who releases the memory?
The BST is made up of BSTNodes.
Each BSTNode has a pointer to the Voter and owns it. Meaning that the BSTNode destructure deletes the Voters when it is deleted  (in the BSTNode  destructor)
The BSTNode is deleted when the BST is deleted (in the BST destructor).
The other two data structures, the MaxHeap and the Age Array do not delete the Voter objects.

How do you update your bst/voter after percolate up, extract, etc.?
Since the Voter is in the BST, we just search for it and do changes on the object.
If the Impact changes because of changes to support/strength or likelihood then we call an update function on Impact Max Heap, find the voter in the heap and percolate it up.
We can percolate up because we know that the Impact only increases.
If the Voter voted, we just mark it as voted and exclude it going forward.

Why does the Impact only increase and does not go down?
The support command only increases the strength.
The reduce-likelihood only reduces the likelihood (likelihood = likelihood * (100-X)/100
impact = strength / likelihood, strength goes up and likelihood goes down so impact only can go up.

How is the BST sorted? What is your BST organized by?
The BST is sorted by keys of the form first name + ”  ”+ last name.

What is the complexity of finding a Voter?
What is the time complexity of finding a user in the Binary search Tree?
Voters are looked up by their key (based on their names)
Since it is a Binary Search Tree, on average the lookup is O(Log N). 
This is on average if we assume the tree is balanced.

Are you removing the already voted from the system or just flagging?
Not removed, just marked (flagged) as already voted.
Why? To be able to stop a voter who already voted from registering again. 

What did you sort by for each?
BST is by the name based key. Used for the rest (voter, voted, support, likelihood)
MaxHeap is by Impact. Use for chauffeur.
Age Array is by Age. Used for show-impact.

Age Array/Vector Implementation:
Used for show-impact to list all the voters sorted by age.
Implemented as a Vector of Voter Vectors of pointers to Voters  (vector< vector<Voter*> > ages; )
The outer vector uses the age of the voter to find the inner Voter vector. This is done in constant time.  For example, to find all the inner vectors for age 21 we just look up ages[21].
To print all the Voter objects by age we simply loop through the ages vector and for each one we loop through the Voters. We skip any Voter objects marked as voted.
Printing the list is O(N) because we print sequentially and only visit each object once.
Adding a Voter is O(1) 
Why did you guys use a Vector instead of Arrays? To avoid having to deal with increasing capacity and having to allocate memory and copy the array.


Efficiency Requirements
support and reduce-likelihood work in O(log N) using the BST to search for Voters.
voted and voter must work in O(log N) time. They also use the BST…
chauffeur must work in O(log N) time. Retrieving the Voter with highest Impact from the MaxHeap is O(1), but extracting it requires percolating up which is O(log N).
show-impact should work in O(N) time. Because it shows the voters by age, it uses the Age Array (Vector) which is sorted by Age.
One visit per voter

Testing
To test while writing the code we used a test file that provided the user inputs and expected outputs.
This helped make sure we test Edge Cases and that we do not introduce bugs as we change things.
Example:
# Teacher test: Test-case 2 : voter, voted, and support
>> voter Lai Tulsi 16
out: Voter age should be between 18 and 118
Lines that start with “#” are skipped so they are considered comments.
Lines that start with “>>” are use input
Lines that start with “out:” are expected outputs.

