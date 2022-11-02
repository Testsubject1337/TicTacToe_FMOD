#include "AIPlayer.h"


AIPlayer::AIPlayer() 
{
	srand((unsigned int)time(nullptr));
}

void AIPlayer::doTurn(Field* field)
{
	int numPossibilities = field->getNumFreePositions();
	int* possibilities = new int[numPossibilities];

	field->getFreePositions(possibilities);


	//If winnable Turn there, take it
	for (int i = 0; i < numPossibilities; i++)
	{
		field->putOwnMarkAt(possibilities[i]);
		if (field->hasWon())
			return;
		field->putEmptyMarkAt(possibilities[i]);
	}


	//If Player could have winnable Turn, block it
	for (int i = 0; i < numPossibilities; i++)
	{
		field->putEnemyMarkAt(possibilities[i]);
		if (field->hasLost())
		{
			field->putEmptyMarkAt(possibilities[i]);
			field->putOwnMarkAt(possibilities[i]);
			return;
		}
		field->putEmptyMarkAt(possibilities[i]);
	}


	//If none of above choose Random
	
	field->putOwnMarkAt(possibilities[rand() % numPossibilities]);

}