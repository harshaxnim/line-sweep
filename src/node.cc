// bbst.cc

#include <iostream>
#include <algorithm>

#include "node.h"

bool node::operator<(const node& rightOperand)
{
	return (m_value < rightOperand.m_value);
}

bool node::operator<=(const node& rightOperand)
{
	return (m_value <= rightOperand.m_value);
}

bool node::operator>(const node& rightOperand)
{
	return (m_value > rightOperand.m_value);
}

bool node::operator>=(const node& rightOperand)
{
	return (m_value >= rightOperand.m_value);
}

void (*node::callBack)(const node& callingNode) = nullptr;

void node::traverse(traversal_mode mode)
{
	switch(mode)
	{
		case lowestToHighest:
			if (m_leftChild) m_leftChild->traverse(mode);
			if (callBack) callBack(*this);
			if (m_rightChild) m_rightChild->traverse(mode);
			break;
		default:
			std::cout << "This mode of traversal hasn't been implemented yet." << std::endl;
	}

}

node * node::remove(float val)
{
	if (val == m_value)
	{
		if (!m_leftChild && !m_rightChild)
		{
			return nullptr;
		}
		else if (m_leftChild && !m_rightChild)
		{
			return m_leftChild;
		}
		else if (!m_leftChild && m_rightChild)
		{
			return m_rightChild;
		}
		else
		{
			node *seeker = m_rightChild;
			while (seeker->m_leftChild)
			{
				seeker = seeker->m_leftChild;
			}
			m_value = seeker->m_value;
			m_rightChild = seeker->remove(m_value);
		}

	}
	else if (val < m_value)
	{
		if (m_leftChild) m_leftChild = m_leftChild->remove(val);
	}
	else if (val > m_value)
	{
		if (m_rightChild) m_rightChild = m_rightChild->remove(val);
	}
	update();
	return balance();
}

node * node::insert(float val, void *info)
{
	if (val <= m_value)
	{
		if (m_leftChild)
		{
			m_leftChild = m_leftChild->insert(val, info);
		}
		else
		{
			m_leftChild = new node(val);
			m_leftChild->m_info = info;
		}
	}
	else if (val > m_value)
	{
		if (m_rightChild)
		{
			m_rightChild = m_rightChild->insert(val, info);
		}
		else
		{
			m_rightChild = new node(val);
			m_rightChild->m_info = info;
		}
	}
	update();
	return balance();
}

void node::update()
{
	int lh = 0;
	int rh = 0;
	if (m_leftChild)
	{
		lh = m_leftChild->m_height;
	}
	if (m_rightChild)
	{
		rh = m_rightChild->m_height;
	}

	m_height = 1 + std::max(lh, rh);
	m_balanceFactor = rh - lh;
}

node * node::balance()
{
	// Left Leaning Node:
	if (m_balanceFactor == -2)
	{
		if (m_leftChild->m_balanceFactor == -1)
		{
			return leftLeftCase();
		}
		else
		{
			return leftRightCase();
		}
	}
	// Right Leaning Node
	else if (m_balanceFactor == 2)
	{
		if (m_rightChild->m_balanceFactor == -1)
		{
			return rightLeftCase();
		}
		else
		{
			return rightRightCase();
		}	
	}
	// Already balanced
	return this;
}

node * node::leftLeftCase()
{
	return rightRotation();
}

node * node::leftRightCase()
{
	m_leftChild = m_leftChild->leftRotation();
	return leftLeftCase();
}

node * node::rightLeftCase()
{
	m_rightChild = m_rightChild->rightRotation();
	return rightRightCase();
}

node * node::rightRightCase()
{
	return leftRotation();
}

node * node::leftRotation()
{
	node *replacementNode = m_rightChild;
	m_rightChild = replacementNode->m_leftChild;
	replacementNode->m_leftChild = this;
	
	update();
	replacementNode->update();
	return replacementNode;
}

node * node::rightRotation()
{
	node *replacementNode = m_leftChild;
	m_leftChild = replacementNode->m_rightChild;
	replacementNode->m_rightChild = this;
	
	update();
	replacementNode->update();
	return replacementNode;
}

void node::print()
{
	std::cout << ".\n" << m_value << "\n👈" << std::endl;
	if (m_leftChild) m_leftChild->print(); else std::cout << "💩" << std::endl;
	std::cout << ".\n" << m_value << "\n️👉" << std::endl;
	if (m_rightChild) m_rightChild->print(); else std::cout << "💩" << std::endl;
}
