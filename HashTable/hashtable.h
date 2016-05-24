#include <string>
#include <iostream>
#include "bst.h"
using namespace std;

class HashTable
{
private:
    // Attributes
    BST* arr;     // to refer to an array of binary search tree objects
    int arrSize;  // to record the size of the underlying array
    int curSize;  // to record the current number of items stored in the hash table
    
    // Helper Hunction
    bool findPrime(int); // find the prime number that biger than 2*arrSize
    int hash(string str) const; // find the correct array indices for str
    void deepCopy(const HashTable & hashtable); // helper function for Copy Consturctor and Assignment operator =
    void removeAllHash(); // helper function for destructor

public:
    // Constructors
    HashTable(); // Default Constructor
    HashTable(int n); // Constructor with
    ~HashTable(); // Destructor
    
    HashTable(const HashTable& hashtable); // Copy Constructor
    HashTable & operator = (const HashTable & hashtable); // Assignment operator =

    
    bool Insert(string str); // Insert a string into the hash-table
    bool Remove(string str); // Remove a string from the hash-table
    bool Search(string str) const; // Search a string in the hash-table
    int Size() const; // returns the number of items stored in the hash table
    int MaxSize() const; //returns the size of the hash table's underlying array
    double loadFactor(); // returns the load factor of the hash table
    
};

