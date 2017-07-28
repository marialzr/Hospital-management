#include "ui.h"
#include <iostream>
#include "tester.h"
using namespace std;

UI::UI(Hospital * repo)
{
	this->repo = repo;
}

UI::~UI()
{
	delete[] this->repo;
}

void UI::run()
{
	while (1)
	{
		int cmd;
		cmd = -1;
		cout << "Choose a command:\n";
		cout << "0- Break\n";
		cout << "1- Add a patient that suffers by a disease\n";
		cout << "2- A pacient has been treated by a disease\n";
		cout << "3-Show all diseases of a patient\n";
		cin >> cmd;
		if (cmd == 1)
			addDisease();
		else if (cmd == 2)
			removeDisease();
		else if (cmd == 3)
			patientDisease();
		else if (cmd == 0)
			break;
	}
}

void UI::addDisease()
{
	string d, cnp;
	cout << "Give the CNP of patient\n";
	cin >> cnp;
	if (cnp.length() != 13)
	{
		cout << "Give a valid CNP\n";
		return;
	}
	cout << "Give the disease he suffer\n";
	cin >> d;
	bool ok = this->repo->addDisease(cnp, d);
	if (ok == true)
		cout << "The disease was successfully added!\n";
	else
		cout << "The disease already exist!\n";
}

void UI::removeDisease()
{
	string d, cnp;
	cout << "Give the CNP of patient\n";
	cin >> cnp;
	if (cnp.length() != 13)
	{
		cout << "Give a valid CNP\n";
		return;
	}
	cout << "Give the disease he suffered\n";
	cin >> d;
	bool ok = this->repo->removeDisease(cnp, d);
	if (ok == true)
		cout << "The disease was successfully removed!\n";
	else
		cout << "The disease does not exist!\n";
}

std::string UI::patientDisease()
{
	string cnp;
	cout << "Give the CNP\n";
	cin >> cnp;
	if (cnp.length() != 13)
	{
		cout << "Give a valid CNP\n";
		return "";
	}
	std::string s = this->repo->diseasesOfAPatient(cnp);
	if (s=="")
		cout << "The patient with code " << cnp << "is healthy"<< endl;
	else
		cout << "The patient with code " << cnp << " suffer by: " << s<<endl;
	return s;
}
