#include "playlist.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// PlayList
// PURPOSE: creates an empty playlist
// PARAM:
// PRE: calling the constructor of LinkedList with string template type
// POST: an empty playlist with string template type
PlayList::PlayList()
{
	LinkedList<string> ();
}

// Sise
// PURPOSE: returns the number of items in the playlist
// PARAM:
// PRE: calling the LinkedList method - Size()
// POST: the size of the playlist
int PlayList::Size() const
{
	return songList.Size();
}

// Play
// PURPOSE: removes and returns an item from the front of the playlist
// PARAM:
// PRE: calling the LinkedList method - RemoveAt()
// POST: the first item in the playlist removed and returned
string PlayList::Play()
{
	try
	{
		return songList.RemoveAt(0);
	}
	catch(runtime_error& e)
	{
		return e.what();
	}
}

// Add
// PURPOSE: enqueues an item at the back of the playlist
// PARAM: the item to be inserted
// PRE: calling the LinkedList method - InsertAt(T item, int p)
// POST: add an item at the back of the playlist
void PlayList::Add(string song)
{
	try
	{
		songList.InsertAt(song, songList.Size());
	}
	catch(runtime_error& e)
	{
		cout << e.what() << endl;
	}
}

// MoveUp
// PURPOSE: move an item at the specified index (1-indexed) ahead by 1 position.
//          If the item is already at the front, it remains at the front
// PARAM: the item to be moved ahead
// PRE: calling the LinkedList methods - RemoveAt(), InsertAt(T item, int p)
// POST: the specified item moved ahead by 1 position
void PlayList::MoveUp(int item)
{
	try
	{
		item = item-1;
		string temp;
		if(item == 0)
		{
			temp = songList.RemoveAt(0);
			songList.InsertAt(temp, 0);
		}
		else
		{
			temp = songList.RemoveAt(item);
			songList.InsertAt(temp,item-1);
		}
	}
	catch(runtime_error& e)
	{
		cout <<e.what() << endl;
	}
}

// MoveDown
// PURPOSE: move an item at the specified index (1-indexed) back by 1 position.
//          If the item is already at the back, it remains at the back
// PARAM: the item to be moved back
// PRE: calling the LinkedList methods - RemoveAt(), InsertAt(T item, int p)
// POST: the specified item moved back by 1 position
void PlayList::MoveDown(int item)
{
	try
	{
		item = item-1;
		string temp;
		if(item == songList.Size()-1)
		{
			temp = songList.RemoveAt(item);
			songList.InsertAt(temp,item);
		}
		else
		{
			temp = songList.RemoveAt(item);
			songList.InsertAt(temp, item+1);
		}
	}
	catch(runtime_error& e)
	{
		cout << e.what() << endl;
	}
}

// PrintPlayList
// PURPOSE: prints the contents of the playlist to console using standard output,
//          with one song on each line of output preceded by a 1-indexed number.
// PARAM:
// PRE: calling the LinkedList method - Print()
// POST: the contents of the playlist will be prints
void PlayList::PrintPlayList() const
{
	songList.Print();
}


