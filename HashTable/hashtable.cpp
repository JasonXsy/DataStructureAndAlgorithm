#include "hashtable.h"

// Default Constructor
// PURPOSE: creates a hash table of default size: 101
// PARAM:
// PRE:
// POST: a empty hash table with size 101
HashTable::HashTable()
{
    arrSize = 101;
    arr = new BST[arrSize];
    curSize = 0;
}

// Constructor
// PURPOSE: creates a hash table to store n items where the value of n is given by the constructor's
//          single integer parameter; the size of the underlying array should be set to the smallest
//          prime number larger than 2n
// PARAM: number of item will be inserted into the hash table
// PRE: n must be larger than 1, and calling funciton - findPrime()
// POST: a hash table with smallest prime number size that larger than 2n
HashTable::HashTable(int n)
{
    arrSize = 2 * n;
    while(findPrime(arrSize) == false)
    {
        arrSize++;
    }
    arr = new BST[arrSize];
    curSize = 0;
}

// Find Prime
// PURPOSE: find the smallest prime number that larger than 2n
// PARAM: n the number of item will be inserted into the hash table
// PRE: n must be larger than 1
// POST: return a bool value, true or false
bool HashTable::findPrime(int n)
{
    int isPrime = 0;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            isPrime++;
        }
    }
    if(isPrime == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//// Constructor with string
//HashTable::HashTable(int n)
//{
//    n = findPrime(n);
//    arrSize = n;
//    arr = new BST[arrSize];
//    curSize = 0;
//}
//
//// Find Prime Number
//int HashTable::findPrime(int n)
//{
//    bool isPrime = false;
//    int temp = n * 2;
//    
//    while(!isPrime)
//    {
//        if(temp%2!=0 && temp%3!=0 && temp%5!=0 && temp%7!=0)
//        {
//            isPrime = true;
//        }
//        else
//        {
//            isPrime = false;
//            temp++;
//        }
//    }
//    return temp;
//}

// Destructor
// PURPOSE: de-allocates any dynamic memory associated with the object
// PARAM:
// PRE: calling helper function - removeAllHash()
// POST: a empty hash table
HashTable::~HashTable()
{
    removeAllHash();
}

// Hash(string)
// PURPOSE: hashes a string into integer
// PARAM: the input string
// PRE:
// POST: returns the index position of param
int HashTable::hash(string str) const
{
    int hash = str[0] - 96;
    for (int i = 1; i < str.length(); i++)
    {
        hash = ((hash * 32) + (str[i] - 96)) % arrSize;
    }
    if(str.length() == 1)
    {
        hash = (hash * 32) % arrSize;
    }
    return hash;
}

// Copy Constructor
// PURPOSE: creates a deep copy of its HashTable reference parameter
// PARAM: the hash table to be copied
// PRE: calling helper funciotn - deepCopy()
// POST: a copied hash table
HashTable::HashTable(const HashTable& hashtable)
{
    deepCopy(hashtable);
}

// the Helper function of Copy Constructor and Assignment Operator =
// PURPOSE: creates a deep copy of its HashTable reference parameter
// PARAM: the hash table to be copied
// PRE:
// POST: a copied hash table
void HashTable::deepCopy(const HashTable& hashtable)
{
    arr = new BST[hashtable.arrSize];
    arrSize = hashtable.arrSize;
    curSize = hashtable.curSize;
    for(int i = 0; i < arrSize; i++)
    {
        arr[i] = hashtable.arr[i];
    }
}

// Assignment operator =
// PURPOSE: deep copies its HashTable reference parameter into the calling object and returns a reference to
//          the calling object after de-allocating any dynamic memory associated with the original contents
//          of the calling object; if the calling objects is the same as the parameter, the operator should
//          not copy it
// PARAM: the hash table to be copied
// PRE: calling helper function - deepCopy()
// POST: returns a copied hash table; otherwise return *this
HashTable & HashTable::operator=(const HashTable & hashtable)
{
    if(this != & hashtable)
    {
        removeAllHash();
        deepCopy(hashtable);
    }
    return * this;
}

// removeAllHash
// PURPOSE: remove all items in the hash table
// PARAM:
// PRE: calling BST destructor
// POST: a empty hash table
void HashTable::removeAllHash()
{
    for(int i = 0; i < arrSize; i++)
    {
        arr[i].~BST(); // calling BST destructor
    }
}

// Insert
// PURPOSE: insert its single string parameter into the hash table unless the string is already contained in
//          the table; returns true if the insertion is successful, returns false otherwise
// PARAM: the string to be inserted
// PRE: calling BST insert function
// POST: inserted and returns true; otherwise returns false
bool HashTable::Insert(string str)
{
    int hashIndex = hash(str);
    if(arr[hashIndex].Insert(str))
    { // using BST insert function
        curSize++;
        return true;
    }
    else
    {
        return false;
    }

}

// Remove
// PURPOSE: removes its single string parameter from the hash table; returns true if the parameter value was
//          found and removed, returns false if the parameter value was not found in the hash table
// PARAM: the string to be removed
// PRE: calling BST remove function
// POST: removed and returns true; otherwise returns false
bool HashTable::Remove(string str)
{
    int hashIndex = hash(str);
    if(arr[hashIndex].Remove(str))
    {// using BST remove function
        curSize--;
        return true;
    }
    else
    {
        return false;
    }
}

// Search
// PURPOSE: returns true if its single string parameter is contained in the hash table, returns false otherwise
// PARAM: the string to be searched
// PRE: calling BST search function
// POST: finds it and returns true; otherwise returns false
bool HashTable::Search(string str) const
{
    int hashIndex = hash(str);
    if(arr[hashIndex].Search(str))
    { // using BST search function
        return true;
    }
    else
    {
        return false;
    }
}

// Size
// PURPOSE: returns the number of items stored in the hash table
// PARAM:
// PRE:
// POST: the number of items stored in the hash table
int HashTable::Size() const
{
    return curSize;
}

// MaxSize
// PURPOSE: returns the size of the hash table's underlying array
// PARAM:
// PRE:
// POST: the underlying array size
int HashTable::MaxSize() const
{
    return arrSize;
}

// LoadFactor
// PURPOSE: returns the load factor of the hash table as a double type. Note that with separate chaining,
//          the load factor can be greater than 1
// PARAM:
// PRE:
// POST: the load factor of the hash table
double HashTable::loadFactor()
{ // the size of the underlying array / current number of items stored in the hash table
    return static_cast<double>(curSize) / static_cast<double>(arrSize);
}

