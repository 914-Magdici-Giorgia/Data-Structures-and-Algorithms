#include "MultiMapIterator.h"
#include "MultiMap.h"

MultiMapIterator::MultiMapIterator(MultiMap& m) : m(m) {

	this->first();
}


TEl MultiMapIterator::getCurrent() const {

	TEl current;
	current.first = this->m.hashTable[this->indexKey].first;
	current.second = this->m.hashTable[this->indexKey].second[indexValue];
	return current;
}


bool MultiMapIterator::valid() const {

	if (this->indexKey == -1 || this->indexKey == this->m.capacity)
		return false;
	return true;
}

void MultiMapIterator::next() {

	int indexK = this->indexKey;
	int indexV = this->indexValue + 1;

	if (indexV < this->m.hashTable[indexK].second.size())
	{
		this->indexValue++;
		return;
	}
	else
	{
		indexK++;
		while (indexK < this->m.capacity)
		{
			if (this->m.hashTable[indexK].first != NULL_TKEY && this->m.hashTable[indexK].first != DELETED)
			{
				this->indexKey = indexK;
				this->indexValue = 0;
				return;
			}
			indexK++;
		}
	}
	this->indexKey = this->m.capacity;
}




void MultiMapIterator::first() {

	int i = 0;
	while (i < this->m.capacity)
	{
		if (this->m.hashTable[i].first != NULL_TKEY && this->m.hashTable[i].first != DELETED)
		{
			this->indexKey = i;
			this->indexValue = 0;
			return;
		}
		i++;
	}
}

void MultiMapIterator::previous()
{
	int indexK = this->indexKey;
	int indexV = this->indexValue + 1;

	if (indexV >0)
	{
		this->indexValue--;
		return;
	}
	else
	{
		indexK--;
		while (indexK > 0)
		{
			if (this->m.hashTable[indexK].first != NULL_TKEY && this->m.hashTable[indexK].first != DELETED)
			{
				this->indexKey = indexK;
				this->indexValue = this->m.hashTable[indexK].second.size();
				return;
			}
			indexK--;
		}
	}
	this->indexKey = 0;
}

