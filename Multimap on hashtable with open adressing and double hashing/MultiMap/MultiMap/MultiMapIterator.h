#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	MultiMap& m;
	//TODO - Representation
	int indexKey = -1;
	int indexValue = -1;


	MultiMapIterator(MultiMap& m);

public:
	TEl getCurrent()const;
	bool valid() const;
	void next();
	void first();
	void previous();

};