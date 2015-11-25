#include "Continent.h"


Continent::Continent(void)
{
}

Continent::Continent(string name,int unit)
{
	this->name = name;
	this->unit = unit;
}

Continent::~Continent(void)
{
}

string Continent::getName(){
	return this->name;
}

void Continent::setName(string name){
	this->name=name;
}

int Continent::getUnit(){
	return this->unit;
}

void Continent::setUnit(int unit){
	this->unit=unit;
}

