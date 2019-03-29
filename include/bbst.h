#ifndef bbst_h
#define bbst_h
// bbst.h
#include "node.h"
#include <string>

class bbst
{
public:
	bbst() {};
	bbst(float value) { root = new node(value); };


	node *root = nullptr;

	void insert(float value, void *info = nullptr);
	void remove(float value);
	void traverse(node::traversal_mode mode);
	void print();
};

#endif
