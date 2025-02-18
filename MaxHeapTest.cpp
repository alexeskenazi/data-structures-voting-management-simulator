#include "MaxHeap.h"
#include <cassert>

bool testAddVoter() {
    MaxHeap heap;
    Voter v1("Alice", "Smith", 30);
    Voter v2("Bob", "Johnson", 25);
    Voter v3("Charlie", "Williams", 35);

    heap.addVoter(&v1);
    heap.addVoter(&v2);
    heap.addVoter(&v3);

    if (heap.list.size() != 3) return false;
    if (heap.list[0]->getImpact() != v3.getImpact()) return false;
    if (heap.list[1]->getImpact() != v1.getImpact()) return false;
    if (heap.list[2]->getImpact() != v2.getImpact()) return false;

    return true;
}

bool testUpdateVoter() {
    MaxHeap heap;
    Voter v1("Alice", "Smith", 30);
    Voter v2("Bob", "Johnson", 25);

    heap.addVoter(&v1);
    heap.addVoter(&v2);

    v1.setStrength(100);
    heap.updateVoter(&v1);

    if (heap.list[0]->getImpact() != v1.getImpact()) return false;
    if (heap.list[1]->getImpact() != v2.getImpact()) return false;

    return true;
}

bool testGetMaxImpactVoterToChauffeur() {
    MaxHeap heap;
    Voter v1("Alice", "Smith", 30);
    Voter v2("Bob", "Johnson", 25);
    Voter v3("Charlie", "Williams", 35);

    heap.addVoter(&v1);
    heap.addVoter(&v2);
    heap.addVoter(&v3);

    Voter* maxVoter = heap.getMaxImpactVoterToChauffeur();
    if (maxVoter->getImpact() != v3.getImpact()) return false;
    if (heap.list.size() != 2) return false;

    return true;
}

bool testRemoveVoter() {
    MaxHeap heap;
    Voter v1("Alice", "Smith", 30);
    Voter v2("Bob", "Johnson", 25);
    Voter v3("Charlie", "Williams", 35);

    heap.addVoter(&v1);
    heap.addVoter(&v2);
    heap.addVoter(&v3);

    heap.removeVoter(&v2);
    if (heap.list.size() != 2) return false;
    if (heap.list[0]->getImpact() != v3.getImpact()) return false;
    if (heap.list[1]->getImpact() != v1.getImpact()) return false;

    return true;
}

int main() {
    if (testAddVoter() && testUpdateVoter() && testGetMaxImpactVoterToChauffeur() && testRemoveVoter()) {
        cout << "All tests passed!" << endl;
    } else {
        cout << "Some tests failed." << endl;
    }
    return 0;
}