#include "TicTacToeFMOD.h"

void TicTacToeFMOD::run()
{
	char input;
	while (true)
	{
		if (!isThemePlaying) startUp.playSound();
		isThemePlaying = true;
		drawAsciiArt(1);
		std::cout << 
			"-----------------------------------Main Menu-----------------------------------  " << std::endl <<
			"		1) Singleplayer (AI-Mode) \n" <<
			"		2) Local Multiplayer \n" <<
			"		3) About this Project \n" <<
			"		4) Settings \n" <<
			"		5) Quit \n		Input: ";
		std::cin >> input;
		int numberEntered = input - '0'; //Converting Char to Int with Asciitable

		//Singleplayer 
		if (numberEntered == 1)
		{
			selectSound.playSound();
			startUp.fadeOut();
			isThemePlaying = false;
			Game* game = (new Game(new LocalPlayer(), new AIPlayer(), *FMODINSTANCEPTR, true));
			game->run(&field);
			delete game;
			game = nullptr;
			field.resetField();

		}

		//Local Multiplayer
		else if (numberEntered == 2)
		{
			selectSound.playSound();
			startUp.fadeOut();
			isThemePlaying = false;
			Game* game = (new Game(new LocalPlayer(false, 1), new LocalPlayer(false, 2), *FMODINSTANCEPTR, false));
			game->run(&field);
			delete game;
			game = nullptr;
			field.resetField();


		}

		//About this Project
		else if (numberEntered == 3)
		{
			selectSound.playSound();
			startUp.fadeOut();
			isThemePlaying = false;
			aboutThis.playSound();
			drawAsciiArt(2);
			std::cout <<

				"--------------------------------Dear Crytek-Team,-------------------------------" << std::endl <<
				" " << std::endl <<
				"It looks like you found the less obvious part of my application! ;) " << std::endl <<
				std::endl <<
				"This project was created purely for this purpose. " << std::endl <<
				"The basic idea for the TikTacToe comes from @Pilzschaf on YouTube, I created the" << std::endl <<
				"projects fundamentals based on his videos and adapted it for my purposes - like " << std::endl <<
				"adding sound using the **FMOD Core API** and a few sound effects. " << std::endl <<
				std::endl <<
				"This project was created within 9 hours (steep learning curve included! ;D) " << std::endl <<
				std::endl <<
				"Speaking of sound: Is that the 8-bit Version of the FarCry 3 Theme??    " << std::endl << std::endl;
			system("pause");

			aboutThis.fadeOut();

		}

		//Settings
		else if (numberEntered == 4)
		{
			while (true)
			{
				system("cls");
				drawAsciiArt(1);
				std::cout <<
					"-----------------------------------Settings------------------------------------" << std::endl <<
					"		1) Adjust Volume \n" <<
					"		2) back \n" <<
					"		Input: ";
				input = '0';
				numberEntered = '0';
				std::cin >> input;
				numberEntered = input - '0'; // Converting Char to Int with Asciitable



				if (numberEntered == 1) // Volume Setting
				{
					while (true)
					{
						drawAsciiArt(1);
						std::cout <<
						"---------------------------------Adjust Volume---------------------------------" << std::endl <<
						"		You can Adjust the Volume with a Number betweeen 0 & 10(max). \n" <<
						"		42 for abort. \n		Input: ";

						floatEntered = 0;
						std::cin >> floatEntered; // !!! Comma as User Input still breaks the Code...
						

						if (floatEntered == 42)
						{
							break;
						}
						else if (floatEntered >=0 && floatEntered <= 10)
						{;
							FMODINSTANCEPTR->setMasterVolume(floatEntered);
							break;
						}
						else { std::cout << "Invalid Input. Try again." << std::endl; }
						floatEntered = 0;
					}
				}
				else if (numberEntered == 2)
				{
					break;
				}
				else
				{
					std::cout << "Invalid input. Please try again.";
					Sleep(300);
				}
			}
		}

		//Quit
		else if (numberEntered == 5)
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


void TicTacToeFMOD::drawAsciiArt(int imgID = 1)  // 1=Default, 2=About This
{
	if (imgID == 1) // NORMAL TICTACTOE-HEADER
	{
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
			"*********************************FMOD-EDITION**********************************" << std::endl << std::endl;
	}
	else if (imgID == 2) // ABOUT THIS HEADER
	{
		system("cls");
		std::cout <<
			"********************************************************************************" << std::endl <<
			"* _______  _______  _______  __   __  _______   _______  __   __  ___  _______ *" << std::endl <<
			"*|   _   ||  _    ||       ||  | |  ||       | |       ||  | |  ||   ||       |*" << std::endl <<
			"*|  |_|  || |_|   ||   _   ||  | |  ||_     _| |_     _||  |_|  ||   ||  _____|*" << std::endl <<
			"*|       ||       ||  | |  ||  |_|  |  |   |     |   |  |       ||   || |_____ *" << std::endl <<
			"*|       ||  _   | |  |_|  ||       |  |   |     |   |  |       ||   ||_____  |*" << std::endl <<
			"*|   _   || |_|   ||       ||       |  |   |     |   |  |   _   ||   | _____| |*" << std::endl <<
			"*|__| |__||_______||_______||_______|  |___|     |___|  |__| |__||___||_______|*" << std::endl <<
			"***********************The Secret Part of my application************************" << std::endl << std::endl;
	} 
}