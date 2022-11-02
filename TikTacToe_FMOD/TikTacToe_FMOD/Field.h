#pragma once
#include <iostream>

class Field
{
public:
	Field(char player1Char = 'X', char player2Char = 'O');


	void switchPerspective();

	//Fieldinfo
	int getNumFreePositions();
	int* getFreePositions(int* positions);
	
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


private:

	bool hasPlayerWithCharWon(char character);
	
	void printCurrentField();
	


	bool isPlayer1Perspective = true;
	char player1Char = ' ';
	char player2Char = ' ';
	int numFreePositions = 9;
	char field[9];

}; 