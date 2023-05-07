#include "BST.h"
#include <vector>
#include <iostream>

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
    delete root;
    numElements = 0;
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}

void deleteBST(BST::Node* n) {
    if(n != nullptr) {
        if(n->leftChild != nullptr) {
            deleteBST(n->leftChild);
        }
        if(n->rightChild != nullptr) {
            deleteBST(n->rightChild);
        }
        delete(n);
    }
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    deleteBST(root);
    root = nullptr;
    BST::numElements = 0;
}



BST::Node* inserth(BST::Node* temp, int value) {
    if(temp == nullptr) {
        return new BST::Node(value);
    }
    if(temp->data == value) {
        return nullptr;
    }

    if(value > temp->data) {
        BST::Node* rchild = inserth(temp->rightChild, value);
        temp->rightChild = rchild;
        rchild->parent = temp;
    }
    else {
        BST::Node* lchild = inserth(temp->leftChild, value);
        temp->leftChild = lchild;
        lchild->parent = temp;
    }
    return temp;
}
/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    if(root == nullptr) {
        Node* n = new Node(element);
        root = n;
        numElements++;
        return true;
    }
    if(element == root->data) {
        return false;
    }
    Node* result = inserth(root, element);
    if(result != nullptr) {
        numElements++;
        return true;
    }
    else {
        return false;
    }

}


bool findh(BST::Node* temp, int value) {
    if(temp == nullptr) {
        return false;
    }
    if(value == temp->data) {
        return true;
    }

    if(value > temp->data) {
        return findh(temp->rightChild, value);
    }
    else if(value < temp->data){
        return findh(temp->leftChild, value);
    }
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    Node* temp = root;
    return findh(temp, query);
   /* if(query == root->data) {
        return true;
    }

    if(query > root->data) {
        return findh(root->rightChild, query);
    }
    else {
        return findh(root->leftChild, query);
    }*/
    
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    if(root == nullptr) {
        return root;
    }
    Node* temp = root;
    while(temp->leftChild != nullptr) {
        temp = temp->leftChild;
    }
    return temp;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    Node* temp = this;
    Node* node = this;
    if(temp->rightChild != nullptr) {
        temp = temp->rightChild;
        while(temp->leftChild != nullptr) {
            temp = temp->leftChild;
        }
        return temp;
    }
    while(temp->parent != nullptr) {
        temp = temp->parent;
        if(temp->leftChild != nullptr && temp->leftChild == node) {
            return temp;
        }
        node = node->parent;
    }
    return nullptr;
    
}

    


