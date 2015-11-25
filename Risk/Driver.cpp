#include <iostream>
#include <string>
#include "Game.h"
#include "Map.h"
#include "MapEditorComponent.h"
#include "SaveLoadAdapter.h"
#include <sstream>

using namespace std;

int main(){

	//Map map = SaveLoadMapComponent::InitializeOptions();

	string loadMapName;
	string saveMapName;
	string createOrLoad;
	string addContinent;
	string continentName;
	int continentUnitCount;
	int continentCount = 1;
	bool boolCreateOrLoad = true;
	int componentEdit = 10;
	Map map;

	while (boolCreateOrLoad){
		cout << "Do you want to create or play or edit a map ?" << endl;
		cin >> createOrLoad;

		if (createOrLoad == "create"){
			map = MapEditorComponent::CreateMap();
			cout << "Do you want to add a continent?" << endl;
			cin >> addContinent;
			while (addContinent == "yes"){
				cout << "Name your continent #" << continentCount << endl;
				cin >> continentName;
				cout << "How many units can be contained in " << continentName << " ?" << endl;
				cin >> continentUnitCount;
				continentCount++;
				map = MapEditorComponent::AddContinentAndTerritories(map, continentName, continentUnitCount);
				cout << "Do you want to add a continent?" << endl;
				cin >> addContinent;
			}
			cout << "Enter the name of the map file you want to save it to" << endl;
			cin >> saveMapName;
			cout << "Checking map validity..." << endl;
			bool isValid = MapEditorComponent::ValidateMap(map);
			if (isValid){
				SaveLoadAdapter::saveMap(saveMapName, map);
				cout << "The map has been successfully saved !" << endl;
				boolCreateOrLoad = false;
			}
			else{
				cout << "The map is not valid, please fix it" << endl;
			}
			cout << "Creation Successfull" << endl;
			boolCreateOrLoad = false;
		}
		else if (createOrLoad == "edit"){
			cout << "Enter the name of the map file you want to load" << endl;
			cin >> loadMapName;
			map = SaveLoadAdapter::readMap(loadMapName);
			while (componentEdit != 0){
				cout << "What component would you like to edit ?" << endl;
				cout << "1 - Map" << endl;
				cout << "2 - Continents" << endl;
				cout << "3 - Territories" << endl;
				cout << "4 - Add a Continent" << endl;
				cout << "5 - Add a Territory" << endl;
				cout << "0 - Exit" << endl;
				cin >> componentEdit;
				switch (componentEdit){
				case 1:
					map = MapEditorComponent::EditMap(map);
					break;
				case 2:
					map = MapEditorComponent::EditContinents(map);
					break;
				case 3:
					map = MapEditorComponent::EditTerritories(map);
					break;
				case 4:
					cout << "Name your continent #" << continentCount << endl;
					cin >> continentName;
					cout << "How many units can be contained in " << continentName << " ?" << endl;
					cin >> continentUnitCount;
					map = MapEditorComponent::AddContinentAndTerritories(map, continentName, continentCount);
					break;
				case 5:
					map = MapEditorComponent::AddTerritory(map);
					break;
				default:
					break;
				}
			}
			cout << "Process of editing the map has finished" << endl;
			cout << "Enter the name of the map file you want to save it to" << endl;
			cin >> saveMapName;
			cout << "Checking map validity..." << endl;
			bool isValid = MapEditorComponent::ValidateMap(map);
			if (isValid){
				SaveLoadAdapter::saveMap(saveMapName, map);
				cout << "The map has been successfully saved !" << endl;
				boolCreateOrLoad = false;
			}
			else{
				cout << "The map is not valid, please fix it" << endl;
			}
		}
		else if (createOrLoad == "play"){
			cout << "Enter the name of the map file you want to load" << endl;
			cin >> loadMapName;
			map = SaveLoadAdapter::readMap(loadMapName);
			break;
		}
	}

	//Temporarily included to stop the game from proceeding
	int test;
	cin >> test;

	return 0;
}