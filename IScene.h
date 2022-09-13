#pragma once

class IScene {
public:
	IScene() {}
	virtual ~IScene() {}

	virtual void Draw() = 0;
	virtual bool Update(float dt) = 0;
};