#include "bst.h"
#include "Voter.h"
#include <iostream>

bool testAddVoter() {
    BST tree;

    Voter v1("F01", "L01", 25);
    Voter v2("F02", "L02", 25);
    Voter v3("F03", "L03", 25);

    tree.addVoter(&v1);
    tree.addVoter(&v2);
    tree.addVoter(&v3);

    if (tree.getVoter(v1) != &v1) {
        std::cout << "testAddVoter failed: v1 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v2) != &v2) {
        std::cout << "testAddVoter failed: v2 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v3) != &v3) {
        std::cout << "testAddVoter failed: v3 not found" << std::endl;
        return false;
    }
    return true;
}

bool testGetVoter() {
    BST tree;
    Voter v1("F01", "L01", 25);
    Voter v2("F02", "L02", 25);

    tree.addVoter(&v1);
    tree.addVoter(&v2);

    Voter* result1 = tree.getVoter(v1);
    Voter* result2 = tree.getVoter(v2);
    Voter v3("Non", "Existent", 25);

    if (result1 != &v1) {
        std::cout << "testGetVoter failed: v1 not found" << std::endl;
        return false;
    }
    if (result2 != &v2) {
        std::cout << "testGetVoter failed: v2 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v3) != nullptr) {
        std::cout << "testGetVoter failed: non-existent voter found" << std::endl;
        return false;
    }
    return true;
}

bool testDeeperTree() {
    BST tree;

    Voter v1("F01", "L01", 25);
    Voter v2("F02", "L02", 25);
    Voter v3("F03", "L03", 25);
    Voter v4("F04", "L04", 25);
    Voter v5("F05", "L05", 25);

    tree.addVoter(&v1);
    tree.addVoter(&v2);
    tree.addVoter(&v3);
    tree.addVoter(&v4);
    tree.addVoter(&v5);

    if (tree.getVoter(v1) != &v1) {
        std::cout << "testDeeperTree failed: v1 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v2) != &v2) {
        std::cout << "testDeeperTree failed: v2 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v3) != &v3) {
        std::cout << "testDeeperTree failed: v3 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v4) != &v4) {
        std::cout << "testDeeperTree failed: v4 not found" << std::endl;
        return false;
    }
    if (tree.getVoter(v5) != &v5) {
        std::cout << "testDeeperTree failed: v5 not found" << std::endl;
        return false;
    }
    return true;
}

bool testEdgeCases() {
    BST tree;

    Voter v1("F01", "L01", 25);
    Voter v2("F02", "L02", 25);

    tree.addVoter(&v1);
    tree.addVoter(&v2);

    if (tree.getVoter(v1) != &v1) {
        std::cout << "testEdgeCases failed: v1 not found" << std::endl;
        return false; // Should return the first F01 L01
    }
    if (tree.getVoter(v2) != &v2) {
        std::cout << "testEdgeCases failed: v2 not found" << std::endl;
        return false;
    }
    return true;
}

int main() {
    if (!testAddVoter()) {
        std::cout << "testAddVoter failed." << std::endl;
    } else if (!testGetVoter()) {
        std::cout << "testGetVoter failed." << std::endl;
    } else if (!testDeeperTree()) {
        std::cout << "testDeeperTree failed." << std::endl;
    } else if (!testEdgeCases()) {
        std::cout << "testEdgeCases failed." << std::endl;
    } else {
        std::cout << "All tests passed!" << std::endl;
    }
    return 0;
}