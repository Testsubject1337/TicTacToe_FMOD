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
		AudioCoreEngine FMODINSTANCE = AudioCoreEngine();
		AudioCoreEngine* FMODINSTANCEPTR = &FMODINSTANCE;
		AudioSource aboutThis = AudioSource("FarCry3_8bit.wav", FMOD_LOOP_NORMAL, FMODINSTANCEPTR->getFMODSystem());
		AudioSource startUp = AudioSource("startup.wav", FMOD_LOOP_NORMAL, FMODINSTANCEPTR->getFMODSystem());
		AudioSource selectSound = AudioSource("select.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem());
		
		char input;
		while (true)
		{

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
				"		2) Local Multiplayer \n" <<
				"		3) About this Project \n" <<
				"		4) Quit \n		";
			std::cin >> input;
			int numberEntered = input - '0'; //Converting Char to Int with Asciitable

			//Singleplayer 
			if (numberEntered == 1)
			{
				selectSound.playSound();
				startUp.fadeOut();
				(new Game(new LocalPlayer(), new AIPlayer(), *FMODINSTANCEPTR))->run(&field);
				field.resetField();
				
			} 

			//Local Multiplayer
			else if (numberEntered == 2)
			{
				selectSound.playSound();
				startUp.fadeOut();
				(new Game(new LocalPlayer(), new LocalPlayer, *FMODINSTANCEPTR))->run(&field);
				field.resetField();
				

			}

			//About this Project
			else if (numberEntered == 3)
			{
				selectSound.playSound();
				startUp.fadeOut();
				system("cls");
				aboutThis.playSound();
				
				std::cout <<
						"********************************************************************************" << std::endl <<
						"* _______  _______  _______  __   __  _______   _______  __   __  ___  _______ *" << std::endl <<
						"*|   _   ||  _    ||       ||  | |  ||       | |       ||  | |  ||   ||       |*" << std::endl <<
						"*|  |_|  || |_|   ||   _   ||  | |  ||_     _| |_     _||  |_|  ||   ||  _____|*" << std::endl <<
						"*|       ||       ||  | |  ||  |_|  |  |   |     |   |  |       ||   || |_____ *" << std::endl <<
						"*|       ||  _   | |  |_|  ||       |  |   |     |   |  |       ||   ||_____  |*" << std::endl <<
						"*|   _   || |_|   ||       ||       |  |   |     |   |  |   _   ||   | _____| |*" << std::endl <<
						"*|__| |__||_______||_______||_______|  |___|     |___|  |__| |__||___||_______|*" << std::endl <<
						"***********************The Secret Part of my application************************" << std::endl <<
						" " << std::endl <<
						"--------------------------------Dear Crytek-Team,-------------------------------" << std::endl <<
						" " << std::endl <<
						" It looks like you found the less obvious part of my application! ;) " << std::endl <<
						std::endl <<
						" This project was created purely for this purpose. " << std::endl <<
						" The basic idea for the TikTacToe comes from @Pilzschaf on YouTube, I created the" << std::endl <<
						" projectbase using his videos and adapted it for my purposes, like adding sound  " << std::endl <<
						" using the **FMOD Core API** and a few sound effects. " << std::endl <<
						std::endl <<
						" This project was created within 12 hours (steep learning curve included! ;D) " << std::endl <<
						std::endl <<
						" Speaking of sound: Is that the 8-bit Version of the FarCry 3 Soundtrack??    " << std::endl << std::endl;
				system("pause");

				aboutThis.fadeOut();
				


			}

			//Quit
			else if (numberEntered == 4)
			{
				selectSound.playSound();
				system("cls");
				std::cout << "					Good Bye <3";
				startUp.fadeOut();
				break;
			}	

			//Invalid Input
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
	//Set PlayerChars here!
	char settedPlayerOneChar = 'X';
	char settedPlayerTwoChar = 'O';

	Field field = Field(settedPlayerOneChar, settedPlayerTwoChar);
};