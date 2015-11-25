#ifndef HEADER_PLAYER
#define HEADER_PLAYER

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Country.h"
#include "Continent.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::find;

class Player{
	
	private:
		vector<Country*> countryList;
		vector<Continent*> continentList;
		int playerNumber;
		int infantryCardCount;
		int cavalryCardCount;
		int artilleryCardCount;
		int cardReinforcementNumber;
		int battlesWon;
	public: 
		//Constructor
		Player(int playerNumber);
		~Player();
		
		//Methods
		vector<Country*> getCountriesAttackable();
		void addCountry(Country* country);
		void removeCountry(Country* country);
		void addContinent(Continent* continent);
		void removeContinent(Continent* continent);

		//Card Methods

		//Used at end of a player's turn if they have conquered a country
		void randomlyAssignCards();
		void takeAllCards(Player* player);
		int tradeCardsforArmy(string type);
		bool checkCardTradeAvailable();
		int getContinentTotalUnitValue();

		//Getters and Setters for variables
		int getPlayerNumber();
		void setPlayerNumber(int playerNumber);

		int getInfantryCardCount();
		void setInfantryCardCount(int infantryCardCount);

		int getCavalryCardCount();
		void setCavalryCardCount(int cavalryCardCount);

		int getArtilleryCardCount();
		void setArtilleryCardCount(int artilleryCardCount);

		int getCardReinforcementNumber();
		void setCardReinforcementNumber(int cardReinforcementNumber);

		int getBattlesWon();
		void setBattlesWon(int battlesWon);

		int getTotalNumberOfCards();

		vector<Country*> getCountryList();
		vector<Continent*> getContinentList();
};

#endif