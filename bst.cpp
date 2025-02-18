#include "bst.h"

string createVoterKey(const string& first, const string& last) {
    return first + " " + last;
}

BST::~BST() {
    deleteSubtree(root);
}

void BST::deleteSubtree(BSTNode* node) {
    if (node) {
        deleteSubtree(node->left);
        deleteSubtree(node->right);
        delete node;
    }
}

void BST::addVoter(Voter* voter) {
    string voterKey = createVoterKey(voter->first, voter->last);
    BSTNode* newNode = new BSTNode(voterKey, voter);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    BSTNode* curr = root;
    BSTNode* parent = nullptr;
    while (curr) {
        if (newNode->key > curr->key) {
            parent = curr;
            curr = curr->right;
        } else if (newNode->key < curr->key) {
            parent = curr;
            curr = curr->left;
        } else {
            // If the new key is equal to the curr node key, return
            // It should not happen because voters are unique by name
            delete newNode; // Avoid memory leak
            return;
        }
    }

    if (newNode->key > parent->key) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
}

Voter* BST::getVoter(const Voter& voter) {
    std::string key = createVoterKey(voter.first, voter.last);
    BSTNode* curr = root;
    while (curr) {
        if (key > curr->key) {
            curr = curr->right;
        } else if (key < curr->key) {
            curr = curr->left;
        } else {
            return curr->voter;
        }
    }
    return nullptr;
}