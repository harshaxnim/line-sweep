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

	bbst tree;

	tree.insert(10);
	tree.insert(9);
	tree.insert(8);
	tree.insert(7);
	tree.insert(6);
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);

	// tree.traverse(node::lowestToHighest);

	ps.eventQueue->root->callBack = planeSweeper::eventHandler;


	std::ifstream planeInput;

	planeInput.open("input/LineSegments.txt");

	std::cout << (bool)planeInput << std::endl;

	int sx, sy, ex, ey;
	while (planeInput >> sx >> sy >> ex >> ey)
	{
		hoard *a = new hoard();
		std::cout << sx << sy << ex << ey << std::endl;
	}
	ps.eventQueue->insert(10, "s");
	ps.eventQueue->insert(9, "s");
	ps.eventQueue->insert(8, "e");
	ps.eventQueue->insert(7, "e");

	ps.eventQueue->root->traverse(node::lowestToHighest);

	// tree.remove(1);
	// tree.remove(2);
	// tree.remove(3);
	// tree.remove(4);
	// tree.remove(5);
	// tree.remove(6);
	// tree.remove(7);
	// tree.remove(8);
	// tree.remove(9);
	// tree.remove(10);

	// tree.print();

	return 0;
}
