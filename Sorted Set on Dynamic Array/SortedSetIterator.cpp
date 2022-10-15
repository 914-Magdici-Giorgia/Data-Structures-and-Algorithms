#include"SortedSetIterator.h"
//  #include"SortedSet.h"
#include<exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m):set(m)
{
	this->current = 0;
}//Theta(1)
void SortedSetIterator::first()
{
	this->current = 0;
}//Theta(1)
void SortedSetIterator::next()
{
	if (this->current == this->set.nr_elements)
		throw exception();
	else 
		this->current++;
}//Theta(1)

TElem SortedSetIterator::getCurrent()
{
	if (this->current == this->set.nr_elements)
		throw exception();
	return this->set.elements[this->current];
}//theta(1)

bool SortedSetIterator::valid() const
{
	if (this->current < this->set.nr_elements)
		return true;
	return false;
}//Theta(1)

void SortedSetIterator::jumpForward(int k)
{
	if (this->current + k >= this->set.nr_elements || k <= 0)
		throw exception();
	this->current+=k;
}
//Theta(1)

