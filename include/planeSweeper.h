// planeSweeper.h

#ifndef PLANESWEEPER_H
#define PLANESWEEPER_H

#include <iostream>

#include "bbst.h"
#include "node.h"

class planeSweeper
{
public:
	planeSweeper(){ eventQueue = new bbst(); sweepLineStatus = new bbst(); lineInfo = new bbst(); };
	planeSweeper(float val){ eventQueue = new bbst(val); sweepLineStatus = new bbst(val); lineInfo = new bbst(); };

	bbst* eventQueue = nullptr;
	bbst* sweepLineStatus = nullptr;
	bbst* lineInfo = nullptr;

	static void eventHandler(const node& callingNode);

	static node *prevNode;
	static node *thisNode;
	static node *nextNode;
	static int nodeTracker;
	static void adjacentNodesHelper(const node& callingNode);
	static void resetAdjacentNodesHelper();

	typedef struct hoard
	{
		typedef enum eventType
		{
			start,
			intersect,
			end
		} eventType;

		typedef struct coord
		{
			int x;
			int y;
		} coord;

		eventType eType;
		coord eCoord;
		int lineID;

		void print()
		{
			std::cout << "eType" << eType << std::endl;
			std::cout << "eCoord" << eCoord.x << ", " << eCoord.y << std::endl;
		};
	} hoard;
};

#endif