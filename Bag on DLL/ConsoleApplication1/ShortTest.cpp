#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"


void testAll() {
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}

	Bag c;
	c.add(5);
	c.add(1);
	c.add(10);
	c.add(7);
	BagIterator it2 = c.iterator();
	it2.first();
	assert(it2.remove() == 5);
	assert(it2.getCurrent() == 1);

}
