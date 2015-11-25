
#ifndef HEADER_GAME
#define HEADER_GAME

#include <iostream>
#include <vector>
#include <functional>
#include "Player.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Game{
	
	private:
		int numberOfPlayers;
		vector<Player*> players;
		vector<Country*> countries;
	public: 
		//Constructor
		Game();
		//Destructor
		~Game();

		//Methods
		void initialize(); //starting method to start a battle/game
		void printSummary();
		void printCardInformation(Player* player);
		void printBattleStatus(Country* attacker, Country* defender);
		void printPlayerCountryInformation(Player* player);
		void startGame();
		void reinforcementPhase(Player* player);
		bool battlePhase(vector<Player*> &tempPlayers, vector<Player*> &activePlayers);
		void fortificationPhase(Player* player);
		void nextTurn(vector<Player*> &tempPlayers, vector<Player*> &activePlayers);
		string battleBetweenCountries(Country* attacker, Country* defender);
		void cleanUp();

		//Getters/Setters
		int getNumberOfPlayers();
		void setNumberOfPlayers(int value);

};

#endif