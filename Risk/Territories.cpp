#include "Territories.h"


Territories::Territories(void)
{
}


Territories::~Territories(void)
{
}

Territories::Territories(string name, double latitude, double longitude, string continent, vector<string> adjacentTerritories)
{
	this->name = name;
	this->latitude = latitude;
	this->longitude = longitude;
	this->continent = continent;
	this->adjacentTerritories = adjacentTerritories;
}

string Territories::getName(){
	return this->name;
}

void Territories::setName(string name){
	this->name=name;
}

double Territories::getLatitude(){
	return this->latitude;
}

void Territories::setLatitude(double latitude){
	this->latitude=latitude;
}

double Territories::getLongitude(){
	return this->longitude;
}

void Territories::setLongitude(double longitude){
	this->longitude=longitude;
}

string Territories::getContinent(){
	return this->continent;
}

void Territories::setContinent(string continent){
	this->continent=continent;
}

int Territories::getArmySize(){
	return this->armySize;
}

void Territories::setArmySize(int armySize){
	this->armySize = armySize;
}

int Territories::getOwner(){
	return this->owner;
}

void Territories::setOwner(int owner){
	this->owner = owner;
}
