#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c) : bag(c)
{
	this->currentElem = c.head;
	this->frequency = c.elems[this->currentElem].info.second;
}

void BagIterator::first() {
	this->currentElem = this->bag.head;
	this->frequency = this->bag.elems[this->currentElem].info.second;
}


void BagIterator::next() {
	if (this->currentElem == -1) {
		throw exception();
	}
	if (this->frequency == 1) {
		this->currentElem = this->bag.next[this->currentElem];
		this->frequency = this->bag.elems[this->currentElem].info.second;
	}
	else {
		this->frequency--;
	}
}


bool BagIterator::valid() const {

	return this->currentElem != -1;
}



TElem BagIterator::getCurrent() const
{
	if (this->currentElem == -1)
		throw exception();
	else
		return this->bag.elems[currentElem].info.first;
}
