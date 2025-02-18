#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "helper.h"
#include "VoterSystem.h"
#include "MaxHeap.h"
using namespace std;

void checkOutput(const string& output, const string& expectedOutput);

string handleNewVoter(stringstream &s);
string handleVoted(stringstream &s);
string handleSupport(stringstream &s);
string handleReduceLikelihood(stringstream &s);
string handleShowImpact(stringstream &s);
string handleChauffeur(stringstream &s);
string handleQuit(stringstream &s);

VoterSystem vs;
bool fromFile = false;

int main(int argc, char *argv[]) {

    istream* input = &cin;
    ifstream infile;

    if (argc >= 2) {
        string inputFile = argv[1];
        infile.open(inputFile);
        if (!infile) {
            cerr << "Error opening file: " << inputFile << endl;
            return 1;
        }
        input = &infile;
        fromFile = true;
    }


    string line;

    // The following loop will read a line at a time
    while(getline(*input, line)) {

        stringstream s(line);
        string command;
        string expectedOutput;

        if(fromFile) {
            
            if(line.empty()){
                cout << endl;
                continue;
            }

            if(line[0] == '#'){
                cout << line << endl;
                continue;
            }

            // get the first token
            string token;
            s >> token;

            if(token == ">>"){
                s >> command;
                cout << line << endl;
                getline(*input, expectedOutput);
                stringstream output(expectedOutput);
                string out;
                output >> out;
                if(out == "out:"){
                     expectedOutput = expectedOutput.substr(5);
                }
                // handle case with "out-n: 2" where 2 is the number of lines to get as expeted output
                if(out == "out-n:"){
                    int n = 0;
                    output >> n;
                    expectedOutput = "";
                    for(int i = 0; i < n; ++i){
                        string temp;
                        getline(*input, temp);
                        expectedOutput += temp + "\n";
                    }

                }
            }
        }
        else {
             if(line.empty()){
                cout << endl;
                continue;
            }
            s >> command;
            if(command == ""){
                continue;
            }
        }


        if(command == "quit"){
            string strOut = handleQuit(s);
            checkOutput(strOut, expectedOutput);
            break;
        }

        if( command == "voter" ) {
            string strOut = handleNewVoter(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "voted" ) {
            string strOut = handleVoted(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "support") {
            string strOut = handleSupport(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "reduce-likelihood" ) {
            string strOut = handleReduceLikelihood(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "show-impact" ) {
            string strOut = handleShowImpact(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "chauffeur" ) {
            string strOut = handleChauffeur(s);
            checkOutput(strOut, expectedOutput);
            continue;
        }

        if( command == "clear" ) {
            vs = VoterSystem();
            continue;
        }

        cout << "Invalid command: " << command << endl;
    }

    return 0;
}

void checkOutput(const string& output, const string& expectedOutput){
    // check if the expected output shoudl be ignored 
    if(expectedOutput == "Ignore"){
        cout << "output ignored" << endl;
         cout << "Actual  : " << output << endl;
        return;
    }

    if(!expectedOutput.empty() && output != expectedOutput){
        cout << "!!!!!Expected: " << expectedOutput << endl;
        cout << "!!!!!Actual  : " << output << endl;
    }
    else {
        if(output != ""){
            cout << output << endl;
        }
    }
}

string handleNewVoter(stringstream &s){
    string lastname;
    string firstname;
    int age = 0;
    s >> lastname;
    s >> firstname;
    s >> age;
    Voter voter(firstname, lastname, age);

    int result = vs.addVoter(voter);
    if(result == ERROR_VOTER_AGE_INVALID){
        return "Voter age should be between 18 and 118";
    }
    if(result == ERROR_VOTER_ALREADY_ADDED){
        return firstname + " " + lastname + ", age " + to_string(age) + ", already exists";
    }
    
    return "New voter " + firstname + " " + lastname + ", age " + to_string(age) + ", added";
}

string handleVoted(stringstream &s){
    string lastname;
    string firstname;
    int age = 0;
    s >> lastname;
    s >> firstname;
    
    Voter voter(firstname, lastname, age);
    int result = vs.markVoted(voter);
    age = voter.age;
    if(result == ERROR_VOTER_NOT_FOUND){
        return "Voted " + firstname + " " + lastname + ", age " + to_string(age) + ", not found";
    }
    if(result == ERROR_VOTER_VOTED){
        // Earl Bird already voted
        return firstname + " " + lastname + " already voted";
    }

    return "Voter " + firstname + " " + lastname + ", age " + to_string(age) + ", voted";
}

string handleSupport(stringstream &s){
    string lastname;
    string firstname;
    int age = 0;
    unsigned int strength = 0;
    s >> lastname;
    s >> firstname;
    s >> strength;
    Voter voter(firstname, lastname, age);
    int result = vs.addSupport(voter, strength);
    if(result == ERROR_VOTER_NOT_FOUND){
        return "Support " + firstname + " " + lastname + ", age " + to_string(age) + ", not found";
    }
    if(result == ERROR_VOTER_VOTED){
        // Earl Bird already voted
        return firstname + " " + lastname + " already voted";
    }

    return "Support from " + firstname + " " + lastname + " increased by " + to_string(strength) + " strength points";
}

string handleReduceLikelihood(stringstream &s){
    string lastname;
    string firstname;
    int age = 0;
    unsigned int reduction = 0;
    s >> lastname;
    s >> firstname;
    s >> reduction;
    Voter voter(firstname, lastname, age);
    int result = vs.reduceLikelihood(voter, reduction);
    if(result == ERROR_VOTER_NOT_FOUND){
        return "Reduce-likelihood " + firstname + " " + lastname + ", age " + to_string(age) + ", not found";
    }
    if(result == ERROR_VOTER_VOTED){
        // Earl Bird already voted
        return firstname + " " + lastname + " already voted";
    }
    
    return "Voting likelihood of " + firstname + " " + lastname + " decreased by " + to_string(reduction) + "%.";
}

string handleShowImpact(stringstream &s){
    return vs.showImpact();
    
}

string handleChauffeur(stringstream &s){

        // sample output: Driving Mike Lewis (54): strength of support: 95, likelihood: 67.5, impact: 1.41
        Voter* v = vs.getMaxImpactVoterToChauffeur();
        if(v != nullptr){
            return "Driving " + v->first + " " + v->last + " (" + to_string(v->age) 
                + "): strength of support: " + to_string(v->strength) 
                + ", likelihood: " + to_string_with_precision(v->likelihood, 2) 
                + ", impact: " + to_string_with_precision(v->getImpact(), 2);
            // Driving Mike Lewis (54): strength of support: 95, likelihood: 67.5, impact: 1.41
        }
        else{
            if(fromFile){
                return "No voters found in list" ;
            }
        }
    return "";
}

string handleQuit(stringstream &s){
    return "Exiting Program";
}


