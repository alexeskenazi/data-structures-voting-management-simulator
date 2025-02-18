#pragma once
#include <vector>
#include "Voter.h"




class MaxHeap{
public:
    vector <Voter*> list;
    void addVoter(Voter* voter);
    void updateVoter(Voter* voter);
    void percolateUp(int index);
    void percolateDown(int index);
    int findVoteIndex(Voter* voter);
    int getParent(int index);
    void swap(int index1, int index2);
    void showHeap();
    Voter* getMaxImpactVoterToChauffeur();
    void removeVoter(Voter* voter);
};