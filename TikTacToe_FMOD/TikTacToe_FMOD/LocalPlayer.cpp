#include "LocalPlayer.h"


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

			//Validate Input...  yes, i hate myself for this cucubercode but this was way too timeconsuming and in this case it justs works :D
			if (userinput.length() == 1 && (userinput == "1" || userinput == "2" || userinput == "3" || userinput == "4" || userinput == "5" || userinput == "6" || userinput == "7" || userinput == "8" || userinput == "9")) 
			{
				input = stoi(userinput);  //Converting to Integer
				break;
			}
			else
			{
				std::cout << "Invalid Input. Must be Number between 1-9." << std::endl;

			}
		}

			input--; //Player can intuitively set a Number between 1-9 and still stays in array-range of field
			pos = input;
			

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