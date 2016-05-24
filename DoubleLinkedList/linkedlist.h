#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	// Default Constructor of Node
	Node():next(NULL),prev(NULL){};

	// Parameterrized constructor
	Node(T value):data(value),next(NULL),prev(NULL){};

	public:
		T data; // Template type data of Node
		Node<T>* next; // pointer to next
		Node<T>* prev; // pointer to previous
};

template <class T>
class LinkedList
{
public:
	LinkedList(); // Constructor

	LinkedList(const LinkedList<T>& ll); // Copy constructor

	~LinkedList(); // Destructor

	// Overloaded assignment operator
	const LinkedList & operator = (const LinkedList<T>& ll);

	int Size() const; // Returns the number of items in the list

	bool IsEmpty() const; // Returns true if the list is empty, false otherwise

	bool Contains(T item) const; // Returns whether a specified item exists in the list

	T ElementAt(int p) const; // Returns the data value of the list element at index p

	void InsertAt(T item, int p); // Inserts an item into the list at index p, otherwise
								  // should throw a runtime_error of an invalid index
	T RemoveAt(int p); // Removes and returns the item at index p, otherwise
					   // should throw a runtime_error of an invalid index
	void Print() const; // prints the contents of the playlist with one song on each
						// line of output preceded by a 1-indexed number

private:
	Node<T>* front; // front of the LinkedList

	Node<T>* back; // back of the LinkedList

	int num_of_elements; // Number of items in the list

	void DeepCopy(const LinkedList<T>& ll); // Helper method for copy constructor and
											// assignment operator
	void deleteList(); // Helper method for Destructor and assignment operator

};

#include "linkedlist.cpp" // Include the implementation file
#endif /* LINKEDLIST_H_ */
