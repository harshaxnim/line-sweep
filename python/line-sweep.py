#!/usr/bin/python

# line-sweep.py

from sortedcontainers import SortedDict



eventQueue = SortedDict()
sweepLineStatus = SortedDict()

inp = open("LineSegments.txt")


lines = []

for l in inp.readlines():
	lines.append(l)



class lsPoint:
	def __init__(self, x, y):
		self.x = x
		self.y = y

class lsLines:
	def __init__(self, lines):
		self.lines = lines

# eventQueue
# 	add all the line events in the sorted order.

# let's make a dictionary, key is the y axis, value is the lsEvent class instance
class lsEvent:
	# type can be left end point, intersection or right end point.
	# info can have the point, line id/id(s) if it's an intersection
	def __init__(self, lsType, lsInfo):
		self.type = lsType
		self.info = lsInfo
