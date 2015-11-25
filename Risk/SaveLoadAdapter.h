#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
#include "SaveLoadFormat.h"

using namespace std;

class SaveLoadAdapter: SaveLoadFormat
{
	public:
		static Map SaveLoadAdapter::readMap(string);
		static void SaveLoadAdapter::saveMap(string, Map);
};