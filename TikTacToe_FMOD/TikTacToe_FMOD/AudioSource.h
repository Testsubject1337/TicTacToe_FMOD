#pragma once
#include "AudioCoreEngine.h"

class AudioSource {
private:
	std::string sourceFile;
	std::string* sourceFileptr = &sourceFile;
	FMOD_MODE MODE = FMOD_DEFAULT;
	FMOD_RESULT result;
	FMOD::System* FMODSYSTEMPTR;
	FMOD::Channel* channel;
	float defaultVolume = 0.5f;

public:
	FMOD::Sound* soundhandle;


	AudioSource(std::string sourceFile, FMOD_MODE MODE, FMOD::System* FMODSYSTEM);
	AudioSource(std::string sourceFile, FMOD::System* FMODSYSTEM);

	void playSound();
	void stopSound();
	void fadeOut();


};