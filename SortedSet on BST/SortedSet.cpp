#include "SortedSet.h"
#include "SortedSetIterator.h"
#include<iostream>

BSTNode* SortedSet::initNode(TElem e)
{
	BSTNode* newNode = new BSTNode();
	newNode->info = e;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}



SortedSet::SortedSet(Relation r) {
	this->relation = r;
	this->root = nullptr;
	this->Size = 0;
}


bool SortedSet::add(TComp elem) {

	/*bool existing_item = search(elem);
	if (existing_item == true)
		return false;
	insert_rec(this->root, elem);
	this->Size++;
	return true;*/


	BSTNode* new_node;
	BSTNode* parent = new BSTNode;

	new_node = root;

	if (root == nullptr) {
		root = initNode(elem);
		Size++;
		return true;
	}

	while (new_node && new_node->info != elem) {
		parent = new_node;

		if (relation(elem, new_node->info))
			new_node = new_node->left;
		else
			new_node = new_node->right;
	}

	if (!new_node) {
		new_node = initNode(elem);

		if (relation(elem, parent->info))
			parent->left = new_node;
		else
			parent->right = new_node;
		Size++;
		return true;
	}
	return false;
	
}
//
//BSTNode* SortedSet::insert_rec(BSTNode* node,TComp elem)
//{
//	if (node == nullptr)
//		node = initNode(elem);
//	else {
//		if (this->relation(node->info, elem))
//			node->right = insert_rec(node->right, elem);
//		else
//			node->left = insert_rec(node->left, elem);
//	}
//	return node;
//}




BSTNode* SortedSet::remove_rec(BSTNode* node, TComp elem, bool& found)
{
	if (!node)
		return node;
	if (node->info == elem) {
		found = true;
		if (node->left == nullptr && node->right == nullptr)
			return nullptr;

		if (node->left == nullptr) {
			return node->right;
		}
		if (node->right == nullptr) {
			return node->left;
		}
		BSTNode* temp = minValueNode(node->right);
		node->info = temp->info;
		node->right = remove_rec(node->right, temp->info, found);
	}
	else
		if (this->relation(elem, node->info))
			node->left = remove_rec(node->left, elem, found);
		else
			node->right = remove_rec(node->right, elem, found);

	return node;

}

bool SortedSet::remove(TComp e)
{
	bool found = false;
	root = remove_rec(this->root, e, found);
	if (found == true)
		this->Size--;
	return found;
}



BSTNode* SortedSet::minValueNode(BSTNode* node)
{
	BSTNode* current = node;
	while (current && current->left != nullptr)
		current = current->left;
	return current;
}

bool SortedSet::search(TComp elem) const
{
	return (search_rec(this->root,elem));
}

bool SortedSet::search_rec(BSTNode* node, TComp e) const 
{
	if (node == nullptr)
		return false;
	else
	{
		if (node->info == e)
			return true;
		else
		{
			if (this->relation(node->info, e))
				return search_rec(node->right, e);
			else
				return search_rec(node->left, e);
		}
	}
}






int SortedSet::size() const {
	return this->Size;
}



bool SortedSet::isEmpty() const {
	return (this->Size==0);
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	delete root;
}

void delete_rec(BSTNode* root,SortedSet* mySet,int& count) {
	if (root != nullptr) {
		if (mySet->search(root->info)) {
			count++;
			mySet->remove(root->info);
		}
		delete_rec(root->left, mySet, count);
		delete_rec(root->right, mySet, count);
	}
}

int SortedSet::difference(const SortedSet& s)
{

	int count = 0;
	delete_rec(s.root, this, count);
	return count;

}


