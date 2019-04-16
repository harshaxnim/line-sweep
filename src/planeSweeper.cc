// planeSweeper.cc

#include "planeSweeper.h"
#include <iostream>

extern planeSweeper ps;

void planeSweeper::eventHandler(const node &callingNode)
{

	hoard* info = (hoard*) callingNode.m_info;
	hoard::eventType et = info->eType;
	hoard::coord ec = info->eCoord;

	// std::cout << info->lineID << "\t";
	// std::cout << et << "\t";
	// std::cout << ec.x << ", " << ec.y << std::endl;

	if (et == hoard::start)
	{
		// TODO
		// add to sweep line status
		ps.sweepLineStatus->insert(ec.y, info);

		// find adjacent segments in the sweep line
		thisNode = new node(ec.y, info);
		std::cout << thisNode << std::endl;
		ps.sweepLineStatus->traverse(node::lowestToHighest, planeSweeper::adjacentNodesHelper);

		// test intersections with these segments
		std::cout << thisNode << std::endl;
		thisNode->print();


		// add intersection to the event queue

		resetAdjacentNodesHelper();
	}
	else if (et == hoard::intersect)
	{
		// TODO
	}
	else if (et == hoard::end)
	{
		// TODO
	}
	else
	{
		std::cout << "fuck, i don't know what to do..." << std::endl;
	}
}

node *planeSweeper::prevNode = nullptr;
node *planeSweeper::thisNode = nullptr;
node *planeSweeper::nextNode = nullptr;
int planeSweeper::nodeTracker = -1;
void planeSweeper::adjacentNodesHelper(const node &callingNode)
{
	std::cout << thisNode->m_value << std::endl;
	std::cout << callingNode.m_value << std::endl;
	if ((*thisNode).m_value == callingNode.m_value)
	{
		std::cout << "= " << thisNode->m_value << std::endl;
		nodeTracker = 0;
	}
	else if (nodeTracker == -1)
	{
		prevNode = (node *)&callingNode;
	}
	else if (nodeTracker == 0)
	{
		nextNode = (node *)&callingNode;
		nodeTracker = 1;
	}
}

void planeSweeper::resetAdjacentNodesHelper()
{
	delete thisNode;
	prevNode = nullptr;
	thisNode = nullptr;
	nextNode = nullptr;
	nodeTracker = -1;
}