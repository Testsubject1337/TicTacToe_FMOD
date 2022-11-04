#pragma once
#include "Player.h"
#include "Field.h"
#include "AudioSource.h"
#include "AudioCoreEngine.h"

class Game
{
public:
	AudioCoreEngine* FMODINSTANCEPTR;
	AudioSource* inGameMusic = (new AudioSource("inGame.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem()));
	AudioSource* gameOverSound = (new AudioSource("gameOver.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem()));
	bool isSingleplayer;


	//Constructor 1
	Game(Player* player1, Player* player2, AudioCoreEngine FMODINSTANCE, bool isSingleplayer) : player1(player1), player2(player2), FMODINSTANCEPTR(&FMODINSTANCE), isSingleplayer(isSingleplayer) {};
	

	//Deconstructor
	~Game() {
#ifdef _DEBUG
		std::cout << " GameDestructor Called.\n";
		Sleep(2000);
#endif
		delete player1;
		delete player2;
		player1 = nullptr;
		player2 = nullptr;
		delete inGameMusic;
		delete gameOverSound;
		inGameMusic = nullptr;
		gameOverSound = nullptr;

	}


	void run(Field* field);


private:
	Player* player1;
	Player* player2;
};