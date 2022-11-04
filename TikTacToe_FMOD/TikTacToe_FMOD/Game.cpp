#include "Game.h"

void Game::run(Field* field)
{
	inGameMusic->playSound();
	while (!field->isFull() && !field->hasLost() && !field->hasWon())
	{
		player1->doTurn(field);
		Player* player = player1;
		player1 = player2;
		player2 = player;

		field->switchPerspective();
	}

	if (field->hasWon())
	{
		field->printCurrentField();
		inGameMusic->fadeOut();
		gameOverSound->playSound();
		inGameMusic->fadeOut();
		if (isSingleplayer)
		{
			player1->onWin();
			player2->onLose();
		}
		else std::cout << "\nGame is over. Congratulations!";
		std::cout << std::endl;
		system("pause");
	}
	else if (field->hasLost())
	{
		field->printCurrentField();
		inGameMusic->fadeOut();
		gameOverSound->playSound();
		if (isSingleplayer)
		{
			player2->onWin();
			player1->onLose();
		}
		else std::cout << "\nGame is over. Congratulations!";
		std::cout << std::endl;


		system("pause");
	}
	else
	{
		field->printCurrentField();
		inGameMusic->fadeOut();
		gameOverSound->playSound();
		std::cout << "\nIt is a tie!";
		std::cout << std::endl;


		system("pause");
	}

}