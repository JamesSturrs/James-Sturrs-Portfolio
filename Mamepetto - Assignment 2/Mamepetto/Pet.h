#pragma once
#include <string>

class Pet
{
	enum PetState
	{
		move,
		eat,
		sleep,
		dead,
		toilet
	};

private:
	int hunger;
	int bladder;
	int tiredness;
	std::string name;

	PetState state;

	void Eat();
	void Sleep();
	void StatUpdate();
	void StateCheck();
	void Dead();
	void Toilet();
	int PosX();
	int PosY();
	void Move();
	void Input();
	void PlayMenu();
	

public:
	Pet(std::string _name);

	void UpdatePet();
	int PetDead = 0;
	int Mamepetto();
	void DisplayStats();
	bool PetSleep;
	bool PetToilet;

};


