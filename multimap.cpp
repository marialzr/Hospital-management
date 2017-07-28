#include "multimap.h"
using namespace std;

MultiMap::MultiMap()
{
	this->T = new string[N];
	this->V = new TElem[N];
	this->m = M;
	for (int i = 0; i < this->m; i++)
	{
		this->T[i] = "";
		this->V[i].value = "";
		this->V[i].deleted = false;
	}
}

int MultiMap::hashCodeFunction(std::string k, int i)
{
	int k2 = 0;
	int v[10] = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 }; //replace the value of number
	for (int i = 0; i < 13; i++)
	{
		int c = k[i] - '0';
		k2 += i*v[c];
	}
	return k2;
}

int MultiMap::hashFunction(std::string k, int i)
{
	int k2 = this->hashCodeFunction(k, i);
	return (k2 + i+3*i*i) % m;
}



void MultiMap::resize()
{
	this->m = this->m * 2;
	TElem *newElems = new TElem[this->m];
	std::string *newpos = new string[this->m];
	for (int i = 0; i < this->m / 2; i++)
	{
		newElems[i].value=this->V[i].value;
		newElems[i].deleted=this->V[i].deleted;
		newpos[i] = this->T[i];
	}
	this->V = newElems;
	this->T = newpos;
}

int MultiMap::search(std::string key, std::string v)
{
	int i = 0;
	int ok = -1;
	int pos = this->hashFunction(key, i);
	if (this->V[pos].value == v && this->T[pos] == key && this->V[pos].deleted == false)
		ok = pos;

	while (i < this->m && this->T[pos] != "" && ok == -1)
	{
		if (this->V[pos].value == v && this->T[pos] == key && this->V[pos].deleted == false)
			ok = pos;
		pos = this->hashFunction(key, i);
		i++;
	}
	return ok;
}


bool MultiMap::add(string key, string value)
{
	int pos = this->hashFunction(key, 0);
	int i = 0;
	while (i < this->m && this->T[pos] != "")
	{
		if (this->T[pos] == key && this->V[pos].value == value && this->V[pos].deleted==false)
			return false;
		int j = 1;
		if (this->T[pos] != "" && this->V[pos].deleted == true)
		{
			int ok = 0;
			int p = this->hashFunction(key, 1);
			while (this->T[p] != "" && j<this->m)
			{
				if (this->V[p].deleted == false)
					ok = 1;
				j++;
				p = this->hashFunction(key, j);
			}
			if (ok == 0)// it means that we rmeoved all values specific to a key and we can reuse this
			{
				this->T[pos] = key;
				this->V[pos].value=value;
				this->V[pos].deleted=false;
				return true;
			}
		}
		i = i + 1;
		pos = this->hashFunction(key, i);
	}
	if (i == this->m)
	{
		this->resize();
		while (i < this->m && this->T[pos] != "")
		{
			i = i + 1;
			pos = this->hashFunction(key, i);
		}
	}
	this->T[pos] = key;
	this->V[pos].value=value;
	this->V[pos].deleted=false;
	return true;
}

bool MultiMap::remove(string key, string value)
{
	int p = this->hashFunction(key, 0);
	int i = 0;
	while (i < this->m && this->T[p] != "")
	{
		if (this->T[p] == key && this->V[p].value == value)
		{
			this->V[p].deleted=true;
			TElem V = this->V[p];
			return true;
		}
		i = i + 1;
		p = this->hashFunction(key, i);
	}
	return false;
}

int MultiMap::size()
{
	int nr = 0;
	for (int i = 0; i < this->m; i++)
	{
		if (this->T[i] != "" && this->V[i].deleted == false)
			nr++;
	}
	return nr;
}

MultiMapIterator * MultiMap::iterator()
{
	return new MultiMapIterator(this);
}