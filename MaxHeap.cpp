#include<iostream>
#include "MaxHeap.h"

void MaxHeap::addVoter(Voter* voter){
    list.push_back(voter);

    if((int)list.size()==1) {
        return;
    }

    int index = (int)list.size()-1; 

    percolateUp(index);
}

 void MaxHeap::updateVoter(Voter* voter) {
    int index = findVoteIndex(voter);
    if(index == -1) {
        return;
    }

    // we know from the teacher's prompt that the impact only increases
    // because the strength only increases and the likelihood only decreases
    percolateUp(index);
 }

 void MaxHeap::percolateUp(int index) {
    while(index > 0) {
        float childImpact = list[index]->getImpact();
        int indexParent = getParent(index);
        float parentImpact = list[indexParent]->getImpact();

        if (childImpact <= parentImpact) {
            break;
        }
        swap(index, indexParent);
       
        index = indexParent; 
    }
 }

void MaxHeap::percolateDown(int index) {
    int listSize = (int)list.size();
    while(index < listSize) {
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        int maxIndex = index;

        float leftChildImpact = 0;
        float rightChildImpact = 0;
        if(leftChild < listSize) {
            leftChildImpact = list[leftChild]->getImpact();
        }
        if(rightChild < listSize) {
            rightChildImpact = list[rightChild]->getImpact();
        }
        
        float maxImpact = list[maxIndex]->getImpact();

        if(leftChild < listSize && leftChildImpact > maxImpact) {
            maxIndex = leftChild;
        }
        if(rightChild < listSize && rightChildImpact > maxImpact) {
            maxIndex = rightChild;
        }
        if(maxIndex == index) {
            break;
        }
        swap(index, maxIndex);
        index = maxIndex;
    }
   
}

Voter* MaxHeap::getMaxImpactVoterToChauffeur() {
    int listSize = (int)list.size();
    if(listSize == 0) {
        return nullptr;
    }
    
    Voter* maxVoter = list[0];

    // Move last element to root
    list[0] = list[listSize-1];

    // Remove last element
    list.pop_back();

    // Percolate down the new root
    int index = 0;
    percolateDown(index);

    return maxVoter;
}

void MaxHeap::showHeap(){
    cout << "Max Heap: " << endl; 
    for(int i = 0; i < (int)list.size(); ++i){
        cout << list[i]->getImpact() << endl;
    }
}

int MaxHeap::findVoteIndex(Voter* voter) {
    for(int i = 0; i < (int)list.size(); ++i) {
        if(list[i] == voter) {
            return i;
        }
    }
    return -1;
}

int MaxHeap::getParent(int index){
    if(index == 0){
        return 0;
    }
    return (index - 1)/2;
}

void MaxHeap::swap(int index1, int index2){
    Voter* temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

void MaxHeap::removeVoter(Voter* voter) {
    int index = findVoteIndex(voter);
    if(index == -1) {
        return;
    }

    // Move last element to root
    list[index] = list[(int)list.size()-1];

    // Remove last element
    list.pop_back();

    // Percolate down the new root
    percolateDown(index);
}
