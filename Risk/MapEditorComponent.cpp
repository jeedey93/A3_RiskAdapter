#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
#include <sstream>
#include "MapEditorComponent.h"

using namespace std;

//This function is call when the user add a territory A to the list of adjacent territories of a territory B. This function
//will find the territory A that has been added and will add the territory B to his list of adjacent territories.
Map MapEditorComponent::AddAdjacentEquivalent(Map map, string adjacency, Country* ownTerritory){
	vector<Continent> continentList = map.Continents;
	for (int i = 0; i < continentList.size(); i++){
		vector<Country*> territoryList = continentList.at(i).Country;
		for (int j = 0; j < territoryList.size(); j++){
			if (territoryList.at(j)->getName() == adjacency){
				vector<Country*> adjacencyList = territoryList.at(j)->getBorderingCountries();
				adjacencyList.push_back(ownTerritory);
				territoryList.at(j)->setBorderingCountries(adjacencyList);
			}
		}
		continentList.at(i).Country = territoryList;
	}
	map.Continents=continentList;
	return map;
}

//This function is call when the user remove a territory A from the list of adjacent territories of a territory B. This function
//will find the territory A that has been removed and will remove the territory B from his list of adjacent territories.
Map MapEditorComponent::DeleteAdjacentEquivalent(Map map, string adjacency, string ownTerritory){
	vector<Continent> continentList = map.Continents;
	for (int i = 0; i < continentList.size(); i++){
		vector<Country*> territoryList = continentList.at(i).Country;
		for (int j = 0; j < territoryList.size(); j++){
			if (territoryList.at(j)->getName() == adjacency){
				vector<Country*> adjacencyList = territoryList.at(j)->getBorderingCountries();
				for (int k = 0; k < adjacencyList.size(); k++){
					if (adjacencyList.at(k)->getName() == ownTerritory){
						adjacencyList.erase(adjacencyList.begin() + k);
					}
				}
				territoryList.at(j)->setBorderingCountries(adjacencyList);
			}
		}
		continentList.at(i).Country= territoryList;
	}
	map.Continents = continentList;
	return map;
}

Map MapEditorComponent::CreateMap(){
	string author;
	string image;
	string wrap;
	string scroll;
	string warn;
	Map map;

	//PROMPTS USER FOR ALL ATTRIBUTES OF MAP
	cout << "What is the author's name?" << endl;
	cin >> author;

	cout << "What is the image's extension?" << endl;
	cin >> image;

	cout << "Is the map wrap?[Y/N]" << endl;
	cin >> wrap;

	cout << "Is the map vertical or horizontal?[Y/H]" << endl;
	cin >> scroll;

	cout << "Is the map warn?[Y/N]" << endl;
	cin >> warn;

	map = Map(author, image, wrap=="Y"?true:false, scroll, warn=="Y"?true:false);
	return map;
}

Map MapEditorComponent::EditMap(Map map){
	//PROMPTS USER FOR DIFFERENT STUFF TO EDIT
	string modification="";
	while (modification != "0"){
		cout << "What would you like to edit ?[1,2,3,4,5] 0 to exit" << endl;
		cout << "1 - Author's Name " << endl;
		cout << "2 - Image's Filename " << endl;
		cout << "3 - Map's Wrap " << endl;
		cout << "4 - Map's Scroll " << endl;
		cout << "5 - Map's Warn " << endl;
		cout << "0 - Exit" << endl;
		cin >> modification;

		if (modification == "1"){
			cout << "This is the author's name:" << map.getAuthor() << endl;
			cout << "Input a new author's name or skip" << endl;
			cin.ignore();
			getline(cin,modification);

			if (modification != "skip"){
				map.setAuthor(modification);
			}
		}
		else if (modification == "2"){
			cout << "This is the image's filename:" << map.getImage() << endl;
			cout << "Input a new image's filename or skip" << endl;
			cin.ignore();
			getline(cin, modification);

			if (modification != "skip"){
				map.setImage(modification);
			}
		}
		else if (modification == "3"){
			cout << "This is the map's wrap:" << map.getWrap() << endl;
			cout << "Input a new map's wrap or skip" << endl;
			cin.ignore();
			getline(cin, modification);

			if (modification != "skip"){
				map.setWrap(modification == "true" ? true : false);
			}
		}
		else if (modification == "4"){
			cout << "This is the map's scroll:" << map.getScroll() << endl;
			cout << "Input a new map's scroll or skip" << endl;
			cin.ignore();
			getline(cin, modification);

			if (modification != "skip"){
				map.setScroll(modification);
			}
		}
		else if (modification == "5"){
			cout << "This is the map's warn:" << map.getWarn() << endl;
			cout << "Input a new map's warn or skip" << endl;
			cin.ignore();
			getline(cin, modification);

			if (modification != "skip"){
				map.setWarn(modification == "true" ? true : false);
			}
		}
		else{
			break;
		}
	}
	return map;
}

Map MapEditorComponent::EditContinents(Map map){
	//PROMPS USER TO DECIDE WHICH CONTINENT TO EDIT
	string updateContinentNumber;
	cout << "Which continents would you like to edit ? Type exit otherwise" << endl;
	for (int i = 0; i < map.Continents.size(); i++)
	{
		cout << i + 1 << "- " << map.Continents[i].getName() << endl;
	}
	cin >> updateContinentNumber;
	while (updateContinentNumber != "exit"){
		string modification = "";
		while (modification != "0"){
			//ONCE CONTINENT CHOSEN, THE USER CAN MODIFY ANY FIELDS FROM IT
			cout << "What would you like to edit ?[1,2] 0 to exit" << endl;
			cout << "1 - Continent's Name " << endl;
			cout << "2 - Continent's Maximum Number of Units " << endl;
			cout << "0 - Exit" << endl;
			cin >> modification;
			if (modification == "1"){
				cout << "This is the continents's name:" << map.Continents[stoi(updateContinentNumber) - 1].getName() << endl;
				cout << "Input a new continents's name or skip" << endl;
				cin.ignore();
				getline(cin, modification);

				if (modification != "skip"){
					map.Continents[stoi(updateContinentNumber) - 1].setName(modification);
				}
			}
			else if (modification == "2"){
				cout << "This is the continents's maximum number of units:" << map.Continents[stoi(updateContinentNumber) - 1].getUnit() << endl;
				cout << "Input a new continents's maximum number of units or skip" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[stoi(updateContinentNumber) - 1].setUnit(stoi(modification));
				}
			}
			else{
				break;
			}
		}
		//THE SYSTEM WILL KEEP ON GOING UNTIL THE USER TYPES EXIT
		cout << "Which continents would you like to edit ? Type exit otherwise" << endl;
		for (int i = 0; i < map.Continents.size(); i++)
		{
			cout << i + 1 << "- " << map.Continents[i].getName() << endl;
		}
		cin >> updateContinentNumber;
	}
	return map;
}

Map MapEditorComponent::EditTerritories(Map map){
	string updateTerritoryNumber;

	//THE SYSTEM PROMPS THE USER TO DECIDE WHICH TERRITORY HE WOULD LIKE TO EDIT
	for (int i = 0; i < map.Continents.size(); i++)
	{
		cout << "Which territory would you like to edit ? Type next or exit otherwise" << endl;
		cout << "These are the territories for " << map.Continents[i].getName() << endl;
		for (int j = 0; j < map.Continents[i].Country.size(); j++){
			cout << j + 1 << "- " << map.Continents[i].Country[j]->getName() << endl;
		}
		cin >> updateTerritoryNumber;
		if (updateTerritoryNumber == "exit"){
			break;
		}
		while (updateTerritoryNumber != "next"){
			//ONCE THE TERRITORY IS CHOSEN, THE USER WILL DECIDE WHICH ATTRIBUTE HE WILL MODIFY
			string modification;

			cout << "What would you like to edit ?[1,2,3,4,5] 0 to exit" <<  endl;
			cout << "1 - Name " << endl;
			cout << "2 - Latitude " << endl;
			cout << "3 - Longitude " << endl;
			cout << "4 - Continent " << endl;
			cout << "5 - Adjacent Territories " << endl;
			cout << "0 - Exit" << endl;
			cin >> modification;

			if(modification == "1"){
				cout << "This is the territory's name:" << map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getName() << endl;
				cout << "Input a new territory's name" << endl;
				cin.ignore();
				getline(cin, modification);

				if (modification != "skip"){
					map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->setName(modification);
				}
			}
			else if(modification == "2"){
				cout << "This is the territory's latitude:" << map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getLatitude() << endl;
				cout << "Input a new territory's latitude" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->setLatitude(stoi(modification));
				}
			}
			else if(modification == "3"){
				cout << "This is the territory's longitude:" << map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getLongitude() << endl;
				cout << "Input a new territory's longitude" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->setLongitude(stoi(modification));
				}
			}
			else if(modification == "4"){
				cout << "This is the territory's continent:" << map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getContinent() << endl;
				cout << "Input a new territory's continent" << endl;
				cin.ignore();
				getline(cin, modification);

				if (modification != "skip"){
					if (modification != map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getContinent()){
						
						for (int j = 0; j < map.Continents.size(); j++){

							//Add to new continent
							if (map.Continents[j].getName() == modification){
								map.Continents[j].Country.push_back(map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]);
							}
						}
						//Remove from old continent
						if (map.Continents[i].getName() == map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getContinent()){
							map.Continents[i].Country.erase(map.Continents[i].Country.begin() + stoi(updateTerritoryNumber) - 1);
						}

						map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->setContinent(modification);
					}
				}
			}
			else if (modification == "5"){
				cout << "This is the territory's adjacent countries:" << endl;
				for(int k=0;k< map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries().size();k++){
					cout << k+1 << "-" << map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries()[k]->getName() << endl;
				}

				//ADD AND REMOVE ADJACENT COUNTRIES
				cout << "Do you want to add or remove adjacent country?" << endl;
				cin >> modification;
				if(modification == "add"){
					cout << "Type the name of adjacent country you want to add" << endl;
					cin >> modification;
					
					bool adjacentExist = false;
					Country* c = new Country();
					for (int j = 0; j < map.Continents.size(); j++){
						for (int k = 0; k < map.Continents[j].Country.size(); k++){
							if (modification == map.Continents[j].Country[k]->getName()){
								c = map.Continents[j].Country[k];
								adjacentExist = true;
							}
						}
					}
					if (adjacentExist){
						map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries().push_back(c);
						map = MapEditorComponent::AddAdjacentEquivalent(map, modification, map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]);
					}
					else{
						cout << "Adjacent Territory doesn't exist, Please add one that already exists" << endl;
					}
				}
				else if(modification=="remove"){
					cout << "Type the name of adjacent country you want to remove" << endl;
					cin.ignore();
					getline(cin, modification);
					Country* c = new Country();
					for (int h = 0; h < map.Continents.size(); h++){
						for (int m = 0; m < map.Continents[h].Country.size(); m++){
							if (modification == map.Continents[h].Country[m]->getName()){
								c = map.Continents[h].Country[m];
							}
						}
					}
					for(int a=0;a< map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries().size();a++){
						if (map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries()[a]->getName() == c->getName()){
							map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries().erase(map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getBorderingCountries().begin()+a);
						}
					}
					map = MapEditorComponent::DeleteAdjacentEquivalent(map, modification, map.Continents[i].Country[stoi(updateTerritoryNumber) - 1]->getName());
				}
			}
			else if (modification == "0"){
				updateTerritoryNumber = "next";
			}
			else{ 
				break; 
			}
		}
	}
	return map;
}

bool MapEditorComponent::ValidateMap(Map map){
	vector<Continent> continentList = map.Continents;
	for (int i = 0; i < continentList.size(); i++){
		string continentName = continentList.at(i).getName();
		for (int j = i; j < continentList.size(); j++){
			if (continentName == continentList.at(j).getName()){
				if (i != j){
					return false;
				}
			}
		}
	}
	for (int i = 0; i < continentList.size(); i++){
		vector<Country*> territoryList = continentList.at(i).Country;
		for (int j = 0; j < territoryList.size(); j++){
			string territoryName = territoryList.at(j)->getName();
			for (int k = 0; k < continentList.size(); k++){
				for (int l = 0; l < territoryList.size(); l++){
					if (i != k && j != l){
						if (territoryName == territoryList.at(l)->getName()){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

Map MapEditorComponent::AddTerritory(Map map){
	string addTerritory;
	string territoryName;
	double latitude;
	double longitude;
	int territoryCount = 1;
	string adjacentTerritory;
	string continentName;

	//PROMPTS USER FOR EVERY DIFFERENT FIELD WHEN CREATING A TERRITORY
	cout << "Name your territory #" << territoryCount << endl;
	cin.ignore();
	getline(cin, territoryName);
	cout << "Please specify the latitude of " << territoryName << endl;
	cin >> latitude;
	cout << "Please specify the longitude of " << territoryName << endl;
	cin >> longitude;
	vector<Country*> adjacentTerritories;
	cout << "Please enter an adjacent territory or stop" << endl;
	cin.ignore();
	getline(cin, adjacentTerritory);

	Country* c = new Country();
	for (int i = 0; i < map.Continents.size(); i++){
		for (int j = 0; j < map.Continents[i].Country.size(); j++){
			if (adjacentTerritory == map.Continents[i].Country[j]->getName()){
				c = map.Continents[i].Country[j];
			}
		}
	}

	while (adjacentTerritory != "stop"){
		adjacentTerritories.push_back(c);
		cout << "Please enter an adjacent territory or stop" << endl;
		cin.ignore();
		getline(cin, adjacentTerritory);
		c = new Country();
		for (int i = 0; i < map.Continents.size(); i++){
			for (int j = 0; j < map.Continents[i].Country.size(); j++){
				if (adjacentTerritory == map.Continents[i].Country[j]->getName()){
					c = map.Continents[i].Country[j];
				}
			}
		}
	}
	cout << "Which continent do you want your territory to be added to?" << endl;
	getline(cin, continentName);

	//CHECK IF TERRITORY ALREADY EXIST
	bool territoryAlreadyExists = false;
	for (int i = 0; i < map.Continents.size(); i++){
		for (int j = 0; j < map.Continents[i].Country.size(); j++){
			if (map.Continents[i].Country[j]->getName() == territoryName)
				territoryAlreadyExists = true;
		}
	}
	if (territoryAlreadyExists == false)
	{
		Country* territory = new Country(territoryName, latitude, longitude, continentName, adjacentTerritories);
		for (int i = 0; i < map.Continents.size(); i++){
			if (map.Continents[i].getName() == continentName){
				map.Continents[i].Country.push_back(territory);
			}
		}
		for (int i = 0; i < adjacentTerritories.size(); i++){
			map = MapEditorComponent::AddAdjacentEquivalent(map, adjacentTerritories[i]->getName(), territory);
		}
	}
	else{
		cout << "Territory already exists, Please create a new one." << endl;
	}
	return map;
}

Map MapEditorComponent::AddContinentAndTerritories(Map map, string continentName, int continentUnitCount){
	string addTerritory;
	string territoryName;
	double latitude;
	double longitude;
	int territoryCount = 1;
	string adjacentTerritory;


	//CHECK IF CONTINENT ALREADY EXISTS
	bool continentAlreadyExists = false;
	for (int i = 0; i < map.Continents.size(); i++){
		if (map.Continents[i].getName() == continentName)
			continentAlreadyExists = true;
	}
	if (continentAlreadyExists == false){
		//PROMPTS THE USER TO CREATE TERRITORIES IN ADDITION TO HIS CONTINENT
		Continent continent = Continent(continentName, continentUnitCount);
		cout << "Do you want to add a territory to " << continentName << " ?" << endl;
		cin >> addTerritory;
		while (addTerritory == "yes"){
			cout << "Name your territory #" << territoryCount << endl;
			cin.ignore();
			getline(cin, territoryName);
			cout << "Please specify the latitude of " << territoryName << endl;
			cin >> latitude;
			cout << "Please specify the longitude of " << territoryName << endl;
			cin >> longitude;
			vector<Country*> adjacentTerritories;
			cout << "Please enter an adjacent territory or stop" << endl;
			cin >> adjacentTerritory;
			Country* c = new Country();
			for (int i = 0; i < map.Continents.size(); i++){
				for (int j = 0; j < map.Continents[i].Country.size(); j++){
					if (adjacentTerritory == map.Continents[i].Country[j]->getName()){
						c = map.Continents[i].Country[j];
					}
				}
			}
			while (adjacentTerritory != "stop"){
				adjacentTerritories.push_back(c);
				cout << "Please enter an adjacent territory or stop" << endl;
				cin.ignore();
				getline(cin, adjacentTerritory);
				c = new Country();
				for (int i = 0; i < map.Continents.size(); i++){
					for (int j = 0; j < map.Continents[i].Country.size(); j++){
						if (adjacentTerritory == map.Continents[i].Country[j]->getName()){
							c = map.Continents[i].Country[j];
						}
					}
				}
			}
			//CHECK IF TERRITORY ALREADY EXIST
			bool territoryAlreadyExists = false;
			for (int i = 0; i < map.Continents.size(); i++){
				for (int j = 0; j < map.Continents[i].Country.size(); j++){
					if (map.Continents[i].Country[j]->getName() == territoryName)
						territoryAlreadyExists = true;
				}
			}
			if (territoryAlreadyExists == false)
			{
				Country* c = new Country();
				for (int i = 0; i < map.Continents.size(); i++){
					for (int j = 0; j < map.Continents[i].Country.size(); j++){
						if (adjacentTerritory == map.Continents[i].Country[j]->getName()){
							c = map.Continents[i].Country[j];
						}
					}
				}
				Country* territory = new Country(territoryName, latitude, longitude, continentName, adjacentTerritories);
				continent.Country.push_back(territory);
				territoryCount++;
				cout << "Do you want to add a territory to " << continentName << " ?" << endl;
				cin >> addTerritory;
			}
			else{
				cout << "Territory already exists, Please create a new one." << endl;
			}
		}
		map.Continents.push_back(continent);
	}
	else{
		cout << "Continent already exists, Please create a new one." << endl;
	}
	return map;
}

