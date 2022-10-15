#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;



Bag::Bag() {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}


void Bag::add(TElem elem) {

	if (size() == 0) {
		Node* newNode = new Node();
		createNode(newNode, nullptr, nullptr, elem);
		this->head = newNode;
		this->tail = newNode;
		this->length++;
	}
	else {
		Node* current = this->head;
		bool found = false;
		while (current != nullptr && !found) {
			if (current->info.first == elem) {
				current->info.second++;
				this->length++;
				found = true;
			}
			else
				current = current->next;
		}

		if (!found) {
			Node* newNode = new Node();
			createNode(newNode, this->tail, nullptr, elem);
			this->tail->next = newNode;
			this->tail = newNode;
			this->length++;
		}
	}
}


bool Bag::remove(TElem elem) {
	Node* current = this->head;
	bool found = false;
	if (size() != 0) {
		while (current != nullptr && !found)
			if (current->info.first != elem)
				current = current->next;
			else {
				found = true;
				current->info.second--;
				this->length--;

				if (current->info.second == 0)
					if (current == this->head) {
						if (current->next != nullptr) {
							current->next->prev = nullptr;
							this->head = current->next;
							current->next = nullptr;
							delete current;
						}
						else
							current = nullptr;
					}
					else
						if (current == this->tail) {
							if (current->prev != nullptr) {
								current->prev->next = nullptr;
								this->tail = current->prev;
								current->prev = nullptr;
								delete current;
							}
						}
						else {
							current->prev->next = current->next;
							current->next->prev = current->prev;
							current->next = nullptr;
							current->prev = nullptr;
							delete current;
						}


			}
	}
	return found;

}


bool Bag::search(TElem elem) const {
	Node* current = this->head;
	while (current != nullptr) {
		if (current->info.first == elem)
			return true;
		current = current->next;
	}
	return false;
}

int Bag::nrOccurrences(TElem elem) const {

	Node* current = this->head;
	while (current != nullptr) {
		if (current->info.first == elem)
			return current->info.second;
		current = current->next;
	}
	return 0;
}


int Bag::size() const {

	return this->length;
}


bool Bag::isEmpty() const {

	return (this->length == 0);
}

BagIterator Bag::iterator()  {
	return BagIterator(*this);
}


Bag::~Bag() {
	Node* previous = nullptr;
	Node* current = this->head;
	while (current != nullptr) {
		previous = current;
		current = current->next;
		delete previous;
	}
}

