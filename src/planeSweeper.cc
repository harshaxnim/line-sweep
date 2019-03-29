// planeSweeper.cc

#include "planeSweeper.h"
#include <iostream>

extern planeSweeper ps;

void planeSweeper::eventHandler(const node &callingNode)
{
	
	hoard* info = (hoard*) callingNode.m_info;
	hoard::eventType et = info->eType;
	hoard::coord ec = info->eCoord;

	if (et == hoard::start)
	{
		std::cout << "s" << std::endl;
	}
	else if (et == hoard::intersect)
	{
		std::cout << "i" << std::endl;
	}
	else if (et == hoard::end)
	{
		std::cout << "e" << std::endl;
	}
	else
	{
		std::cout << "fuck, i don't know what to do..." << std::endl;
	}
}