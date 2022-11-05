#include "AudioCoreEngine.h"

//Constructor

AudioCoreEngine::AudioCoreEngine() 
	{

#ifdef _DEBUG
		std::cout << "initializing FMod System..." << std::endl;
		Sleep(500);
		std::cout << std::endl;
#endif // _DEBUG

		result = FMOD::System_Create(&fmodsysptr);   // Create FMOD System
		if (result == FMOD_OK) {
#ifdef _DEBUG
			std::cout << "...System Creation is ok." << std::endl;
			Sleep(500);
			std::cout << std::endl;
#endif
		};

		result = fmodsysptr->init(maxChannels, FMOD_INIT_NORMAL, NULL);  // Initialize FMOD
#ifdef _DEBUG
		if (result == FMOD_OK)
		{
			std::cout << "...FMOD Instance Init went ok." << std::endl;
			Sleep(500);
			std::cout << std::endl;
		}
		else if (result != FMOD_OK)
		{
			std::cout << "FMOD Instance Init went wrong. " << result << std::endl;
			Sleep(4000);
			std::cout << std::endl;
		}

#endif

	}


FMOD::System* AudioCoreEngine::getFMODSystem() {
	return fmodsysptr;
}

FMOD::ChannelGroup* AudioCoreEngine::getMainMixChannelGroup() {
	return mainMixptr;
}