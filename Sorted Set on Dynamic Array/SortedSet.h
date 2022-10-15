#pragma once

typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111

class SortedSetIterator;

class SortedSet {
	friend class SortedSetIterator;
private:
	TElem* elements;
	int capacity;
	int nr_elements;
	Relation relation;

public:
	//constructor
	SortedSet(Relation r);

	//destructor
	~SortedSet();


	//adds an element to the sorted set
	//if the element was added, the operarion returns true,  false otherwise (if the element was already in the set)
	bool add(TComp e);


	//removes an element from the sorted set 
	//it returnes true if the element was removed, false otherwise
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TElem elem) const;

	//returns the number of elements from the sorted set 
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;


};