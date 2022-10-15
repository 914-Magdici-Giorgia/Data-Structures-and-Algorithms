#pragma once
//DO NOT INCLUDE BAGITERATOR
#include<iostream>
#include<vector>
using namespace std;

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator;
struct Node{ std::pair<TElem, int> info; };
class Bag {

private:

	
	Node* elems;
	int* next;
	int* prev;
	int capacity;
	int head, tail;
	int firstEmpty;
	int length;

	int allocateP();
	void resize();

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) ;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	int findElement(TElem e);

	//destructor
	~Bag();

	vector<int> histogram() const;
};