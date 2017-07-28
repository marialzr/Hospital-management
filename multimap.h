#pragma once
#define M 13
#define N 13
#include <string>

class MultiMapIterator;
class TElem
{
	friend class Tester;
	friend class MultiMap;
	friend class MultiMapIterator;
private:
	std::string value;
	bool deleted;
};

class MultiMap
{
	friend class MultiMapIterator;
	friend class Tester;
	friend class TElem;

private:
	int m; //capacity;
	TElem* V;
	std::string *T;
	int hashCodeFunction(std::string k, int i);
	/*
	recompute the capacity of the conainer
	input:-
	output:-
	*/
	void resize();
	/*
	compute a value representing the position
	input: key: string, i: integer
	outpu
	*/
	int hashFunction(std::string k, int i);
public:
	/*
	creates a new empty multimap
	input: -
	output: empty multimap
	*/
	MultiMap();


	/*
	verify if a pair <key, value> exists in container
	input: key:String; v:String
	output: an integer pos, being the position in the multimap
	*/
	int search(std::string key, std::string v);

	/*
	adds a new pair <key, value> to container
	input: key:string, value: string
	output: true - if the pair was successfully added
	false - otherwise
	*/
	bool add(std::string key, std::string value);

	/*
	remove a pair <key, value> to container
	input: key:string, value: string
	output: true - if the pair was successfully removed
	false - otherwise
	*/
	bool remove(std::string key, std::string value);

	/*
	returns the size of multimap
	input: -
	output: integer: size
	*/
	int size();
	MultiMapIterator* iterator();
};

class MultiMapIterator {
	friend class MultiMap;
	friend class MultiMapIterator;
private:
	int current;
	MultiMap* mm;

public:
	/*
	initialize an iterator for the multimap
	input: map:MultiMap
	output: MultimapIterator
	*/
	MultiMapIterator(MultiMap* map)
	{
		this->current = 0;
		this->mm = map;
	}


	/*
	gets the current value
	input: -
	output: the current value
	*/
	std::string getCurrent() {
		return this->mm->V[this->current].value;
	}

	/*
	gets the current key
	input: -
	output: the current key
	*/
	std::string getCurrentKey() {
		return this->mm->T[this->current];
	};

	/*
	gets a boolean variable which tells us if the element from the current position was removed or not
	input: -
	output: the boolean variable
	*/
	bool getDeleted()
	{
		return this->mm->V[this->current].deleted;
	}

	/*
	goes to the next element from the container
	input:-
	output:-
	*/
	void next() {
		current++;
		while (this->mm->V[this->current].deleted == true && this->current<this->mm->m)
			this->current++;
	}

	/*
	verify if the current position is a valid one
	input: -
	output: true if it is valid
	output: otherwise
	*/
	bool valid() {
		if (current < mm->m)
			return true;
		return false;
	}
} typedef MultiMapIterator;