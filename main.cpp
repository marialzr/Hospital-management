#include "multimap.h"
#include "repository.h"
#include"ui.h"
#include "tester.h"
int main()
{
	/*
	Tester t;
	t.testHashFunction();
	t.testResize();
	t.testFunctions();
	t.testIterator();
	*/
	MultiMap* mp = new MultiMap();
	MultiMapIterator* mi = new MultiMapIterator(mp);
	Hospital* hp=new Hospital(mp, mi);
	UI* ui=new UI(hp);
	ui->run();
	return 0;
}