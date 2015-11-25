#pragma once
#include <iostream>
#include <vector>
#include "Continent.h"
using namespace std;

class Map
{
public:
	Map(void);
	~Map(void);
	Map::Map(string,string, bool, string, bool);
	string getAuthor();
	void setAuthor(string);
	string getImage();
	void setImage(string);
	bool getWrap();
	void setWrap(bool);
	string getScroll();
	void setScroll(string);
	bool getWarn();
	void setWarn(bool);
	vector<Continent> Continents;
private:
	string author;
	string image;
	bool wrap;
	string scroll;
	bool warn;
};

