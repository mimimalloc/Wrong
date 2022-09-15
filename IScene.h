#pragma once

class IScene {
protected:
	bool readyForRelease{ false };
public:
	IScene() {}
	virtual ~IScene() {}

	virtual void Draw() = 0;
	virtual bool Update(float dt) = 0;
};