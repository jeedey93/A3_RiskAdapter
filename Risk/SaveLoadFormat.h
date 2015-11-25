#pragma once
#include <iostream>
#include "Map.h"
#include "Country.h"
using namespace std;

class SaveLoadFormat
{
public:
	virtual Map readMap(string) =0;
	virtual void saveMap(string, Map)=0;
};

