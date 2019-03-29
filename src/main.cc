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

	ps.eventQueue->root->callBack = planeSweeper::eventHandler;

	std::ifstream planeInput;
	planeInput.open("input/LineSegments.txt");

	int e1x, e1y, e2x, e2y, lineID = 0;
	while (planeInput >> e1x >> e1y >> e2x >> e2y)
	{
		hoard *segment_start = new hoard();
		*segment_start = { e1x < e2x ? hoard::start : hoard::end, {e1x, e1y}, lineID };
		ps.eventQueue->insert(e1x, segment_start);

		hoard *segment_end = new hoard();
		*segment_end = { e1x >= e2x ? hoard::start : hoard::end, {e2x, e2y}, lineID };
		ps.eventQueue->insert(e2x, segment_end);

		lineID+=1;
	}

	ps.eventQueue->root->traverse(node::lowestToHighest);

	return 0;
}
