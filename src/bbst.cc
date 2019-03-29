// bbst.cc

#include <iostream>

#include "bbst.h"


void bbst::insert(float val, std::string info)
{
	if (root)
	{
		root->m_nodeCount+=1;
		root = root->insert(val, info);
	}
	else
	{
		root = new node(val);
		root->m_info = info;
	}
}

void bbst::remove(float val)
{
	if (root)
	{
		root->m_nodeCount-=1;
		root = root->remove(val);
	}
	else
	{
		std::cout << "No tree!" << std::endl;
	}
}

void bbst::traverse(node::traversal_mode mode)
{
	if (root)
	{
		root->traverse(mode);
	}
}

void bbst::print()
{
	if (root) root->print();
	else std::cout << "No tree!" << std::endl;
}