#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>

class Field
{
public:
	Field(char player1Char = 'X', char player2Char = 'O');


	void switchPerspective();

	//Fieldinfo
	int getNumFreePositions();
	int* getFreePositions(int* positions);
	void printCurrentField();


	//Marksetter
	bool putOwnMarkAt(int pos);
	bool putEnemyMarkAt(int pos);
	void putEmptyMarkAt(int pos);

	//Markinfo
	bool isOwnMarkAt(int pos);
	bool isEnemyMarkAt(int pos);
	bool isEmptyMarkAt(int pos);


	//Gameinfo
	bool hasWon();
	bool hasLost();
	bool isFull();

	void resetField();


private:

	bool hasPlayerWithCharWon(char character);

	bool isPlayer1Perspective = true;
	char player1Char = ' ';
	char player2Char = ' ';
	int numFreePositions = 9;
	char field[9];

}; 