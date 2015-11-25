#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
#include "SaveLoadFormat.h"

using namespace std;

class SaveLoadMapComponent: SaveLoadFormat
{
	public:
		static Map SaveLoadMapComponent::readMap(string);
		static void SaveLoadMapComponent::saveMap(string, Map);
};