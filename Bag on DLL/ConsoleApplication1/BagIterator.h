#include "Bag.h"

class Bag;

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;

private:
	Bag& bag;
	Node* currentElement;
	int count;
	BagIterator(Bag& c);
public:
	void first();
	void next();
	TElem getCurrent() const;
	bool valid() const;
	TElem remove();
};
