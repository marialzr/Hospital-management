#pragma once
#include "repository.h"
class UI
{
private:
	Hospital* repo;
public:
	UI(Hospital* repo);
	~UI();
	void addDisease();
	void removeDisease();
	void noOfAllDiseases();
	std::string patientDisease();
	void run();
	
};