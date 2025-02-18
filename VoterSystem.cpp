#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "VoterSystem.h"

VoterSystem::VoterSystem(){
}

VoterSystem::~VoterSystem(){
}

bool VoterSystem::isVoterAgeValid(const Voter& voter){
    int age = voter.age;
    return !(age > 118 || age < 18);
}

int VoterSystem::addVoter(Voter& voter){
   if(!isVoterAgeValid(voter)) {
        return ERROR_VOTER_AGE_INVALID;
    }
    if(voterAlreadyAdded(voter)){
        return ERROR_VOTER_ALREADY_ADDED;
    }

    Voter* v = new Voter(voter);

    // Add Pointers to voter to the age vector, max impact heap, and bst
    // The bst will own the voter memory
    ageVector.AddVoter(v);
    maxImpactHeap.addVoter(v);
    bst.addVoter(v);
    return SUCCESS;
 }

bool VoterSystem::voterAlreadyAdded(const Voter &voter){
    Voter* v = getVoter(voter);
    return v != nullptr;
}

string VoterSystem::showImpact(){
    return ageVector.getVotersString();
}

int VoterSystem::markVoted(Voter &voter){
    Voter* v = getVoter(voter);
    if(v == nullptr){
        return ERROR_VOTER_NOT_FOUND;
    }
    if(v->voted){
        return ERROR_VOTER_VOTED;
    }
    v->voted = true;
    voter = *v; // we need the age from the original voter because it is not passes in the "voted" command
    return SUCCESS;
}

int VoterSystem::addSupport(const Voter &voter, int strength){
    Voter* v = getVoter(voter);
    if(v == nullptr){
        return ERROR_VOTER_NOT_FOUND;
    }   
    if(v->voted){
        return ERROR_VOTER_VOTED;
    }
    v->setStrength(v->strength + strength);
    maxImpactHeap.updateVoter(v);
    return SUCCESS;
}

Voter* VoterSystem::getVoter(const Voter &voter){
    // Do the voter search using the BST to get O(log n) time
    return bst.getVoter(voter);
}


int VoterSystem::reduceLikelihood(const Voter &voter, int reduction){
    Voter* v = getVoter(voter);
    if(v == nullptr){
        return ERROR_VOTER_NOT_FOUND;
    } 
    if(v->voted){
        return ERROR_VOTER_VOTED;
    }
    v->reduceLikelihood(reduction);
    maxImpactHeap.updateVoter(v);
    return SUCCESS;
}

Voter* VoterSystem::getMaxImpactVoterToChauffeur(){
    // From the teacher: Once a voter has been driven to the polls to vote, any future feedback 
    // from volunteers on that voter's strength of support or likelihood of voting should be 
    Voter* v = maxImpactHeap.getMaxImpactVoterToChauffeur();
    if(v == nullptr){
        return nullptr;
    }
    v->voted = true;
    return v;
}
