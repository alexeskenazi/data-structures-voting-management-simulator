#pragma once
#include <stdlib.h>
#include <vector>
#include "Voter.h"
#include <list>
#include "AgeVector.h"
#include "MaxHeap.h"
#include "bst.h"
using namespace std;


#define SUCCESS -1
#define ERROR_VOTER_AGE_INVALID 0
#define ERROR_VOTER_NOT_FOUND 1
#define ERROR_VOTER_ALREADY_ADDED 2
#define ERROR_VOTER_VOTED 3


class VoterSystem{
public:
    AgeVector ageVector; // Holds pointers to the voters by age
    MaxHeap maxImpactHeap; // Holds pointers to the voters by impact
    BST bst; // Holds pointers to the voters by name
    
    VoterSystem();
    ~VoterSystem();

    bool isVoterAgeValid(const Voter& voter);
    int addVoter(Voter& voter);
    bool voterAlreadyAdded(const Voter &voter);
    string showImpact();
    int markVoted(Voter &voter);
    int addSupport(const Voter &voter, int strength);
    Voter* getVoter(const Voter &voter);
    int reduceLikelihood(const Voter &voter, int reduction);
    Voter* getMaxImpactVoterToChauffeur();
    
};