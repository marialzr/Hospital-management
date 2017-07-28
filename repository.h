#pragma once
#include "multimap.h"
class Hospital
{
private:
	MultiMap *mm;
	MultiMapIterator* mmIterator;

public:
	/*
	create a new instance of class Hospital
	input: m:MultiMap, mi:MultimapIterator
	output: -
	*/
	Hospital(MultiMap* m, MultiMapIterator* mi);
	/*
	destroy an instance of Hospital
	input: -
	output: -
	*/
	~Hospital();
	/*
	add a disease to a patient
	input: the CNP of the patient
	output: true if it was successfully added
			false otherwise
	*/
	bool addDisease(std::string CNP, std::string d);
	/*
	remove a disease to a patient
	input: the CNP of the patient
	output: true if it was successfully removed
			false otherwise
	*/
	bool removeDisease(std::string CNP, std::string d);

	//int noAllDiseasesOfAllPatients();

	/*
	verifies if a patient with CNP=CNP have the disease=d
	input: CNP:string - the cnp of patient, d:string - the disease
	output: true if the patient has this disease
			false otherwise
	*/
	bool hasSpecificDisease(std::string CNP, std::string d);

	/*
	returns the list with all diseases of a patient
	input: the patient's CNP- a string
	output: a string containing all diseases
	*/
	std::string diseasesOfAPatient(std::string CNP);
};
