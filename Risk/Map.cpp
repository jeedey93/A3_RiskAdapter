#include "Map.h"


Map::Map(void)
{
}


Map::~Map(void)
{
}

Map::Map(string author,string image, bool wrap, string scroll, bool warn)
{
	this->author = author;
	this->image = image;
	this->wrap = wrap;
	this->image = image;
	this->scroll = scroll;
	this->warn = warn;
}

string Map::getAuthor(){
	return this->author;
}

void Map::setAuthor(string author){
	this->author = author;
}

string Map::getImage(){
	return this->image;
}

void Map::setImage(string image){
	this->image = image;
}

bool Map::getWrap(){
	return this->wrap;
}

void Map::setWrap(bool wrap){
	this->wrap = wrap;
}

string Map::getScroll(){
	return this->scroll;
}

void Map::setScroll(string scroll){
	this->scroll = scroll;
}

bool Map::getWarn(){
	return this->warn;
}

void Map::setWarn(bool warn){
	this->warn = warn;
}