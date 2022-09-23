#pragma once

/**
	[ SceneStatus ]
	When a scene updates, it returns one of these
	to communicate back to the scene manager what
	to do after the scene has updated
*/
enum SceneStatus {
	CONTINUE_UPDATES, STOP_UPDATES, EXIT_SIGNAL 
};

/**
	[ IScene ]
	The base scene that other scenes inherit from.

	Don't use this class on its own - it's intended
	to be inherited by "real" Scenes.
*/
class IScene {
protected:
	// This is true when the scene is done, and is
	// ready for its SceneManager to destroy it
	bool readyForRelease{ false };
public:
	IScene() {}
	virtual ~IScene() {}

	virtual void Initialize() = 0;
	virtual void Draw() = 0;
	virtual SceneStatus Update(float dt) = 0;
};