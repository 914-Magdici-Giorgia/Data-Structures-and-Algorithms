#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : BT(m)
{
    BSTNode* node = BT.root;
    this->stack = new BSTNode * [BT.Size + 2];
    this->top = -1;

    while (node) {
        this->stack[++top] = node;
        node = node->left;
    }
    if (this->top == -1)
        this->current = nullptr;
    else
        this->current = this->stack[top];
}


void SortedSetIterator::first() {
    BSTNode* node = BT.root;
    this->stack = new BSTNode * [BT.Size + 2];
    this->top = -1;

    while (node) {
        this->stack[++top] = node;
        node = node->left;
    }
    if (this->top == -1)
        this->current = nullptr;
    else
        this->current = this->stack[top];
}


void SortedSetIterator::next() {
    if (!valid())
        throw exception();

    BSTNode* node = this->stack[top--];
    if (node->right) {
        node = node->right;
        while (node) {
            this->stack[++top] = node;
            node = node->left;
        }
    }
    if (this->top < 0)
        this->current = nullptr;
    else
        this->current = this->stack[this->top];
}


TComp SortedSetIterator::getCurrent()
{
    if (!this->valid())
        throw  exception();
    return this->current->info;
}

bool SortedSetIterator::valid() const {
    return this->current != nullptr;
}
