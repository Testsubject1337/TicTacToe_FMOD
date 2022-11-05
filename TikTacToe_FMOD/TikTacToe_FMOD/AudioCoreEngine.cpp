#include "AudioCoreEngine.h"

//Constructor

AudioCoreEngine::AudioCoreEngine() 
	{

#ifdef _DEBUG
		std::cout << "initializing FMod System..." << std::endl;
		Sleep(500);
		std::cout << std::endl;
#endif  


// Create FMOD System
		result = FMOD::System_Create(&fmodsysptr);   
		if (result == FMOD_OK) {
#ifdef _DEBUG
			std::cout << "...System Creation is ok." << std::endl;
			Sleep(500);
			std::cout << std::endl;
#endif
		};



		// Initialize FMOD
		result = fmodsysptr->init(maxChannels, FMOD_INIT_NORMAL, NULL);  
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
		


		//Initialize Channelgroup
#ifdef _DEBUG
		std::cout << "trying to initialize Channelgroup....\n";
#endif

		result = fmodsysptr->createChannelGroup(((const char*)&mainChannelGroup), &mainChannelGroupPTR);

#ifdef _DEBUG
		if (result == FMOD_OK)
		{
			std::cout << "...Channelgroup Init went ok. Channelgroup: " << &mainChannelGroupPTR <<std::endl;
			Sleep(500);
			std::cout << std::endl;
		}
		else if (result != FMOD_OK)
		{
			std::cout << "Channelgroup Init went wrong. " << result << std::endl;
			Sleep(4000);
			std::cout << std::endl;
		}
#endif


		//Instanciate MasterSoundgroup
#ifdef _DEBUG
		std::cout << "Trying to Instanciate MasterSoundgroup...\n";
#endif	
		result = fmodsysptr->getMasterSoundGroup(&mainSoundGroup);
#ifdef _DEBUG
		if (result == FMOD_OK)
		{
			std::cout << "...Instanciation went ok. Every Sound is now part of the soundgroup " << &mainSoundGroup << " by default." << std::endl;
			Sleep(2000);
			std::cout << std::endl;
		}
		else if (result != FMOD_OK)
		{
			std::cout << "Instanciation failed. " << FMOD_ErrorString(result) << std::endl;
			Sleep(4000);
			std::cout << std::endl;
		}
#endif

	}


FMOD::System* AudioCoreEngine::getFMODSystem() {
	return fmodsysptr;
}

void AudioCoreEngine::setMasterVolume(float volume)
{
	setVolume = volume * 0.1;
	mainSoundGroup->setVolume(setVolume);
}

FMOD::ChannelGroup* AudioCoreEngine::getMainChannelGroup()
{
	return mainChannelGroupPTR;
}
