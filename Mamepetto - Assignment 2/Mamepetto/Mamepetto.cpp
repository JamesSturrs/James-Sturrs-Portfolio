#include <iostream>
#include <thread>
#include <string>
#include <windows.h>

#include "Pet.h"
#include "Map.h"

void GamePause(int mSeconds);
void ClearScreen(int xpos, int ypos);
void StartGame();
void Name();

std::string MamepettoName;

Pet test = Pet(MamepettoName);
Map map;

int main()
{
	bool playGame = false;
    char choice;
    bool sleep = false;

    StartGame();
    Name();

    choice = toupper(_getwch());

    if (choice == 'Y')
    {
        
        playGame = true;
       
    }
    else if (choice == 'N')
    {
        StartGame();
        Name();
    }


    do
	{
        map.UpdateMap();

        if (map.InBed == true)
        {
            test.PetSleep = true;
        }
        else
        {
            test.PetSleep = false;
        }

        if (map.Toilet == true)
        {
            test.PetToilet = true;
        }
        else
        {
            test.PetToilet = false;
        }

        ClearScreen(0, 7);
        test.UpdatePet();

        GamePause(500);

        system("cls");

	}   while (playGame == true);

	system("Pause");

}	// int main()

void GamePause(int mSeconds)
{
	std::chrono::milliseconds dura(mSeconds);
	std::this_thread::sleep_for(dura);

}	// void GamePause(int mSeconds)

void ClearScreen(int xpos, int ypos)
{
    HANDLE hStdout; // handle to console screen
    COORD coordScreen = { xpos, ypos }; // home for the cursor
    DWORD cCharsWritten; //
    CONSOLE_SCREEN_BUFFER_INFO csbi; //
    DWORD dwConSize; // Used to store size of screen

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to output screen.
    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hStdout, // Handle to console screen buffer
        (TCHAR)' ', // Space Character to write to the buffer
        dwConSize, // Number of cells to write
        coordScreen, // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hStdout, // Handle to console screen buffer
        csbi.wAttributes, // Character attributes to use
        dwConSize, // Number of cells to set attribute
        coordScreen, // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hStdout, coordScreen);

}   // void ClearScreen(int xpos, int ypos)

void StartGame()
{
    std::cout << "Please name your Mamepetto : ";
    std::cin >> MamepettoName;
    test.PetSleep = false;
    map.InBed = false;
}

void Name()
{
    std::cout << std::endl << "Name your Mamepetto " << MamepettoName << "? : Y/N : " << std::endl;
    
}