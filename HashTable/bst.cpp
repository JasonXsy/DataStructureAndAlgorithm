#include "bst.h"

// Default Constructor
// PURPOSE: creates an empty BST whose root is NULL
// PARAM:
// PRE:
// POST: an empty BST
BST::BST()
{
    root = NULL;
}

// Copy Constructor
// PURPOSE: creates a deep copy of its BST reference parameter
// PARAM: the object to be copied
// PRE: calling helper function - deepCopy()
// POST: a copied BST
BST::BST(const BST&bst)
{
    root = NULL;
    deepCopy(bst.root);
}

// DeepCopy and overloaded = Helper Function
// PURPOSE: this function is the helper method for both Copy Constructor,
//          and Overloaded Assignment Operator =
// PARAM: the object to be copied
// PRE: must be non-empty
// POST: creates a deep copy of the imput object
void BST::deepCopy(Node* source)
{
    if(source != NULL)
    {
        Insert(source->data);
        deepCopy(source->left);
        deepCopy(source->right);
    }
}

// Overloaded Assignment Operator =
// PURPOSE: deep copies its BST reference parameter into the calling object and returns
//          a reference to the calling object after de-allocating any dynamic memory
//          associated with the original contents of the calling objects; if the calling
//          object is the same as the parameter, the operator should not copy it
// PARAM: the object to be deep copied
// PRE: calling Helper Function - RemoveAll(), deepCopy()
// POST: a new deep copied BST
BST & BST::operator = (const BST& bst)
{
    if(this!= & bst)
    {
        RemoveAll(root);
        deepCopy(bst.root);
    }
    return *this;
}

// Destructor
// PURPOSE: deletes dynamic memory allocated by the BST
// PARAM:
// PRE: calling Helper Funtion - RemoveAll()
// POST: a empty BST
BST::~BST()
{
    RemoveAll(root);
    root = NULL;
}

// Destructor Helper Function
// PURPOSE: empties the BST, de-allocating dynamic memory allocated by the BST
// PARAM: the node to be deleted
// PRE: recursively calling it-self
// POST: an empty BST
void BST::RemoveAll(Node *nd)
{
    if(nd != NULL)
    {
        if(nd->left != NULL)
        {
            RemoveAll(nd->left);
        }
        if(nd->right != NULL)
        {
            RemoveAll(nd->right);
        }
        delete nd;
    }
}

// Search
// PURPOSE: searches the tree for the method's single parameter and returns TRUE if it is found
//          and FALSE otherwise
// PARAM: the item to be searched
// PRE:
// POST: a bool value, true or false
bool BST::Search(string value) const
{
    Node* nd = root;
    while(nd != NULL)
    {
        if(value < nd->data)
        {
            nd = nd->left;
        }
        else if(value > nd->data)
        {
            nd = nd->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Insert
// PURPOSE: if the tree does not contain the method's single parameter, inserts the parameter
//          and returns true; otherwise does not insert the parameter and return false
// PARAM: the item to be inserted
// PRE:
// POST: inserted the item and return true; otherwise return false
bool BST::Insert(string value)
{
    if(Search(value))
    {
        return false;
    }
    else
    {
        Node* newNode = new Node(value); // Create a new node
        if(root == NULL) // Tree is empty
        {
            root = newNode;
        }
        else // Tree not empty
        {
            Node* previous = root;
            bool inserted = false;
            // Find correct position and insert node
            while(!inserted)
            {
                if(value < previous->data) // Go left
                {
                    if(previous->left == NULL)
                    {
                        previous->left = newNode;
                        inserted = true;
                    }
                    else
                    {
                        previous = previous->left;
                    }
                }
                else // Go right
                {
                    if(previous->right == NULL)
                    {
                        previous->right = newNode;
                        inserted = true;
                    }
                    else
                    {
                        previous = previous->right;
                    }
                }
            }
        }
        return true;
    }
}

// Remove
// PURPOSE: removes the method's single parameter from the BST and return true;
//          if the tree does not contain the parameter, returns false
// PARAM: value is the data to be removed
// PRE: calling helper funciton - removeHelper()
// POST: the node removed from the BST and return true; otherwise return false
bool BST::Remove(string value)
{
    if(!Search(value))
    {
        return false;
    }
    else
    {
        Node* previous = root;
        bool found = false;
        bool isLeftChild = false;
        
        // Root contains value
        if(root->data == value)
        {
            removeHelper(root,NULL,false);
            return true;
        }
        
        // Find correct position of node to remove
        while(!found && previous != NULL)
        {
            if(value < previous->data)
            {// Go left
                if(value == previous->left->data)
                {
                    found = true;
                    isLeftChild = true;
                }
                else
                {
                    previous = previous->left;
                }
            }
            else
            {// Go right
                if(value > previous->data)
                {
                    found = true;
                    isLeftChild = false;
                }
                else
                {
                    previous = previous->right;
                }
            }
        }
        
        if(found)
        {
            if(isLeftChild)
            {
                removeHelper(previous->left,previous,isLeftChild);
            }
            else
            {
                removeHelper(previous->right,previous,isLeftChild);
            }
        }
        return true;
    }
}

// Remove Helper
// PURPOSE: the remove helper function, if a node to be removed has two children, its data should be
//          replaced by its predecessor's data and predecessor node should be removed from the tree
// PARAM: target is the value to be removed
// PRE: calling helper function - predecessor()
// POST: the node removed from the BST and return true; otherwise return false
void BST::removeHelper(Node* target, Node* previous, bool isLeft)
{
    Node* replacement; // Target's child
    // Case where target has 0 or 1 children
    if(target->left == NULL || target->right == NULL)
    {
        if(target->left != NULL)
        {
            replacement = target->left;
        }
        else
        {
            replacement = target->right; // may be NULL if target has no children
        }
        // Deal with case where target is root
        if(previous == NULL)
        {
            root = replacement;
        }
        else if(isLeft)
        {
            previous->left = replacement;
        }
        else
        {
            previous->right = replacement;
        }
        delete target;
    }
    else // Case where target has two children
    {
        Node* pre = predecessor(target);
        // Replace target with predecessor
        // Note that predecessor's child has been dealt with
        if(target->left != pre)
        {
            pre->left = target->left;
        }
        pre->right = target->right;
        
        // Target is root
        if(previous == NULL)
        {
            root = pre;
        }
        else if(isLeft)
        {
            previous->left = pre;
        }
        else
        {
            previous->right = pre;
        }
        delete target;
    }
}

// Predecessor
// PURPOSE: finds and returns the predecessor node and attaches the predecessor's child to
//          predecessor's parent if parent is not the parameter
// PARAM: nd is node whose predecessor is to be returned
// PRE:
// POST: return the predecessor
BST::Node* BST::predecessor(Node* nd)
{
    // The predecessor is RIGHT most node of LEFT subtree
    Node* pre = nd->left;
    Node* pre_previous = nd->left;
    
    // Find predecessor - the RIGHT most node of the LEFT subtree
    while(pre->right != NULL)
    {
        pre_previous = pre;
        pre = pre->right;
    }
    // Replace the predecessor with its left child
    if(pre != pre_previous)
    {
        pre_previous->right = pre->left;
    }
    return pre;
}

// PreOrder
// PURPOSE: returns a vector containing the contents of the BST, ordered using a pre-order traversal
// PARAM:
// PRE: calling helper function - PreOrder_Helper()
// POST: return the vector that containging the string value
vector<string> BST::PreOrder() const
{
    vector<string> vec;
    PreOrder_Helper(vec, root);
    return vec;
}


// PreOrder Helper
// PURPOSE: using pre-order traversal to insert node's data to the calling object
// PARAM: a new vector called vec, a node in the BST (should be root of the BST)
// PRE: non-empty
// POST: returns all node's data to the vec in pre-order
void BST::PreOrder_Helper(vector<string>& vec,Node* nd) const
{
    if(nd != NULL) {
        vec.push_back(nd->data);
        PreOrder_Helper(vec,nd->left);
        PreOrder_Helper(vec,nd->right);
    }
}









