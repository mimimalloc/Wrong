#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>

/**
	[ AudioManager ]
	The AudioManager handles audio - both sounds
	and music. It stores loaded audio in maps and
	provides an interface to accessing and playing
	them through raylib functions
*/
class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	// Initializes the audio device
	void AMActivate();
	// Closes the audio device
	void AMDeactivate();

	// Loads a sound file and stores it with the given label
	void AMLoadSFX(std::string label, std::string path);
	// Loads a music stream and stores it with the given label
	void AMLoadMusic(std::string label, std::string path);

	// Unloads a sound file stored by the given label
	void AMUnloadSFX(std::string label);
	// Unloads a music stream stored by the given label
	void AMUnloadMusic(std::string label);

	// Plays a sound stored by the given label
	void AMPlaySound(std::string label);

	// Plays a music stream stored by the given label
	void AMPlayMusic(std::string label);
	// Pauses a music stream stored by the given label
	void AMPauseMusic(std::string label);
	// Resumes a music stream stored by the given label
	void AMResumeMusic(std::string label);
	// Stops a music stream stored by the given label
	void AMStopMusic(std::string label);
	// Updates the music stream if it is active
	void AMUpdateMusicStream(std::string label);
private:
	// Stores sounds that have been loaded
	std::unordered_map<std::string, Sound> loadedSFX;
	// Stores music that has been loaded
	std::unordered_map<std::string, Music> loadedMusic;
};

