#pragma once
#include "raylib.h"
#include <map>
#include <string>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void AMActivate();
	void AMDeactivate();

	void AMLoadSFX(std::string label, std::string path);
	void AMLoadMusic(std::string label, std::string path);

	void AMUnloadSFX(std::string label);
	void AMUnloadMusic(std::string label);

	void AMPlaySound(std::string label);

	void AMPlayMusic(std::string label);
	void AMPauseMusic(std::string label);
	void AMResumeMusic(std::string label);
	void AMStopMusic(std::string label);
private:
	std::map<std::string, Sound> loadedSFX;
	std::map<std::string, Music> loadedMusic;
};

