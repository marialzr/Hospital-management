#include "multimap.h"
#include <assert.h>
#include "tester.h"
void Tester::testHashFunction()
{
	MultiMap* mm = new MultiMap();
	int nr = mm->hashFunction("2970807042645", 1);
	assert(nr == 0);
}

void Tester::testResize()
{
	MultiMap* mm = new MultiMap();
	mm->resize();
	assert(mm->m = 169);
}

void Tester::testFunctions()
{
	MultiMap* mm = new MultiMap();

	int nr = mm->hashFunction("2970807042645", 1);
	assert(nr == 0);

	assert(mm->add("2970807042645", "disease1") == true);
	assert(mm->T[12] == "2970807042645");
	assert(mm->V[12].value == "disease1");
	assert(mm->V[12].deleted == false);
	assert(mm->add("2970807042645", "disease1") == false);

	assert(mm->search("2970807042645", "disease1") == 12);
	assert(mm->search("2970807021112", "disease2") == -1);

	assert(mm->size() == 1);

	assert(mm->remove("2970807021112", "disease2") == false);
	assert(mm->remove("2970807042645", "disease1") == true);

	assert(mm->add("2970807042645", "disease2") == true);
	assert(mm->add("2970807042645", "disease3") == true);
	assert(mm->add("2970807042645", "disease4") == true);
	assert(mm->search("2970807042645", "disease4") == 1);

	assert(mm->remove("2970807042645", "disease2") == true);
	assert(mm->remove("2970807042645", "disease3") == true);
	assert(mm->remove("2970807042645", "disease4") == true);

	assert(mm->add("2970807042645", "disease3") == true);

	assert(mm->add("2970807042645", "disease2") == true);
	assert(mm->add("2970807042645", "disease4") == true);

	assert(mm->remove("2970807042645", "disease2") == true);
	assert(mm->add("2970807042645", "disease4") == false);

	assert(mm->add("2970807042645", "disease1") == true);
	assert(mm->add("2970807042645", "disease2") == true);
	assert(mm->add("2970807042645", "disease5") == true);
	assert(mm->add("2970807042645", "disease6") == true);
	assert(mm->add("2970807042645", "disease7") == true);
	assert(mm->add("2970807042645", "disease8") == true);
	assert(mm->add("2970807042645", "disease9") == true);
	assert(mm->add("2970807042645", "disease10") == true);
	assert(mm->add("2970807042645", "disease11") == true);
	assert(mm->add("2970807042645", "disease12") == true);
	assert(mm->add("2970807042645", "disease13") == true);
	assert(mm->add("2970807042645", "disease14") == true);
	assert(mm->m == 26);
}

	