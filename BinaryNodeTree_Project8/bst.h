//
// Created by Deeptanshu Das on 11/27/18.
//

//Link-based implementation of the ADT binary search tree.
//@file BinarySearchTree.h */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
//#include "NotFoundException.h"
//include "PrecondViolatedExcept.h"
#include <memory>
template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
    size_t nodes;
    BinaryNode<ItemType>* rootPtr;
protected:
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Places a given new node at its proper position in this binary
// search tree.
   // BinaryNode<ItemType>*  placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
// Removes the given target value from the tree while maintaining a
// binary search tree.

    BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

    void removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
// Removes a given node from a tree while maintaining a binary search tree.
  //  auto removeNode(BinaryNode<ItemType>* nodePtr);
// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
   // auto removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
// Returns a pointer to the node containing the given value,
// or nullptr if not found.
    void findNode(BinaryNode<ItemType>* treePtr, const ItemType& target,bool& success) const;
    int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();
//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
    bool isEmpty();
    int getHeight() const;
    int getNumberOfNodes() const;
   ItemType getRootData();
    bool setRootData(const ItemType& newData);

    bool insert(ItemType const& value);
    void clear();
//    ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
    void inorder(BinaryNode<ItemType>*);
    void traverseInorder();

    void preorder(BinaryNode<ItemType>*);
    void traversePreorder();

    void postorder(BinaryNode<ItemType>*);
    void traversePostorder();


//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
   //BinarySearchTree<ItemType>&operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree



template<class ItemType>
 void  BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,const ItemType target,bool& isSuccessful)
{
    BinaryNode<ItemType>* tempPtr;
if (subTreePtr == nullptr)
{
isSuccessful = false;
}
else if (subTreePtr->getItem() == target)
{
// Item is in the root of some subtree
subTreePtr = removeNode(subTreePtr); // Remove the item
isSuccessful = true;
}
else if (subTreePtr->getItem() > target)
{
// Search the left subtree
tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
subTreePtr->setLeftChildPtr(tempPtr);
}
else
{
// Search the right subtree
tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
subTreePtr->setRightChildPtr(tempPtr);
}
return subTreePtr;
}

/*
template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodeptr)
{
    BinaryNode<ItemType>* N;
    BinaryNode<ItemType>* nodetoConnectPtr;
    if(N->isLeaf())
    {
        N == nullptr;
    }

    else if(getLeftChildPtr()==NULL)
    {
        nodetoConnectPtr = nodeptr->getRightChildPtr();

    }

}
 */


template<class ItemType>

void BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const {

    if (treePtr == nullptr) // not found here

        return treePtr;

    if (treePtr->getItem() == target) // found it

    {

        success = true;

        return treePtr;

    } else {

        BinaryNode<ItemType> *targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);

        if (!success) // no need to search right subTree

        {

            targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);

        } // end if



        return targetNodePtr;

    } // end if
}



//constructors

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
    nodes = 0;
    rootPtr = nullptr;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
    rootPtr = CopyTree(tree.rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    this->destroyTree(rootPtr);
}  // end destructor



template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr)
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


//public methods

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::insert(ItemType const& newData)
{

        auto* newNodePtr = new BinaryNode<ItemType>(newData);
        rootPtr = balancedAdd(rootPtr, newNodePtr);
        return true;
    }  // end add


template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData()
{
    assert (!isEmpty());
    return rootPtr->getItem();
} // end getRootData


template<class ItemType>
bool BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
    if (isEmpty()) {
        rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
    }
    else {
        rootPtr->setItem(newData);
    }
} // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty()
{
    return rootPtr == nullptr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> *subTreePtr) const
{
    if (subTreePtr ==nullptr)
        return 0;
    return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()) , getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{

}




//traversal implementations

template<class ItemType>
void BinarySearchTree<ItemType>::inorder(BinaryNode<ItemType>* node) {
    if(node != nullptr) {

        if(node->getLeftChildPtr()) {
            inorder(node->getLeftChildPtr());
        }
        cout << " " << node->getItem() << " ";

        if(node->getRightChildPtr()) {
            inorder(node->getRightChildPtr());
        }

    }
}



template<class ItemType>
void BinarySearchTree<ItemType>::traverseInorder()
{
    inorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorder(BinaryNode<ItemType>* node) {
    if(node != nullptr) {
        cout << " " << node->getItem() << " ";

        if(node->getLeftChildPtr()) preorder(node->getLeftChildPtr());

        if(node->getRightChildPtr()) preorder(node->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::traversePreorder()
{
    preorder(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorder(BinaryNode<ItemType>* node) {
    if(node != nullptr) {

        if(node->getLeftChildPtr()) postorder(node->getLeftChildPtr());

        if(node->getRightChildPtr()) postorder(node->getRightChildPtr());
        cout << " " << node->getItem() << " ";
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::traversePostorder()
{
    postorder(rootPtr);
}

#endif
