#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class BST
{
public:
    BST(); // Default Constructor
    BST(const BST& bst); // Copy Constructor
    ~BST(); // De-allocates dynamic memory associated with tree
    
    bool Insert(string value); // Insert Function
    bool Remove(string value); // Remove Function
    bool Search(string target) const; // Searches tree for target
    BST & operator = (const BST & bst); // Assignment operator =
    
    vector<string> PreOrder() const; // returns a vector containing the contents of the BST
    
    
private:
    // Node class
    class Node
    {
    public:
        string data; // Node data with type string
        Node* left;  // A node pointer to left child
        Node* right; // A node pointer to right child
        
        Node():data(),left(NULL),right(NULL){}; // Node default constructor
        Node(string value):data(value), left(NULL), right(NULL) {}; // Node constructor with string value
    };
    
    Node* root; // A node pointer to the root of the tree
    
    void removeHelper(Node* target, Node* previous, bool isLeft); // doing the remove process for Remove function
    Node* predecessor(Node* nd); // Find the predecessor for the node to be deleted
    
    void deepCopy(Node* source); // Helper function for copy constructor and operator =
    void RemoveAll(Node* nd); // Helper function for destructor to remove all node in the tree
    
    void PreOrder_Helper(vector<string>& vec,Node* nd) const; // Helper function for PreOrder
};

