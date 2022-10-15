#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(Bag& c) : bag(c)
{
	this->currentElement = c.head;
	this->count = 1;
}

void BagIterator::first() {
	this->currentElement = this->bag.head;
	this->count = 1;
}


void BagIterator::next() {
	if (this->currentElement != nullptr) {
		if (this->count == this->currentElement->info.second)
		{
			this->currentElement = this->currentElement->next;
			this->count = 1;
		}
		else
			this->count++;
	}
	else
		throw exception();
}


bool BagIterator::valid() const {

	return this->currentElement != nullptr;
}

TElem BagIterator::remove()
{
	TElem e = this->currentElement->info.first;
	this->next();
	this->bag.remove(e);

	return e;
}



TElem BagIterator::getCurrent() const
{
	if (this->currentElement == nullptr)
		throw exception();
	else
		return this->currentElement->info.first;
}
