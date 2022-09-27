#include "AudioManager.h"

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{

}

void AudioManager::AMActivate()
{
	InitAudioDevice();
}

void AudioManager::AMDeactivate()
{
	CloseAudioDevice();
}

void AudioManager::AMLoadSFX(std::string label, std::string path)
{
	if (!loadedSFX.count(label)) {
		loadedSFX[label] = LoadSound(path.c_str());
	}
}

void AudioManager::AMLoadMusic(std::string label, std::string path)
{
	if (!loadedMusic.count(label)) {
		loadedMusic[label] = LoadMusicStream(path.c_str());
	}
}

void AudioManager::AMUnloadSFX(std::string label)
{
	if (loadedSFX.count(label)) {
		UnloadSound(loadedSFX[label]);
		loadedSFX.erase(label);
	}
}

void AudioManager::AMUnloadMusic(std::string label)
{
	if (loadedMusic.count(label)) {
		UnloadMusicStream(loadedMusic[label]);
		loadedMusic.erase(label);
	}
}

void AudioManager::AMPlaySound(std::string label)
{
	if (loadedSFX.count(label)) {
		PlaySound(loadedSFX[label]);
	}
}

void AudioManager::AMPlayMusic(std::string label)
{
	if (loadedMusic.count(label)) {
		PlayMusicStream(loadedMusic[label]);
	}
}

void AudioManager::AMPauseMusic(std::string label)
{
	if (loadedMusic.count(label)) {
		PauseMusicStream(loadedMusic[label]);
	}
}

void AudioManager::AMResumeMusic(std::string label)
{
	if (loadedMusic.count(label)) {
		ResumeMusicStream(loadedMusic[label]);
	}
}

void AudioManager::AMStopMusic(std::string label)
{
	if (loadedMusic.count(label)) {
		StopMusicStream(loadedMusic[label]);
	}
}
