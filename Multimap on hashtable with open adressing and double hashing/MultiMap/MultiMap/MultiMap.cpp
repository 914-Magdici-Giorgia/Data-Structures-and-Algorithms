#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//complexity -> theta(capacity)
void MultiMap::resize()
{
	std::vector<TEl> values;

	for (int i = 0; i < this->capacity; i++)
		for (auto elem : this->hashTable[i].second)
		{
			TEl current(this->hashTable[i].first, elem);
			values.push_back(current);
		}

	this->hashTable = new TElem[this->capacity * 2];
	this->capacity *= 2;
	this->Size = 0;

	for (int i = 0; i < this->capacity; i++)
		this->hashTable[i].first = NULL_TKEY;

	for (auto elem : values)
		this->add(elem.first, elem.second);

}
// complexity = theta(1)
MultiMap::MultiMap() {

	this->capacity = 100;
	this->Size = 0;
	this->hashTable = new TElem[this->capacity];
	this->load_factor = 0.7;
	this->keys = 0;

	for (int i = 0; i < this->capacity; i++)
		this->hashTable[i].first = NULL_TKEY;


}

// complexity = O(capacity)
void MultiMap::add(TKey c, TValue v) {


	

	int i = 0;
	int position = this->hash(c, i);

	while (i < this->capacity && (this->hashTable[position].first != NULL_TKEY && this->hashTable[position].first != DELETED))
	{
		if (this->hashTable[position].first == c)
		{
			this->hashTable[position].second.push_back(v);
			this->Size++;
			return;
		}
		i++;
		position = this->hash(c, i);
	}

	if (i == this->capacity)
	{
		this->resize();
		this->add(c, v);
	}
	else
	{
		this->hashTable[position].first = c;
		this->hashTable[position].second.push_back(v);
		this->Size++;
	}
}
/// complexity is O(capacity)
bool MultiMap::remove(TKey c, TValue v) {

	int i = 0;
	int position = this->hash(c, i);

	while (i < this->capacity && this->hashTable[position].first != NULL_TKEY)
	{
		if (this->hashTable[position].first == c)
		{
			for (int j = 0; j < this->hashTable[position].second.size(); j++)
				if (this->hashTable[position].second[j] == v)
				{
					this->hashTable[position].second.erase(this->hashTable[position].second.begin() + j);
					this->Size--;

					if (this->hashTable[position].second.size() == 0)
						this->hashTable[position].first = DELETED;
					return true;
				}
			return false;
		}
		i++;
		position = this->hash(c, i);
	}
	return false;

}

//complexity = O(capacity)
vector<TValue> MultiMap::search(TKey c) {

	int i = 0;
	int position = this->hash(c, i);

	while (i < this->capacity && this->hashTable[position].first != NULL_TKEY)
	{
		if (this->hashTable[position].first == c)
			return this->hashTable[position].second;
		i++;
		position = this->hash(c, i);

	}
	std::vector<TValue> empty;
	return empty;

}

// complexity = theta(1)
int MultiMap::size() const {

	return this->Size;
}

//  complexity is theta(1)
bool MultiMap::isEmpty() const {

	return this->Size == 0;
}

// complexity = theta(1)
MultiMapIterator MultiMap::iterator() {
	return MultiMapIterator(*this);
}


// complexity = theta(1)
MultiMap::~MultiMap() {

	delete[] this->hashTable;
}