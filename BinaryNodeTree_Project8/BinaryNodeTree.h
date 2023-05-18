//
// Created by Deeptanshu Das on 11/27/18.
//

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_
#include <iostream>
#include <cassert>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include <algorithm>

using namespace std;
//#include "PrecondViolatedExcept.h"
//#include "NotFoundException.h"
template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
    BinaryNode<ItemType>* rootPtr;
protected:
// PROTECTED UTILITY METHODS SECTION: RECURSIVE HELPER METHODS FOR THE PUBLIC METHODS
    int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
    int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
// Recursively adds a new node to the tree in a left/right fashion to keep tree balanced
    BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
    // Removes the target value from the tree
   // virtual  BinaryNode<ItemType>*removeValue(BinaryNode<ItemType>* subTreePtr,
     //                        const ItemType target, bool& isSuccessful);
// Copies values up the tree to overwrite value in current node until a leaf is reached.
// the leaf is then removed, since its value is stored in the parent.
   // auto moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
// Recursively searches for target value.
    virtual BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, ItemType target) const;
// Copies the tree rooted at treePtr and returns a pointer to the root of the copy
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
// Recursively deletes all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* subTreePtr);
    // Recursive traversal helper methods
    void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
public:
// CONSTRUCTOR AND DESTRUCTOR SECTION
    BinaryNodeTree();
    BinaryNodeTree(const ItemType& rootItem);
    BinaryNodeTree(const ItemType& rootItem,
                   const BinaryNodeTree<ItemType>* leftTreePtr,
                   const BinaryNodeTree<ItemType>* rightTreePtr);

    BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr);
    virtual ~BinaryNodeTree();
    // PUBLIC BINARY_TREE_INTERFACE METHODS SECTION
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const ;
    bool setRootData(const ItemType& newItem);
    bool add(const ItemType& newData); // Adds an item to the tree
    bool remove(const ItemType& data); // Removes specified item from the tree
    void clear();
    //ItemType getEntry(const ItemType& anEntry);
    bool contains(const ItemType& anEntry) const;
    // PUBLIC TRAVERSAL SECTION
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
// OVERLOADED OPERATOR SECTION
   // BinaryNodeTree& operator = (const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree
//#include “BinaryNodeTree.cpp”

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
    int h;
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr()));

} // end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
               + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
} //end getNumberOfNodesHelper

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr)
{
    {
        if (subTreePtr == nullptr)
            return newNodePtr;
        else
        {
            BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
            BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

            if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
            {
                rightPtr = balancedAdd(rightPtr , newNodePtr);
                subTreePtr->setRightChildPtr(rightPtr );
            }
            else
            {
                leftPtr = balancedAdd(leftPtr, newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
            }  // end if

            return subTreePtr;
        }  // end if
    }  // end balancedAdd
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
    BinaryNode<ItemType>* newTreePtr = nullptr;

    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr)
    {
        // Copy node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }  // end if

    return newTreePtr;
}  // end copyTree


template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }  // end if
}  // end destroyTree

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType> :: findNode(BinaryNode<ItemType>* subTreePtr, ItemType target) const
{
    if (subTreePtr == nullptr)
        return nullptr;                                           // Not found
    else if (subTreePtr->getItem() == target)
        return subTreePtr;                                  // Found
    else if (subTreePtr->getItem() > target)
        // Search left subtree
        return findNode(subTreePtr->getLeftChildPtr(), target);
}


//recursive traversal helper methods

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    }  // end if
}  // end inorder

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    } // end if
} // end preorder

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    } // end if
} // end postorder


//constructor and destructor sections

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{
    rootPtr = nullptr;
}  // end default constructor


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
                                       copyTree(rightTreePtr->rootPtr));
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
    rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    destroyTree(rootPtr);
}  // end destructor


//public interface section

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
    auto* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}  // end add

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(rootPtr);
} // end getNumberOfNodes

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
    assert (!isEmpty());
    return rootPtr->getItem();
} // end getRootData

template<class ItemType>
bool BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem)
{
    if (isEmpty()) {
        rootPtr = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
    }
    else {
        rootPtr->setItem(newItem);
    }
} // end setRootData

template<class ItemType>
bool BinaryNodeTree<ItemType> ::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class ItemType>
int BinaryNodeTree<ItemType> ::getHeight() const
{
    return getHeightHelper(rootPtr);
}

template<class ItemType>
bool BinaryNodeTree<ItemType> ::remove(const ItemType& data)
{
//	BinaryNode<ItemType>* nodePtr = nullptr;
    bool success = false;
//	nodePtr = findNode(rootPtr, data, success);
    return success;
}

/*
template<class ItemType>
 ItemType BinaryNodeTree<ItemType> ::getEntry(const ItemType& anEntry)
{
    BinaryNode<ItemType>* nodePtr = nullptr;
    bool success = false;
    //nodePtr = findNode(rootPtr, anEntry, success);
    nodePtr = findNode(rootPtr, anEntry);
    return nodePtr->getItem();
}
 */

template<class ItemType>
void BinaryNodeTree<ItemType> ::clear()
{

}

template<class ItemType>
bool BinaryNodeTree<ItemType> ::contains(const ItemType& anEntry) const
{
    BinaryNode<ItemType>* nodePtr = nullptr;
    bool success = false;
    //nodePtr = findNode(rootPtr, anEntry, success);
    nodePtr = findNode(rootPtr, anEntry);
    return success;
}

//public traversal method

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    inorder(visit, rootPtr);
}  // end inorderTraverse


template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    preorder(visit, rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    postorder(visit, rootPtr);
}  // end inorderTraverse

#endif