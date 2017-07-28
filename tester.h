#pragma once
class Tester
{
	friend class MultiMap;
	friend class TElem;
public:
	void testHashFunction();
	void testResize();
	void testFunctions();
	void testIterator();
};
