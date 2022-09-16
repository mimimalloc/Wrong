#pragma once

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
	virtual bool Update(float dt) = 0;
};