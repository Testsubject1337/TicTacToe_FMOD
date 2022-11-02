#pragma once

#include "Field.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "Game.h"
#include "AudioSource.h"


class TicTacToeFMOD 
{
public:


	void run()
	{

		
		char input;
		while (true)
		{
			AudioCoreEngine FMODINSTANCE = AudioCoreEngine();
			AudioSource startUp = AudioSource("startup.wav", FMOD_LOOP_NORMAL, FMODINSTANCE.getFMODSystem());
			startUp.playSound();
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
			std::cout << std::endl <<
				"-----------------------------------Main Menu-----------------------------------  " << std::endl <<
				"		1) Singleplayer (AI-Mode) \n" <<
				"		2) Multiplayer \n" <<
				"		3) About this Project \n" <<
				"		4) Quit \n		";
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
				startUp.stopSound();


			}

			else if (numberEntered == 4)
			{
				break;
			}
			else
			{
				std::cout << "		Invalid Input. Try again.";
				Sleep(2000);
				std::cout << std::endl;
				numberEntered = NULL;
			}

		}
	}
private:
	char settedPlayerOneChar = 'X';
	char settedPlayerTwoChar = 'O';

	Field field = Field(settedPlayerOneChar, settedPlayerTwoChar);
};