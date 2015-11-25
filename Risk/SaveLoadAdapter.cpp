#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
#include <sstream>
#include "SaveLoadAdapter.h"
#include "SaveLoadMapComponent.h"
#include "SaveLoadTextComponent.h"

using namespace std;

Map SaveLoadAdapter::readMap(string mapName){
	Map map;
	std::string extension = "";
	// find the last occurrence of '.'
	size_t pos = mapName.find_last_of(".");
	// make sure the position is valid
	if (pos != string::npos)
		extension = mapName.substr(pos+1);
	else
		std::cout << "Coud not find . in the string\n";
	if(extension.compare ("map") == 0){
		map = SaveLoadMapComponent::readMap(mapName);
	}
	else if(extension.compare ("txt") == 0){
		map = SaveLoadTextComponent::readMap(mapName);
	}
	return map;
}

void SaveLoadAdapter::saveMap(string saveMapName, Map map)
{
	std::string extension = "";
	// find the last occurrence of '.'
	size_t pos = saveMapName.find_last_of(".");
	// make sure the position is valid
	if (pos != string::npos)
		extension = saveMapName.substr(pos+1);
	else
		std::cout << "Coud not find . in the string\n";
	if(extension.compare ("map") == 0){
		SaveLoadMapComponent::saveMap(saveMapName, map);
	}
	else if(extension.compare ("txt") == 0){
		SaveLoadTextComponent::saveMap(saveMapName, map);
	}
}

