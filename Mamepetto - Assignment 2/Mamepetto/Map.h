#pragma once

class Map
{
private:

	char mapChar[5][10];

	void ResetMap();
	void MapCoords();
	void DisplayMap();
	void BedDisplay();
	void ToiletDisplay();
	
public:

	Map();

	void UpdateMap();
	bool Toilet;
	bool InBed;
};