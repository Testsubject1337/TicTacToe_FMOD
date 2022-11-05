#pragma once
#include <iostream>
#include <fmod.hpp>
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>
#include <Windows.h>

class AudioCoreEngine {
private:
	FMOD::System* fmodsysptr;
	const int maxChannels = 32;
	FMOD_RESULT result;
	FMOD::ChannelGroup* mainMixptr;

public:
	AudioCoreEngine();
	FMOD::System* getFMODSystem();
	FMOD::ChannelGroup* getMainMixChannelGroup();

};

