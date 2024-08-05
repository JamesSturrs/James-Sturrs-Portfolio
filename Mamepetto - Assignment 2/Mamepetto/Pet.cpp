#include "Pet.h"
#include <iostream>
#include <string>
#include "Map.h"

void Pet::Eat()
{

	do
	{
		hunger = hunger + rand() % 40;
		bladder = bladder + rand() % 30;

		std::cout << name << " is eating" << std::endl;

	} while (hunger <= 70);

	if (hunger >= 71)
	{
		state = move;
	}
	//if (hunger >= 60)
	//{
		//Input();
	//}
	
}	// void Pet::Eat()

void Pet::Sleep()
{
	do
	{
		tiredness = tiredness + rand() % 40;

		std::cout << name << " is resting" << std::endl;

	} while (PetSleep == true);

	if (PetSleep == false)
	{
		state = move;
	}

	//if (tiredness >= 30)
	//{
		//Input();
	//}
	
}	// void Pet::Sleep()

void Pet::Toilet()
{
	do
	{
		bladder = bladder - rand() % 20;

		std::cout << name << " is using the toilet" << std::endl;

	} while (PetToilet == true);
	//Input();

	if (PetToilet == false)
	{
		state = move;
	}

}	// void Pet::Toilet()

void Pet::Move()
{

	std::cout << name << " is moving around" << std::endl;

	if (hunger <= 30)
	{
		state = eat;
	}
	
	if (PetToilet == true)
	{
		state = toilet;
	}
	
	if (PetSleep == true)
	{
		state = sleep;
	}

	if (hunger <= 0)
	{
		state = dead;
	}
	else if (hunger >= 201)
	{
		state = dead;
	}
	else if (tiredness <= 0)
	{
		state = dead;
	}
	else if (tiredness >= 201)
	{
		state = dead;
	}
	else if (bladder >= 100)
	{
		state = dead;
	}
	else if (bladder <= -1)
	{
		state = dead;
	}

}	// void Pet::Move()

void Pet::Dead()
{
	std::cout << "<(X.X)>" << std::endl << std::endl;

	std::cout << name << " has died! Press any button to quit" << std::endl;

	system("Pause");

	exit(0);

}	// void Pet::Dead()

Pet::Pet(std::string _name)
{
	_name = name;
	
	tiredness = 100;
	hunger = 150;
	bladder = 0;

}	// Pet::Pet(std::string _name)

void Pet::UpdatePet()
{
	hunger--;
	tiredness--;
	bladder++;

	Mamepetto();
	DisplayStats();
	//Input();

}	//void Pet::UpdatePet()

int Pet::Mamepetto()
{
	int petCount = 0;

	switch (state)
	{
	case move:
		Move();
		break;

	case eat:
		Eat();
		break;

	case sleep:
		Sleep();
		break;

	case dead:
		Dead();
		break;

	case toilet:
		Toilet();
		break;

	}

	return petCount;

}	// int Pet::Mamepetto()

void Pet::PlayMenu()
{
	std::cout << "Play Menu" << std::endl;
	std::cout << "*********" << std::endl;
	std::cout << "M - Move" << std::endl;
	std::cout << "E - Eat" << std::endl;
	std::cout << "S - Sleep" << std::endl;
	std::cout << "T - Toilet" << std::endl;
	std::cout << "Q - Quit" << std::endl;

}	// void Pet::PlayMenu()

void Pet::Input()
{
	char choice;

	PlayMenu();

	choice = toupper(_getwch());

		
		if (choice == 'M')
		{
			Move();
		}
		else if (choice == 'E')
		{
			Eat();
		}
		else if (choice == 'S')
		{
			Sleep();
		}
		else if (choice == 'T')
		{
			Toilet();
		}
		else if (choice == 'Q')
		{
			exit(0);
		}
		

}	// void Pet::Input()

void Pet::DisplayStats()
{
	std::cout << "Hunger = " << hunger << std::endl;
	std::cout << "Tiredness = " << tiredness << std::endl;
	std::cout << "Bladder = " << bladder << std::endl;
	std::cout << "Name = " << name << std::endl;

}	// void Pet::DisplayStats()