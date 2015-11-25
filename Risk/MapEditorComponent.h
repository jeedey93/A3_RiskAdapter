#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class MapEditorComponent
{
public:
	static Map CreateMap();
	static Map AddContinentAndTerritories(Map, string, int);
	static Map AddTerritory(Map);
	static Map EditMap(Map);
	static Map EditContinents(Map);
	static Map EditTerritories(Map);
	static bool ValidateMap(Map);
	static Map AddAdjacentEquivalent(Map, string, Country*);
	static Map DeleteAdjacentEquivalent(Map, string, string);
};