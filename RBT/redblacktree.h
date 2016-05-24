#ifndef _REDBLACKTREE_
#define _REDBLACKTREE_
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <class T>
class Node
{
public:
    
    Node():data(), left(NULL), right(NULL), parent(NULL), is_black(false) {;}; //defualt constructor
    
    Node(T par):data(par), left(NULL), right(NULL), parent(NULL), is_black(false) {;}; //constructor with T type parameter
    
    // Node data
    T data;
    Node<T>* left; // node-left-child
    Node<T>* right; // node-right-child
    Node<T>* parent; // node-parent
    bool is_black; // the colour of the node, either black or red but represented as a bool
};


template <class T>
class RedBlackTree
{
public:
    
    RedBlackTree(); // Default Constructor
    RedBlackTree(const RedBlackTree& rbt); // Copy Constructor
    ~RedBlackTree(); // Destructor
    RedBlackTree & operator = (const RedBlackTree & rbt); // Assignment operator
    
    bool Insert(T item); // Insert Function
    bool Remove(T target); // Remove Function calls helper function to do the remove
    bool Search(T item)const; // Search Function
    T* Between(T min, T max, int& size)const; // Between Function
    void RemoveAll(); // Remove all Node from the tree
    T* Dump(int& size)const; // Return all the node from the tree
    int Size()const; // Return the size of the tree
    int Height()const; // Return the length of the longest path from the root to a leaf
    Node<T>* GetRoot()const; // Returns a pointer to the tree’s root node
    
private:
    Node<T>* root; // root of the tree
    int rbt_size; // size of the tree
    
    void RemoveAll_Helper(Node<T>* nd); // RemoveAll Helper Function
    void bstInsert(Node<T>* newNode); // Insert Helper Function
    void Left_Rotate(Node<T>* newNode); // Left Rotate for Insert Function
    void Right_Rotate(Node<T>* newNode); // Right Rotate for Insert Function
    Node<T>* SearchForNode(T target) const; // Finds a value and returns a node
    void Remove_CleanUp(Node<T>* target); // Remove Function Helper
    void rbtDeleteFixUp(Node<T>* child, Node<T>* parent); // Delete Helper Function, fix the tree after deletion
    Node<T>* Predecessor(Node<T>* target); // Find the predecessor and return node pointer
    void InOrder_Dump(T arr[],int& size, Node<T>* nd)const; // Dump Helper Function
    void InOrder_Between(T arr[], int& size, Node<T>* nd, T min, T max)const; // Between Helper Function
    int Height_Helper(Node<T>* nd)const; // Height Helper Function
    Node<T>* deepCopy(Node<T>* source);
    // For copy constructor and overloaded =
    
};

#include "redblacktree.cpp"
#endif
