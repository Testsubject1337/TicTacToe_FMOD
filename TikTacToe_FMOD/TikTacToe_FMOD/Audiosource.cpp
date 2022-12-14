#include "AudioSource.h"

//Costructor 0
AudioSource::AudioSource(std::string sourceFile, FMOD_MODE MODE, FMOD::System* FMODSYSTEM, FMOD::ChannelGroup* TARGET_CHANNELGROUP)
{
	this->sourceFile = sourceFile;
	this->FMODSYSTEMPTR = FMODSYSTEM;
	this->MODE = MODE;
	this->channelgroup = TARGET_CHANNELGROUP;



#ifdef _DEBUG

	std::cout << "Trying to Create Soundhandle with **" << this->sourceFileptr->c_str() << "** with Standard Memory Configuration" << std::endl;
#endif
	result = FMODSYSTEMPTR->createSound(this->sourceFileptr->c_str(), MODE, NULL, &soundhandle);
	channel->setVolume(defaultVolume);
	channel->setChannelGroup(this->channelgroup);

#ifdef _DEBUG
	if (result != FMOD_OK)
	{
		std::cout << "...Failed. " << FMOD_ErrorString(result);
		Sleep(1000);
		std::cout << std::endl;

	}
	else
	{
		std::cout << "...successully created Soundhandle within Channelgroup " << this->channelgroup << " ...." << FMOD_ErrorString(result) << "\n Soundhandle: " << soundhandle << std::endl;
		Sleep(1000);
	}
#endif

}

//Constructor 1
AudioSource::AudioSource(std::string sourceFile, FMOD_MODE MODE, FMOD::System* FMODSYSTEM)
{
	this->sourceFile = sourceFile;
	FMODSYSTEMPTR = FMODSYSTEM;
	this->MODE = MODE;

#ifdef _DEBUG

	std::cout << "Trying to Create Soundhandle with **" << this->sourceFileptr->c_str() << "** with Standard Memory Configuration" << std::endl;
#endif
	result = FMODSYSTEMPTR->createSound(this->sourceFileptr->c_str(), MODE, NULL, &soundhandle);

#ifdef _DEBUG
	if (result != FMOD_OK)
	{
		std::cout << "...Failed. " << FMOD_ErrorString(result);
		Sleep(1000);
		std::cout << std::endl;

	}
	else std::cout << "...successully created Soundhandle. " << FMOD_ErrorString(result) << soundhandle << std::endl;
#endif
	channel->setVolume(defaultVolume);
}

//Constructor 2
AudioSource::AudioSource(std::string sourceFile, FMOD::System *FMODSYSTEM) 
{
	this->sourceFile = sourceFile;
	FMODSYSTEMPTR = FMODSYSTEM;

#ifdef _DEBUG

	std::cout << "Trying to Create Soundhandle with **" << this->sourceFileptr->c_str() << "** with Standard Memory Configuration" << std::endl;
#endif
	result = FMODSYSTEMPTR->createSound(this->sourceFileptr->c_str(), MODE, NULL, &soundhandle);

#ifdef _DEBUG
	if (result != FMOD_OK)
	{
		std::cout << "...Failed. " << FMOD_ErrorString(result);
		Sleep(1000);
		std::cout << std::endl;

	}
	else std::cout << "...successully created Soundhandle. " << FMOD_ErrorString(result) << soundhandle << std::endl;
#endif
}


//Play Soundhandle
void AudioSource::playSound() 
{
#ifdef _DEBUG
	std::cout << "Trying to Play Sound... | " << (std::string*)soundhandle << std::endl;
#endif

	result = FMODSYSTEMPTR->playSound(this->soundhandle, NULL, false, &channel);
#ifdef _DEBUG
	if (result != FMOD_OK)
	{
		std::cout << "...Failed.  " << FMOD_ErrorString(result) << std::endl << channel << std::endl;
		
		std::cout << std::endl;

		system("pause");
	}
	else if (result = FMOD_OK) std::cout << "...Success!  " << FMOD_ErrorString(result) << std::endl;
#endif
}


//Stop Soundhandle
void AudioSource::stopSound()
{
	result& channel->stop();
}

//Fade Out
void AudioSource::fadeOut() {
	//This could be done in a much better way using the FMOD API itself, but i want to stop the code as long it is fading out anyway.
	for (float i = 1; i > 0; i -= 0.025f) {
		channel->setVolume(defaultVolume*i);
		Sleep(10);

	}
	channel->stop();
	channel->setVolume(defaultVolume);
	
}