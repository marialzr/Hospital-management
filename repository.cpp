#include "repository.h"

Hospital::Hospital(MultiMap * m, MultiMapIterator * mi)
{
	this->mm = m;
	this->mmIterator = mi;
}

Hospital::~Hospital()
{
	delete[] mm;
	delete[] mmIterator;
}

bool Hospital::addDisease(std::string CNP, std::string d)
{
	bool ok=this->mm->add(CNP, d);
	return ok;
}

bool Hospital::removeDisease(std::string CNP, std::string d)
{
	int p = this->mm->search(CNP, d);
	if (p == -1)
		return false;
	bool ok = this->mm->remove(CNP, d);
	return ok;
}

bool Hospital::hasSpecificDisease(std::string CNP, std::string d)
{
	bool ok = this->mm->search(CNP, d);
	return ok;
}
std::string Hospital::diseasesOfAPatient(std::string CNP)
{
	std::string result;
	MultiMapIterator* mit = new MultiMapIterator(this->mm);
	this->mmIterator = mit;
	while (this->mmIterator->valid())
	{
		std::string pos = this->mmIterator->getCurrentKey();
		if (pos == CNP)
			result = result +" "+ this->mmIterator->getCurrent();
		this->mmIterator->next();
	}
	delete[] mit;
	return result;
}
