// main.cc

#include <iostream>
#include <fstream>

#include "bbst.h"
#include "planeSweeper.h"

using namespace std;

typedef planeSweeper::hoard hoard;
planeSweeper ps;

int main()
{

	// ps.eventQueue->root->m_callBack = planeSweeper::eventHandler;

	std::ifstream planeInput;
	planeInput.open("input/LineSegments.txt");

	int e1x, e1y, e2x, e2y, lineID = 0;
	while (planeInput >> e1x >> e1y >> e2x >> e2y)
	{
		hoard *left_input = new hoard();
		*left_input = { e1x < e2x ? hoard::start : hoard::end, {e1x, e1y}, lineID };
		ps.eventQueue->insert(e1x, left_input);

		hoard *right_input = new hoard();
		*right_input = { e1x >= e2x ? hoard::start : hoard::end, {e2x, e2y}, lineID };
		ps.eventQueue->insert(e2x, right_input);

		lineID+=1;
	}

	ps.eventQueue->traverse(node::lowestToHighest, planeSweeper::eventHandler);

	return 0;
}
