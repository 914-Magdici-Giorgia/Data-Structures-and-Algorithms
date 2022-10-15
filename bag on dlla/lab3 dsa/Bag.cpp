#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;






Bag::Bag() {
	this->capacity = 100;
	this->elems = new Node[this->capacity];
	this->next = new int[this->capacity];
	this->prev = new int[this->capacity];

	for (int i = 0; i < capacity - 1; i++) {
		this->next[i] = i + 1;
	}
	this->next[capacity - 1] = -1;

	for (int i = 1; i < capacity ; i++) {
		this->prev[i] = i -1;
	}
	this->next[0] = -1;

	this->head = -1;
	this->tail = -1;
	this->firstEmpty = 0;
}





void Bag::add(TElem elem) {
	int pos = findElement(elem);
	if (pos != -1) {		//the element is already in the bag
		this->elems[pos].info.second++;
	}
	else {
		pos = allocateP();
		this->elems[pos].info.first = elem;
		this->elems[pos].info.second = 1;
		this->next[pos] = -1;

		this->prev[pos] = this->tail;
		if (this->head == -1) {
			this->head = pos;
		}
		else {
			this->next[this->tail] = pos;
		}
		this->tail = pos;
	}
	this->length++;
}


bool Bag::remove(TElem elem) {
	int current = this->findElement(elem);
	if (current != -1) {
		if (this->elems[current].info.second >1) {
			this->elems[current].info.second--;
		}
		else
		{
			if (current == this->head) {
				this->head = this->next[this->head];
				if(this->head!= -1)
					this->prev[this->head] = -1;
			}
			else
				if (current == this->tail) {
					this->tail = this->prev[this->tail];
					this->next[this->tail] = -1;
				}
				else {
					this->next[this->prev[current]] = this->next[current];
					this->prev[this->next[current]] = this->prev[current];
				}

			this->next[current] = this->firstEmpty;
			this->prev[current] = -1;
			this->firstEmpty = current;
		}

		this->length--;
		return true;
	}
	
	return false;
}


bool Bag::search(TElem elem) const {
	int current = this->head;
	while (current != -1) {
		if (this->elems[current].info.first == elem)
			return true;
		current = this->next[current];
	}
	return false;
}

int Bag::nrOccurrences(TElem elem) {
	int pos = findElement(elem);
	if (pos != -1) {
		return this->elems[pos].info.second;
	}

	return 0;
}


int Bag::size() const {

	return this->length;
}


bool Bag::isEmpty() const {
	return this->head==-1;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elems;
	delete[] this->next;
	delete[] this->prev;
}

vector<int> Bag::histogram() const
{
	vector<int> h {-1};
	int current = this->head;
	while (current != -1) {
		if (this->elems[current].info.second + 1 > h.size()) {
			h.resize(this->elems[current].info.second + 1);
			h.at(this->elems[current].info.second ) = 0;
		}
		h.at(this->elems[current].info.second )++;
			
		current = this->next[current];
	}

	return h;

}

int Bag::allocateP()
{
	if (this->firstEmpty == -1)
		resize();
	int newEmpty = this->firstEmpty;
	this->firstEmpty = this->next[this->firstEmpty];
	return newEmpty;
}

void Bag::resize()
{
	int newCapacity = this->capacity * 2;
	Node* newElems = new Node[newCapacity];
	int* newNext= new int[newCapacity];
	int* newPrev = new int[newCapacity];


	int current = 0;
	while (current != this->capacity) {
		newElems[current] = this->elems[current];
		newNext[current] = this->next[current];
		newPrev[current] = this->prev[current];
		current++;
	}

	for (int i = this->capacity; i < newCapacity - 1; i++)
		newNext[i] = i + 1;

	this->firstEmpty = this->capacity;
	this->capacity = newCapacity;
	
	delete[] this->elems;
	delete[] this->next;
	delete[] this->prev;
	
	this->elems = newElems;
	this->next = newNext;
	this->prev = newPrev;
	this->next[newCapacity - 1] = -1;
}

int Bag::findElement(TElem e)
{
	int current = this->head;
	while (current != -1) {
		if (this->elems[current].info.first == e) {
			return current;
		}
		current = this->next[current];
	}
	return -1;
}


