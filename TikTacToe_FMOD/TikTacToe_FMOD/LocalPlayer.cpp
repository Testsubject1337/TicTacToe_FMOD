#include "LocalPlayer.h"
#include <string>

void LocalPlayer::doTurn(Field* field)
{
	int pos = 0;
	std::string userinput;
	int input;
	while (true)
	{
		field->printCurrentField();


		//Check User Input Lenght
		while (true)
		{
			std::cout << "\n Where to put mark at? (1-9): ";
			std::cin >> userinput;
			std::cout << std::endl;

			if (userinput.length() == 1)
			{
				input = stoi(userinput);
				return;
			}
			else
			{
				std::cout << "Invalid Input. Number can not be higher than 9." << std::endl;

			}
		}


			pos = input; //Converting Ascii-Char to Integer (Ascii-Table)
			pos--; //Player can intuitively set a Number between 1-9 and still stays in array-range

		if (pos <= 8 && pos >= 0) //checking array-range
		{
			if (field->isEmptyMarkAt(pos))
			{
				field->putOwnMarkAt(pos);
				return;
			}
			else
			{
				std::cout << "Field at Position " << pos << " is not empty! Try again.\n";
			}
			
		}
		else
		{
			std::cout << "Input invalid. Out of Range. Try again." << std::endl;
		}
	}
}

void LocalPlayer::onWin()
{
	std::cout << "\n You win! \n";
}

void LocalPlayer::onLose()
{
	std::cout << "\n You lost! \n";
}

void LocalPlayer::onTie()
{
	std::cout << "\n It is a Tie! \n";
}