#ifndef HEADER_COUNTRY
#define HEADER_COUNTRY

#include <string>
#include <vector>
//#include "Player.h"

using std::string;
using std::vector;

class Country{
	
	private:
		//Variables
		static int numberOfCountries;
		string name;
		int owner;
		int armySize;
		vector<Country*> borderingCountries;
		double latitude;
		double longitude;
		string continent;

	public: 
		//Constructor
		Country();
		Country(string name);
		Country(string, double, double, string, vector<Country*>);
		~Country();

		//Methods
		void addBorderingCountry(Country* country);

		
		//Getters and Setters
		static int getNumberOfCountries();
		string getName();
		int getOwner();
		int getArmySize();
		vector<Country*> getBorderingCountries();
		void setBorderingCountries(vector<Country*> c);
		void setName(string n);
		void setOwner(int owner);
		void setArmySize(int armySize);
		double getLatitude();
		void setLatitude(double);
		double getLongitude();
		void setLongitude(double);
		string getContinent();
		void setContinent(string);
};

#endif