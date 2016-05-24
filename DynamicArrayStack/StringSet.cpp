#include "StringSet.h"

// Default constructor
// PURPOSE: creates an array of strings of size 4
// PARAM:
// PRE:
// POST: an array of size 4
StringSet::StringSet()
{
	max_size = 4;
	arr = new string[max_size]; // Dynamic array
	current_size = 0;
}

// Copy constructor
// PURPOSE: creates a deep copy of its parameter
// PARAM: the array to be copied
// PRE: calling 'CopyArr()'
// POST: a copied array
StringSet::StringSet(const StringSet & st)
{
	CopyArr(st);
}

// Destructor
// PURPOSE: frees dynamic memory associated by the object(array)
// PARAM:
// PRE:
// POST: an empty array
StringSet::~StringSet()
{
	delete [] arr; // Deallocate dynamic memory
}

// Insertion
// PURPOSE: returns false without inserting value if a string matching the
//			parameter is already in the array;otherwise: inserts the string
//			parameter at the next available index; if the underlying array
//			is full, creates an array of twice the size of current array
// PARAM: is the element to be inserted
// PRE: calling 'Find()'
// POST: returns 'false'; otherwise inserts the string parameter at
//		the next available index; if the array is full, doubles the max size;
//		and increments current size and returns true
bool StringSet::Insert(string st)
{
	int index = Find(st);
	if(index != -1)
	{
		return false;
	}
	// If array full
	if(current_size == max_size)
	{
		// Make a new array of twice the size
		max_size = max_size * 2;
		string* temp = arr;
		arr = new string[max_size];

		// Copy the contents of the old array to the new array
		for(int i=0; i<current_size; i++)
		{
			arr[i] = temp[i];
		}
		// Deallocate memory for old array
		delete [] temp;
	}
	// Insert the new element
	arr[current_size] = st;
	current_size++;
	return true;

}

// Removing
// PURPOSE: returns false if a string matching the parameter is not in the
//			array, otherwise: replaces matching string with the last string
//			in the array(if there is one); decrements current size and returns true
// PARAM: is the element to be removed
// PRE:
// POST: returns false; otherwise: replaces matching string with the last string
//		in the array(if there is one); decrements current size and returns true
bool StringSet::Remove(string st)
{
	int index = Find(st);
	if(index == -1)
	{
		return false;
	}
	else if(index == (current_size -1))
	{
		current_size--;
		return true;
	}
	else
	{
		this->arr[index] = arr[current_size - 1];
		current_size--;
		return true;
	}

}

// Find
// PURPOSE: if a string matching the parameter is in the array, returns the index
//			of that string, otherwise returns -1
// PARAM: the item to be compared with the array's elements
// PRE:
// POST: returns the index of that string; otherwise returns -1
int StringSet::Find(string st) const
{
	for(int i=0; i<current_size; i++)
	{
		if(arr[i] == st)
		{
			return i;
		}
	}
	return -1;
}

// Size
// PURPOSE: returns the current size (the number of strings in the array)
// PARAM:
// PRE:
// POST: returns the current size of the array
int StringSet::Size() const
{
	return current_size;
}

// Union
// PURPOSE: returns a StringSet object that contains the union of the calling
//			object and the parameter
// PARAM: the array that will compare with the calling object
// PRE: the array elements must be string type
// POST: returns the union of the calling object and the parameter
StringSet StringSet::Union(const StringSet & string_source) const
{
	StringSet result;
	for(int i=0; i<this->current_size; i++)
	{
		string st = this->arr[i];
		result.Insert(st);
	}
	for(int i=0; i<string_source.current_size; i++)
	{
		string st = string_source.arr[i];
		result.Insert(st);
	}
	return result;
}

// Intersection
// PURPOSE: returns a StringSet object that contains the intersection of the
//			calling object and the parameter
// PARAM: the array that will compare with the calling object
// PRE: the array elements must be string type
// POST: returns the intersection of the calling object and the parameter
StringSet StringSet::Intersection(const StringSet & string_source) const
{
	StringSet result;
	for(int i=0; i<this->current_size; i++)
	{
		string st = this->arr[i];
		if(string_source.Find(st) != -1)
		{
			result.Insert(st);
		}
	}
	return result;
}

// Difference
// PURPOSE: returns a StringSet object that contains the set difference of
//			the calling object and the parameter
// PARAM: the array that will compare with the calling object
// PRE: the array elements must be string type
// POST: returns the difference of the calling object and the parameter
StringSet StringSet::Difference(const StringSet & string_source) const
{
	StringSet result;
	for(int i=0; i<this->current_size; i++)
	{
		string st = this->arr[i];
		if(string_source.Find(st) == -1)
		{
			result.Insert(st);
		}
	}
	return result;
}

// Copy Method
// PURPOSE: helper method for Copy constructor
// PARAM: the object to be copied
// PRE:
// POST: used by Copy constructor
void StringSet::CopyArr(const StringSet & st)
{
	current_size = st.current_size;
	max_size = st.max_size;

	arr = new string [max_size];

	// Copy the contents of the array
	for(int i=0; i<current_size; i++)
	{
		arr[i] = st.arr[i];
	}
}
