#include "Field.h"

//Constuctor
Field::Field(char player1Char, char player2Char) 
{

#ifdef _DEBUG
	std::cout << "Field Instantiation..." << std::endl;
	Sleep(2000)
#endif

	this->player1Char = player1Char;
	this->player2Char = player2Char;


	//validating Input
	if (player1Char == player2Char || player1Char == ' ' || player2Char == ' ')
	{
		this->player1Char = 'X';
		this->player2Char = '0';
	}

	resetField();

}

void Field::resetField() {

	//reset Free-Positions-Counter
	this->numFreePositions = 9;

	//clear Fields
	for (int i = 0; i < 9; i++)
	{
		field[i] = ' ';
	}
	//reset Player1Perspective for avoiding user-unexpected Character-Switch
	isPlayer1Perspective = true;

}


//Fieldinfo

int Field::getNumFreePositions()
{
	return numFreePositions;
}

int* Field::getFreePositions(int* positions) //Get free Positions
{
	int arrayPos = 0;
	for (int i = 0; i < 9; i++)
	{
		if (field[i] == ' ')
		{
		positions[arrayPos] = i;
		arrayPos++;
		}
	}
	return positions;
}

void Field::switchPerspective() { //Switching Player
	isPlayer1Perspective = !isPlayer1Perspective;
}




//Marksetter
bool Field::putOwnMarkAt(int pos) 
{
	if (field[pos] == ' ') {
		if (isPlayer1Perspective) {
			field[pos] = player1Char;
		}
		else if (!isPlayer1Perspective) {
			field[pos] = player2Char;
		}
		numFreePositions--;
		return true;
	}
	return false;
}


bool Field::putEnemyMarkAt(int pos) 
{
	if (field[pos] == ' ') {
		if (isPlayer1Perspective) {
			field[pos] = player2Char;
		}
		else if (!isPlayer1Perspective) {
			field[pos] = player1Char;
		}
		numFreePositions--;
		return true;
	}
	return false;

}


void Field::putEmptyMarkAt(int pos) 
{
	if (field[pos] != ' ')
	{
		field[pos] = ' ';
		numFreePositions++;
	}
}




//Markinfo
bool Field::isOwnMarkAt(int pos)
{
	if (isPlayer1Perspective)
		return field[pos] == player1Char;
	else
		return field[pos] == player2Char;
}


bool Field::isEnemyMarkAt(int pos)
{
	
	isPlayer1Perspective = !isPlayer1Perspective;
	bool result = isOwnMarkAt(pos);
	isPlayer1Perspective = !isPlayer1Perspective;
	return result;
	  
}


bool Field::isEmptyMarkAt(int pos) 
{
	return field[pos] == ' ';
}




//Gameinfo
bool Field::hasWon() {
	if (isPlayer1Perspective)
		return hasPlayerWithCharWon(player1Char);
	else
		return hasPlayerWithCharWon(player2Char);
}

bool Field::hasLost() {
	if (isPlayer1Perspective)
		return hasPlayerWithCharWon(player2Char);
	else
		return hasPlayerWithCharWon(player1Char);
}

bool Field::isFull() {
	return numFreePositions <= 0;
}




//FieldManger
bool Field::hasPlayerWithCharWon(char character)
{		//Check for all possible Wins
	if (field[0] == character && field[1] == character && field[2] == character
		|| field[0] == character && field[3] == character && field[6] == character
		|| field[0] == character && field[4] == character && field[8] == character
		|| field[1] == character && field[4] == character && field[7] == character
		|| field[2] == character && field[5] == character && field[8] == character
		|| field[2] == character && field[4] == character && field[6] == character
		|| field[3] == character && field[4] == character && field[5] == character
		|| field[6] == character && field[7] == character && field[8] == character)
	{
		return true;
	}
	return false;
}


void Field::printCurrentField()
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
		"*********************************FMOD-EDITION**********************************" << std::endl;
	
	std::cout << "\n\n\n"
		<< "     " << field[0] << " | " << field[1] << " | " << field[2] << "\t\t" << " 1" << " | " << "2" << " | " << "3" << std::endl
		<< "    ---|---|---" << "\t\t---|---|---" << std::endl
		<< "     " << field[3] << " | " << field[4] << " | " << field[5] << "\t\t" << " 4" << " | " << "5" << " | " << "6" << std::endl
		<< "    ---|---|---" << "\t\t---|---|---" << std::endl
		<< "     " << field[6] << " | " << field[7] << " | " << field[8] << "\t\t" << " 7" << " | " << "8" << " | " << "9" << std::endl;
}


