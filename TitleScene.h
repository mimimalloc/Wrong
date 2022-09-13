#pragma once
#include "IScene.h"

class TitleScene : public IScene
{
public:
	TitleScene();
	~TitleScene();

	void Draw();
	bool Update(float dt);
private:
	bool suppressUpdates;
};

