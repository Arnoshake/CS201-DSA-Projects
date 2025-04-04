#ifndef _ST_HPP_
#define _ST_HPP_

#include <utility>
#include <vector>
#include "RBT.hpp"
#include "RBTPrint.hpp"
/*
 Name: Zachary West
 Email: zjwest1@crimson.ua.edu
 Course Section: Spring 2025 CS 201
 Homework #: 2
*/
template <class Key, class Type>
class ST : public RedBlackTree<Key, Type>
{
public:
	typedef RBTNode<Key, Type> *iterator;

	// Constructors
	// constant O(1)
	ST()
	{
		nodeCount = 0;
		// do i need to declare a node or is it implied within the RedBlackTree Declaration?
	};

	// Destructor
	// linear in the size of the ST O(N)
	~ST() {
		// default deconstructor takes care of this, declaration is required
	};

	// access or insert specifies element
	// inserts if the key is not present and returns a reference to
	// the value corresponding to that key
	// O(LogN), N size of ST
	Type &operator[](const Key &key) { // DO THIS!!!!
		iterator node = find(key);
		if (node != nullptr){
			return node->value;
		}
		insert(key,Type{}); //inserts as the generic placeholder of type Type... like 0 in int vect
		return find(key)->value;
	};

	// insert a (key, value) pair, if the key already exists
	// set the new value to the existing key
	// O(LogN), N size of ST
	void insert(const Key &key, const Type &value)
	{
		iterator node = find(key);
		if (node == nullptr){
			RedBlackTree<Key, Type>::Insert(key, value);
			nodeCount++;
		}
		else{
			node->value = value;
		}
		
	};

	// remove element at the given position
	// amortized constant
	void remove(iterator position)
	{
		if (RedBlackTree<Key, Type>::Remove(position))
			nodeCount--;
	};

	// remove element with keyvalue key and
	// return number of elements removed (either 0 or 1)
	// O(logN), N size of ST
	std::size_t remove(const Key &key)
	{
		if (RedBlackTree<Key, Type>::Remove(key))
		{ // Delete is O(LogN)
			nodeCount--;
			return 1;
		}
		return 0;
	};

	// removes all elements from the ST, after this size() returns 0
	// linear in the size of the ST
	void clear()
	{
		RedBlackTree<Key, Type>::DeleteTree(RedBlackTree<Key, Type>::GetRoot()); // DeleteTree is O(N)
		nodeCount = 0;															 // O(1)
	};

	// checks if ST has no elements; true is empty, false otherwise
	// constant
	bool empty() const {
		return (nodeCount == 0); // O(1)
	};

	// returns number of elements in ST
	// constant
	std::size_t size() const
	{
		return nodeCount; // O(1)
	};

	// returns number of elements that match keyvalue key
	// value returned is 0 or 1 since keys are unique
	// O(LogN), N size of ST
	std::size_t count(const Key &key)
	{
		if (this->contains(key))
			return 1;
		return 0;
	};

	// find an element with keyvalue key and return
	// the iterator to the element found, nullptr if not found
	// O(LogN), N size of ST
	iterator find(const Key &key)
	{
		return RedBlackTree<Key, Type>::Search(key); // Search = O(logN)
													 // iterator is used temporarily, no need to actually return it...
	};

	// check if key exists in ST
	// O(LogN), N size of ST
	bool contains(const Key &key)
	{
		if (RedBlackTree<Key, Type>::Search(key) == nullptr)
			return false; // Search = O(logN)
		else
		{
			return true;
		}
	};






	// return contents of ST as a vector of (key,value) pairs
	// O(N), N size of ST
	std::vector<std::pair<Key, Type> > toVector() //vector size is zero, so loop doesnt work dummy
	{ // DO THIS!
		std::vector<std::pair<Key, Type> > vector;
		inOrderTraversalVector(this->root, vector); // call it on the root... will populate vector
		return vector;
	};

	// print the symbol table as Red-Black Tree
	// O(N), N size of ST
	void displayTree()
	{
		std::cout << RBTPrint<Key, Type>::TreeToString(RedBlackTree<Key, Type>::root) << std::endl;
	};

	// print the symbol table in sorted order
	// O(N), N size of ST
	void display()
	{
		std::vector<std::pair<Key, Type> > displayVector = toVector();
		for (int i = 0; i < displayVector.size(); i++)
		{
			std::cout << "(" << displayVector.at(i).first << ", " << displayVector.at(i).second << ") ";
		}
		std::cout << std::endl;
	};

	void inOrderTraversalVector(RBTNode<Key, Type> *node, std::vector<std::pair<Key, Type> > &vector) const
	{ // vector edited by reference, keeping return type void
		if (!node)
			return;								// if a null node (aka child of leaf), bottom of tree depth reached, time to recurse upward
		inOrderTraversalVector(node->left,vector);			// Visit left
		vector.push_back(std::pair<Key, Type>(node->key, node->value));
		inOrderTraversalVector(node->right,vector);			// Visit right
	}

private:
	std::size_t nodeCount;
};

#endif
