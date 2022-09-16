#include "NewSceneEvent.h"

NewSceneEvent::NewSceneEvent(SceneManager* sm, IScene* scene, bool clearFirst, bool atFront):
	sceneManager(sm), newScene(scene), clearFirst(clearFirst), atFront(atFront)
{
}

void NewSceneEvent::Start()
{
	if (clearFirst) {
		sceneManager->ClearAllScenes();
	}

	if (atFront) {
		sceneManager->AddFrontScene(newScene);
	}
	else {
		sceneManager->AddBackScene(newScene);
	}

	isFinished = true;
}
