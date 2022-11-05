#pragma once

#include "Field.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "Game.h"
#include "AudioSource.h"


class TicTacToeFMOD 
{
public:
	void run();


private:
	//Creating FMOD Soundhandles for Menu-Sounds
	AudioCoreEngine FMODINSTANCE = AudioCoreEngine();
	AudioCoreEngine* FMODINSTANCEPTR = &FMODINSTANCE;
	AudioSource aboutThis = AudioSource("FarCry3_8bit.wav", FMOD_LOOP_NORMAL, FMODINSTANCEPTR->getFMODSystem(), FMODINSTANCEPTR->getMainChannelGroup());
	AudioSource startUp = AudioSource("startup.wav", FMOD_LOOP_NORMAL, FMODINSTANCEPTR->getFMODSystem(), FMODINSTANCEPTR->getMainChannelGroup());
	AudioSource selectSound = AudioSource("select.wav", FMOD_DEFAULT, FMODINSTANCEPTR->getFMODSystem(), FMODINSTANCEPTR->getMainChannelGroup());
	bool isThemePlaying = false;
	



	//Set PlayerChars here!
	char settedPlayerOneChar = 'X';
	char settedPlayerTwoChar = 'O';


	float floatEntered = 0;
	std::string stringEntered = "0";
	

	//*****Instantiate Field****
	Field field = Field(settedPlayerOneChar, settedPlayerTwoChar);

	void drawAsciiArt(int imgID);

};