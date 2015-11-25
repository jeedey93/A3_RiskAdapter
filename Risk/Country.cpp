#include "Country.h"

//Initializing the Number of Countries
int Country::numberOfCountries = 0;

//Constructors
Country::Country(){
	Country::numberOfCountries++;
}

Country::Country(string name){
	this->name = name;
	Country::numberOfCountries++;
}

Country::Country(string name, double latitude, double longitude, string continent, vector<Country*> adjacentTerritories)
{
	this->name = name;
	this->latitude = latitude;
	this->longitude = longitude;
	this->continent = continent;
	this->borderingCountries = adjacentTerritories;
}

Country::~Country(){
	//Deleting Countries
	/*for(int i=0; i < (int)borderingCountries.size(); i++){
		delete borderingCountries.at(i);
	}
	borderingCountries.clear();*/
}

//Methods
void Country::addBorderingCountry(Country* country){
	this->borderingCountries.push_back(country);
};

//Getters and Setters
int Country::getNumberOfCountries(){
	return numberOfCountries;
};

void Country::setContinent(string continent){
	this->continent = continent;
};

string Country::getContinent(){
	return this->continent;
};

string Country::getName(){
	return this->name;
};

void Country::setName(string n){
	this->name = n;
};

int Country::getOwner(){
	return this->owner;
};

int Country::getArmySize(){
	return this->armySize;
};

vector<Country*> Country::getBorderingCountries(){
	return this->borderingCountries;
};

void Country::setBorderingCountries(vector<Country*> c){
	this->borderingCountries = c;
};

void Country::setOwner(int owner){
	this->owner = owner;
}

void Country::setArmySize(int armySize){
	this->armySize = armySize;
}

double Country::getLatitude(){
	return this->latitude;
}

void Country::setLatitude(double latitude){
	this->latitude = latitude;
}

double Country::getLongitude(){
	return this->longitude;
}

void Country::setLongitude(double longitude){
	this->longitude = longitude;
}
