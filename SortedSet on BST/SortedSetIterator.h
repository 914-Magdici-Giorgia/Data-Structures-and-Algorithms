#pragma once
#include "SortedSet.h"

class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& BT;
	SortedSetIterator(const SortedSet& m);

	BSTNode** stack;
    int top;
	BSTNode* current;

	//TODO - Representation

public:
	void first();
	void next();
	TComp getCurrent();
	bool valid() const;

};

