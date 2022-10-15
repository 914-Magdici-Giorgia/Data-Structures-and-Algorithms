#pragma once
#include "SortedSet.h"

class SortedSetIterator {
	friend class SortedSet;
private:
	const SortedSet& set;
	SortedSetIterator(const SortedSet& m);

	int current;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid()const;
	void jumpForward(int k);


};