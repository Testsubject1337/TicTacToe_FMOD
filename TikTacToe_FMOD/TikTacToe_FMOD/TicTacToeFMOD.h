#pragma once
#include "Field.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "Game.h"

class TicTacToeFMOD 
{
public:

	void refreshHeader() {
		system("cls");
		std::cout <<
			"*******************************************************************************" << std::endl <<
			"* _______  ___  _______  _______  _______  _______  _______  _______  _______ *" << std::endl <<
			"*|       ||   ||       ||       ||   _   ||       ||       ||       ||       |*" << std::endl <<
			"*|_     _||   ||       ||_     _||  |_|  ||       ||_     _||   _   ||    ___|*" << std::endl <<
			"*  |   |  |   ||       |  |   |  |       ||       |  |   |  |  | |  ||   |___ *" << std::endl <<
			"*  |   |  |   ||      _|  |   |  |       ||      _|  |   |  |  |_|  ||    ___|*" << std::endl <<
			"*  |   |  |   ||     |_   |   |  |   _   ||     |_   |   |  |       ||   |___ *" << std::endl <<
			"*  |___|  |___||_______|  |___|  |__| |__||_______|  |___|  |_______||_______|*" << std::endl <<
			"*********************************FMOD-EDITION**********************************" << std::endl;
	}

	void run()
	{
		

		refreshHeader();

		char input;
		while (true)
		{
			std::cout << std::endl <<
				"-----------------------------------Main Menu-----------------------------------  " << std::endl <<
				"		1) Singleplayer (AI-Mode) \n" <<
				"		2) Multiplayer \n" <<
				"		3) Quit \n		";
			std::cin >> input;
			int numberEntered = input - '0'; //Converting Char to Int with Asciitable

			if (numberEntered == 1)
			{
				(new Game(new LocalPlayer(), new AIPlayer()))->run(&field);
				field.resetField();
				
			} 
			else if (numberEntered == 2)
			{
				(new Game(new LocalPlayer(), new LocalPlayer))->run(&field);
				field.resetField();
				

			}
			else if (numberEntered == 3)
			{
				break;
			}
			else
			{
				std::cout << " invalid Input. Try again." << std::endl;
			}

		}
	}
private:
	char settedPlayerOneChar = 'X';
	char settedPlayerTwoChar = 'O';

	Field field = Field(settedPlayerOneChar, settedPlayerTwoChar);
};