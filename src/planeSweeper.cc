// planeSweeper.cc

#include "planeSweeper.h"
#include <iostream>

extern planeSweeper ps;

void planeSweeper::eventHandler(const node &callingNode)
{

	hoard* info = (hoard*) callingNode.m_info;
	hoard::eventType et = info->eType;
	hoard::coord ec = info->eCoord;

	std::cout << info->lineID << "\t";
	std::cout << et << "\t";
	std::cout << ec.x << ", " << ec.y << std::endl;

	if (et == hoard::start)
	{
		// TODO
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