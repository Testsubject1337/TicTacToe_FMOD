#pragma once
#include "Player.h"
#include "Field.h"
#include "AudioSource.h"
#include "AudioCoreEngine.h"

class Game
{
public:
	AudioCoreEngine* FMODINSTANCEPTR;
	AudioSource inGameMusic = AudioSource("inGame.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem());
	AudioSource gameOverSound = AudioSource("gameOver.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem());


	Game(Player* player1, Player* player2, AudioCoreEngine FMODINSTANCE) : player1(player1), player2(player2), FMODINSTANCEPTR(&FMODINSTANCE)
	{
		
	};
		
	void run(Field * field)
	{
		inGameMusic.playSound();
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
			inGameMusic.fadeOut();
			gameOverSound.playSound();
			inGameMusic.fadeOut();
			player1->onWin();
			player2->onLose();
			system("pause");

		}
		else if (field->hasLost())
		{
			field->printCurrentField();
			inGameMusic.fadeOut();
			gameOverSound.playSound();
			system("pause");
		}
		else
		{
			field->printCurrentField();
			inGameMusic.fadeOut();
			gameOverSound.playSound();
			system("pause");
		}

	}
private:
	Player* player1;
	Player* player2;
};