#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "linkedlist.h"
#include <iostream>
using namespace std;

class PlayList
{
public:

	PlayList(); // Creates an empty playlist

	int Size() const; // Returns the number of items in the playlist

	string Play(); // Removes and returns an item from the front of the playlist

	void Add(string song); // Enqueues and item at the back of the playlist

	void MoveUp(int item); // Moves an item at the specified index (1-indexed) ahead by 1 position

	void MoveDown(int item); // Moves an item at the specified index (1-indexed) back by 1 position

	void PrintPlayList() const; // Prints the contents of the playlist with one song on each line of output preceded by a 1-indexed number.

private:
	// A linkedlist attribute with string template type
	LinkedList<string> songList;
};

#endif /* PLAYLIST_H_ */
