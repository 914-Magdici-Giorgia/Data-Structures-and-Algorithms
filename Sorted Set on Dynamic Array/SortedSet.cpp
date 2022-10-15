#include "SortedSet.h"
#include"SortedSetIterator.h"
#include<exception>
using namespace std;

SortedSet::SortedSet(Relation r)
{
	this->relation = r;
	this->elements = new TComp[1];
	this->nr_elements = 0;
	this->capacity = 1;
}//Theta(1)

SortedSet::~SortedSet() {
	delete[]this->elements;
}//thetta(1)

bool SortedSet::add(TComp elem) {
	if (search(elem) == true)
		return false;
	if (this->capacity == this->nr_elements) {
		TComp* aux = new TComp[2 * this->capacity];
		for (int i = 0; i < this->nr_elements; i++) {
			aux[i] = this->elements[i];
		}
		delete[] this->elements;
		this->capacity *= 2;
		this->elements = aux;
	}

	int i;
	this->nr_elements++;
	for (i = this->nr_elements - 2; (i >= 0 && this->relation(elem, this->elements[i])); i--)
		this->elements[i + 1] = this->elements[i];
	this->elements[i + 1]=elem;
	return true;

}//Best case:Theta(1),Worst case:Theta(nr_elements), Total Complexity:O(nr_elements)

bool SortedSet::remove(TComp elem) {
	if (isEmpty())
		return false;
	int position = -1;
	bool found = false;
	for(int i=this->nr_elements-1;i>=0;i--)
		if (this->elements[i] == elem) {
			position = i;
			found = true;
		}
	if (found) {
		for (int i = position + 1; i < this->nr_elements; i++)
			this->elements[i - 1] = this->elements[i];
		this->nr_elements--;
		return true;
	}

	return false;
}
//Best case:Theta(1), Worst case: Theta(nr_elements), Total Complexity:O(nr_elements)


bool SortedSet::search(TElem elem) const
{
	if (isEmpty())
		return false;
	int index = 0;
	while (index < this->nr_elements) {
		if (this->elements[index] == elem)
			return true;
		else
			index++;
	}
	return false;
}//Best case: Theta(1), Worst case: Theta(nr_elemets) => Total Complexity: O(nr_elemets)

int SortedSet::size()const{
	return this->nr_elements;

}//Theta(1)

bool SortedSet::isEmpty()const {
	return (this->nr_elements == 0);
}


//Theta(1)

SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
}