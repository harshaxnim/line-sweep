// planeSweeper.h

#ifndef PLANESWEEPER_H
#define PLANESWEEPER_H

#include "bbst.h"
#include "node.h"

class planeSweeper
{
public:
	planeSweeper(){ eventQueue = new bbst(); sweepLineStatus = new bbst(); };
	planeSweeper(float val){ eventQueue = new bbst(val); sweepLineStatus = new bbst(val); };

	bbst* eventQueue = nullptr;
	bbst* sweepLineStatus = nullptr;

	static void eventHandler(const node& callingNode);

	typedef struct hoard
	{
		
	} hoard;
};

#endif