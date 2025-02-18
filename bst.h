#pragma once
#include "Voter.h"


class BSTNode {
    public:
        string key;
        Voter* voter;
        BSTNode* left;
        BSTNode* right;

        BSTNode() {
            key = "";
            voter = nullptr;
            left = nullptr;
            right = nullptr;
        }

        BSTNode(string k, Voter* v) {
            key = k;
            voter = v;
            left = nullptr;
            right = nullptr;
        }

        ~BSTNode() {
            // cout << "Deleting BSTNode with key: " << key << endl;
            delete voter;
            voter = nullptr;
        }
};

class BST {
    public:
        // vector<BSTNode> voters; // TEMP while buidling the BST
        BSTNode* root;
        void addVoter(Voter* voter);
        Voter* getVoter(const Voter& voter);
        ~BST();
    private:
        void deleteSubtree(BSTNode* node);
};
