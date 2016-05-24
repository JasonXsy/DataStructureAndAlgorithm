#ifndef STRINGSET_H_
#define STRINGSET_H_
#include <string>
using namespace std;

class StringSet
{
public:
	// Default constructor
	StringSet();

	// Copy constructor
	StringSet(const StringSet&);

	// Destructor
	~StringSet();

	// Inserts the string parameter at the next available index
	bool Insert(string);

	// Replaces matching string with the last string in the array
	bool Remove(string);

	// Returns the index of a string if that string matching the
	// parameter is in the array
	int Find(string) const;

	// Returns the current size
	int Size() const;

	// Returns a StringSet object that contains the union of the
	// calling object and the parameter
	StringSet Union(const StringSet&) const;

	// Returns a StringSet object that contains the intersection
	// of the calling object and the parameter
	StringSet Intersection(const StringSet&) const;

	// Returns a StringSet object that contains the set difference
	// of the calling object and the parameter
	StringSet Difference(const StringSet&) const;

public:
	void CopyArr(const StringSet&); // Helper function for copy constructor

	string* arr;   // arr is a pointer to string
	int current_size; // The number of strings stored in the array
	int max_size;  // The maximum size of the array

};


#endif /* STRINGSET_H_ */
