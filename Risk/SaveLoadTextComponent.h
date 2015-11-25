#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
#include "SaveLoadFormat.h"

using namespace std;

class SaveLoadTextComponent: SaveLoadFormat
{
	public:
		static Map SaveLoadTextComponent::readMap(string);
		static void SaveLoadTextComponent::saveMap(string, Map);
};