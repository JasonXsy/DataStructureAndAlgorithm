#ifdef LINKEDLIST_H_

#include "linkedlist.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


// Default Constructor
// PURPOSE: creates an empty LinkedList
// PARAM:
// PRE:
// POST: an empty LinkedList
template <class T>
LinkedList<T>::LinkedList()
{
	front = NULL;
	back = NULL;
	num_of_elements = 0;
}

// Copy constructor
// PURPOSE: creates a deep copy of the input list ll
// PARAM: the list to be copied
// PRE: calling helper method - DeepCopy()
// POST: a copied linkedList
template <class T>
LinkedList<T>::LinkedList(const LinkedList& ll)
{
	DeepCopy(ll);
}

// Destructor
// PURPOSE: deallocates all memory used by the linkedList
// PARAM:
// PRE: calling helper method - deleteList()
// POST: an empty LinkedList
template <class T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}

// Overloaded Assignment Operator =
// PURPOSE: performs a deep copy of its constant LinkedList reference parameter and
//          returns a reference to the calling object after deallocating any memory
//          associated with the original contents of the calling object; if the calling
//          object is the same as the parameter, the operator should not copy it.
// PARAM: the object to be deep copied
// PRE: calling helper methods - deleteList(), DeepCopy()
// POST: a new deep copied LinkedList
template <class T>
const LinkedList<T> & LinkedList<T>:: operator = (const LinkedList<T>& ll)
{
	if(this != & ll)
	{
		deleteList();
		DeepCopy(ll);
	}
	return *this;
}

// Size
// PURPOSE: returns the number of items in the list
// PARAM:
// PRE:
// POST: the number of items in the list
template <class T>
int LinkedList<T>::Size() const
{
	return num_of_elements;
}

// IsEmpty
// PURPOSE: returns TRUE if the list is empty, FALSE otherwise
// PARAM:
// PRE:
// POST: returns a bool value, true or false
template <class T>
bool LinkedList<T>::IsEmpty() const
{
	if(front == NULL)
	{
		return true; // is empty
	}
	else
		return false; // not empty
}

// Contains
// PURPOSE: returns whether a specified item exists in the list, where T is a template type.
//          Note that in general, a linked list places no restrictions on insertion of
//          duplicate entries.
// PARAM: the item to be find in the list
// PRE:
// POST: returns a bool value, true or false
template <class T>
bool LinkedList<T>::Contains(T item) const
{
	Node<T>* temp = new Node<T>;
	temp->data = item;
	int pos = 0;
	Node<T>* nextNode = new Node<T>;
	nextNode = front;
	while(pos < num_of_elements)
	{
		if(temp == nextNode)
		{
			return true;
		}
		nextNode = nextNode->next;
		pos++;
	}
	return false;
}

// ElementAt
// PURPOSE: returns the data value of the list element at index p. For this implementation
//          we will treat the list as being 0-indexed similarly to arrays.
// PARAM: the index to be find in the list
// PRE: must 0 <= p < num_of_elements
// POST: returns the data value of the list element at index p
template <class T>
T LinkedList<T>::ElementAt(int p) const
{
	int index = p;
	Node<T>* current = new Node<T>;

	if(index <= num_of_elements / 2)
	{
		int pos = 0;
		current = front;
		while(pos != index )
		{
			current = current->next;
			pos++;
		}
		return current->data;
	}
	else //(index > num_of_elements / 2)
	{
		int endpos = num_of_elements-1;
		current = back;
		while(endpos != index)
		{
			current = current->prev;
			endpos--;
		}
		return current->data;
	}
}

// InsertAt
// PURPOSE: inserts an item into the list at index p (0-indexed). This function should throw a
//          runtime_error for an invalid index. You should implement special cases for this function
//          such that insertion at the front or back of the list can occur in constant time.
// PARAM: the item of T type to be inserted at index p
// PRE: if p < 0 or p > num_of_elements, function will throw a runtime_error
// POST: the item inserted at index p, otherwise throw a runtime_error for an invalid index
template <class T>
void LinkedList<T>::InsertAt(T item, int p)
{
	if(p < 0 || p > num_of_elements)
	{
		throw runtime_error("The list is EMPTY or the index is INVALID");
	}
	else //(p >= 0 && p <= num_of_elements)
	{
		int index = p;
		int position = 0;
		Node<T>* current = new Node<T>;
		Node<T>* temp = new Node<T>;
		temp->data = item;

		if (num_of_elements == 0)
		{
			front = temp;
			back = temp;
			temp->next = NULL;
			temp->prev = NULL;
			num_of_elements++;
			return;
		}
		else if (index == 0)
		{
			temp->prev = NULL;
			temp->next = front;
			front->prev = temp;
			front = temp;
			num_of_elements++;
			return;
		}
		else if (index == num_of_elements)
		{
			temp->next = NULL;
			temp->prev = back;
			back->next = temp;
			back = temp;
			num_of_elements++;
			return;
		}
		else if (index <= num_of_elements/2)
		{
			current = front;
			while(position != index)
			{
				current = current->next;
				position++;
			}
		}
		else if (index > num_of_elements/2)
		{
			int endPosition = num_of_elements - 1;
			current = back;
			while(endPosition != index)
			{
				current = current->prev;
				endPosition--;
			}
		}
		temp->next = current;
		current->prev->next = temp;
		temp->prev = current->prev;
		current->prev = temp;
		num_of_elements++;
	}
}

// RemoveAt
// PURPOSE: removes and returns the item at index p (0-indexed). This function should throw a
//          runtime_error if the list empty or if the index is invalid. You should implement
//          special cases to perform removal from the front or back of the list in constant time.
// PARAM: the index of the item to be removed.
// PRE: if p< 0 or p >= num_of_elements, function will throw a runtime_error
// POST: the item removed and returned, otherwise throw a runtime_error
template <class T>
T LinkedList<T>::RemoveAt(int p)
{
	if(p < 0 || p >= num_of_elements || num_of_elements <= 0)
	{
		throw runtime_error("The list is EMPTY or the index is INVALID");
	}
	else // (p >= 0 && p < unm_of_elements && num_of_elements >0)
	{
		int index = p;
		Node<T>* temp = new Node<T>;
		Node<T>* current = new Node<T>;
		Node<T>* nextNode = new Node<T>;
		Node<T>* prevNode = new Node<T>;

		if (index == 0)
		{
			temp = front;// *front
			nextNode = front->next;
			string value = temp->data;
			delete temp;
			front = nextNode;
			num_of_elements--;
			return value;
		}
		else if (index == num_of_elements-1)
		{
			// Node & temp = back->data; // *back
			temp = back;
			prevNode = back->prev;
			string value = temp->data;
			delete temp;
			back = prevNode;
			num_of_elements--;
			return value;
		}
		else if (index <= num_of_elements/2)
		{
			current = front;
			int position = 0;
			while(position != index)
			{
				current = current->next;
				position++;
			}
		}
		else if (index > num_of_elements/2)
		{
			current = back;
			int endPosition = num_of_elements-1;
			while(endPosition != index)
			{
				current = current->prev;
				endPosition--;
			}
		}
		nextNode = current->next;
		prevNode = current->prev;
		string value = current->data;
		delete current;
		nextNode->prev = prevNode;
		prevNode->next = nextNode;
		num_of_elements--;
		return value;
	}
}

// Helper Method for Copy constructor
// PURPOSE: this function is the helper method for both Copy Constructor, and
//          Overloaded Assignment Operator =
// PARAM: the object to be copied
// PRE: must be non-empty
// POST: creates a deep copy of the imput list ll
template <class T>
void LinkedList<T>::DeepCopy(const LinkedList<T>& ll)
{
	front = NULL;
	back = NULL;
	num_of_elements = 0;

	// Only copy if ll is non-empty
	if(ll.front != NULL)
	{
		Node<T>* original = ll.front;
		Node<T>* copy;
		Node<T>* oldCopy;
		// Copy the front
		copy = new Node<T>(original->data); // (*original).data
		oldCopy = copy;
		front = copy;
		original = original->next;
		// Traverse the original copying each node
		while(original != NULL)
		{
			copy->next = new Node<T>(original->data); // (*original).data
			copy = oldCopy->next;
			copy->prev = oldCopy;
			oldCopy = copy;
			original = original->next;
		}
		back = copy;
		num_of_elements = ll.num_of_elements;
	}
}

// Helper Method for Destructor
// PURPOSE: this function is the helper method for the Destructor, it will delete all the
//          elements in the LinkedList object
// PARAM:
// PRE: must be non-empty
// POST: an empty list
template <class T>
void LinkedList<T>::deleteList()
{
	if(front)
	{
		Node<T>* temp = front;

		// Traverse list
		while (temp != NULL)
		{
			temp = front->next;
			delete front;
			front = temp;
		}
		front = NULL;
		back = NULL;
		num_of_elements = 0;
	}
}

// Print
// PURPOSE: prints the contents of the playlist to console using standard output, with one
//          song on each line of output preceded by a 1-indexed number.
// PARAM:
// PRE: must non-empty
// POST: prints the contents of the playlist with one song on each line of output preceded by
//       a 1-indexed number.
template <class T>
void LinkedList<T>::Print() const
{
	Node<T>* temp = front;
	int index = 1;
	while(index <= num_of_elements)
	{
		cout << index <<". "<< temp->data << endl;
		index++;
		temp = temp->next;
	}
}

#endif
