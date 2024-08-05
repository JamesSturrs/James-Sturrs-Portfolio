#include "Map.h"
#include <iostream>

int x;
int y;

Map::Map()
{
	ResetMap();
}

void Map::DisplayMap()
{
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			std::cout << mapChar[row][column];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::MapCoords()
{
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			std::cout << "[" << row << "," << column << "] ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::UpdateMap()
{
	ResetMap();
	//MapCoords();
	//std::cout << x << std::endl << y;
	x = rand() % 5;
	y = rand() % 10;

	if (x == 2)
	{
		if (y >= 5, y <= 6)
		{
			std::cout << "Found Bed" << std::endl;
			InBed = true;
		}
	}
	else
	{
		InBed = false;
	}
	
	if (x == 4)
	{
		if (y == 1)
		{
			std::cout << "Found Toilet" << std::endl;
			Toilet = true;
		}
	}
	else
	{
		Toilet = false;
	}


	mapChar[x][y] = (char)254;
	BedDisplay();
	ToiletDisplay();
	DisplayMap();

}

void Map::ResetMap()
{
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			mapChar[row][column] = (char)176;
		}
	}
}

void Map::ToiletDisplay()
{
	mapChar[4][1] = (char)53;
}

void Map::BedDisplay()
{
	mapChar[2][5] = (char)45;
	mapChar[2][6] = (char)45;
}