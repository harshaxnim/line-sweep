// planeSweeper.cc

#include "planeSweeper.h"
#include <iostream>

extern planeSweeper ps;

void planeSweeper::eventHandler(const node &callingNode)
{
	if (callingNode.m_info == "s")
	{
		ps.sweepLineStatus->insert(callingNode.m_value);

		std::cout << "s" << std::endl;
	}
	else if (callingNode.m_info == "e")
	{
		std::cout << "e" << std::endl;
	}
	else if (callingNode.m_info == "i")
	{
		std::cout << "i" << std::endl;
	}
	else
	{
		std::cout << "fuck, i don't know what to do..." << std::endl;
	}
}