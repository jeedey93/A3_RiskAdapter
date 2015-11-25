#include "Player.h"

//Constructor
Player::Player(int playerNumber){
	this->playerNumber = playerNumber;
	this->artilleryCardCount = 3;
	this->cavalryCardCount = 1;
	this->infantryCardCount = 1;
	//This is used to keep track of how many reinforcments a player would get when the trade in their cards
	this->cardReinforcementNumber = 5;
	this->battlesWon = 0;
}

Player::~Player(){
	/*//Deleting Countries
	for(int i=0; i < (int)countryList.size(); i++){
		delete countryList.at(i);
	}
	countryList.clear();*/
}

//Methods

void Player::addCountry(Country* country){
	countryList.push_back(country);
}

void Player::removeCountry(Country* country){
	for(int i=0; i < (int)countryList.size(); i++){
		if(countryList.at(i) == country){
			countryList.erase(countryList.begin() + i);
			break;
		}
	}
}

void Player::addContinent(Continent* continent){
	continentList.push_back(continent);
}

void Player::removeContinent(Continent* continent){
	for(int i=0; i < (int)continentList.size(); i++){
		if(continentList.at(i) == continent){
			continentList.erase(continentList.begin() + i);
			break;
		}
	}
}

void Player::randomlyAssignCards(){

	int randomResult = (rand() % 3 + 1);
	
	if(randomResult == 1){
		infantryCardCount++;
		cout << "Added an infantry card to Player " << this->getPlayerNumber() << endl;
	} else if (randomResult == 2){
		artilleryCardCount++;
		cout << "Added an artillery card to Player " << this->getPlayerNumber() << endl;
	} else {
		cavalryCardCount++;
		cout << "Added a cavalry card to Player " << this->getPlayerNumber() << endl;
	}
}

void Player::takeAllCards(Player* player){

	//Moving all the dead player's card to the current player's cards.
	this->infantryCardCount = this->infantryCardCount + player->getInfantryCardCount();
	this->artilleryCardCount = this->artilleryCardCount + player->getArtilleryCardCount();
	this->cavalryCardCount = this->cavalryCardCount + player->getCavalryCardCount();

	//Setting the dead players card count to empty
	player->setInfantryCardCount(0);
	player->setArtilleryCardCount(0);
	player->setCavalryCardCount(0);

}

int Player::getContinentTotalUnitValue(){
	
	int returnValue = 0;

	for(int i=0; i < (int)continentList.size(); i++){
		returnValue = returnValue + continentList.at(i)->getUnit();
	}

	return returnValue;
}

int Player::tradeCardsforArmy(string type){
	//Trade the cards away, return the current card ReinforcementNumber, increase cardReinforcementNumber by 5
	if(type.compare("cavalry") == 0){
		cavalryCardCount = cavalryCardCount - 3;	
	} else if (type.compare("artillery") == 0){
		artilleryCardCount = artilleryCardCount - 3;
	} else if (type.compare("infantry") == 0){
		infantryCardCount = infantryCardCount - 3;
	} else if (type.compare("all") == 0){
		cavalryCardCount--;
		artilleryCardCount--;
		infantryCardCount--;
	} else {
		//Should not be accessible
	}
	int returnCardReinforcementValue = cardReinforcementNumber;
	//Increment the reinforcement value for trading in cards
	cardReinforcementNumber = cardReinforcementNumber + 5;
	return returnCardReinforcementValue;
}

vector<Country*> Player::getCountriesAttackable(){

	vector<Country*> attackableCountries;

	//Iterated through all the countries currently in the list
	for(int i=0; i < (int)countryList.size(); i++){
		//Iterate through all the bordering countries for that individual country
		for(int j=0; j < (int)countryList.at(i)->getBorderingCountries().size(); j++){
			//Check inside each of those countries and if the player number != player AND border name not inside returnedCountry -> add it to the returned Country AND countryList greater than 1
			if(countryList.at(i)->getBorderingCountries().at(j)->getOwner() != this->getPlayerNumber() && 
			   find(attackableCountries.begin(), attackableCountries.end(), countryList.at(i)->getBorderingCountries().at(j)) == attackableCountries.end() &&
			   countryList.at(i)->getArmySize() > 1){
				   attackableCountries.push_back(countryList.at(i)->getBorderingCountries().at(j));
			}
		}
	}

	return attackableCountries;

}

//Getters and Setters
int Player::getPlayerNumber(){
	return this->playerNumber;
}

vector<Country*> Player::getCountryList(){
	return this->countryList;
}

vector<Continent*> Player::getContinentList(){
	return this->continentList;
}

void Player::setPlayerNumber(int playerNumber){
	this->playerNumber = playerNumber;
}

int Player::getInfantryCardCount(){
	return this->infantryCardCount;
}

void Player::setInfantryCardCount(int infantryCardCount){
	this->infantryCardCount = infantryCardCount;
}

int Player::getCavalryCardCount(){
	return this->cavalryCardCount;
}

void Player::setCavalryCardCount(int cavalryCardCount){
	this->cavalryCardCount = cavalryCardCount;
}

int Player::getArtilleryCardCount(){
	return this->artilleryCardCount;
}

void Player::setArtilleryCardCount(int artilleryCardCount){
	this->artilleryCardCount = artilleryCardCount;
}

int Player::getCardReinforcementNumber(){
	return this->cardReinforcementNumber;
}

void Player::setCardReinforcementNumber(int cardReinforcementNumber){
	this->cardReinforcementNumber = cardReinforcementNumber;
}

int Player::getBattlesWon(){
	return this->battlesWon;
}

void Player::setBattlesWon(int battlesWon){
	this->battlesWon = battlesWon;
}

int Player::getTotalNumberOfCards(){
	int total = this->infantryCardCount + this->artilleryCardCount + this->cavalryCardCount;
	return total;
}

bool Player::checkCardTradeAvailable(){
	if(this->infantryCardCount >= 3 || this->artilleryCardCount >= 3 || this->cavalryCardCount >= 3){
		//Has a combination of 3 cards
		return true;
	} else if(this->infantryCardCount > 0 && this->artilleryCardCount > 0 && this->cavalryCardCount > 0){
		//Has one of each card
		return true;
	} else {
		return false;
	}
}





