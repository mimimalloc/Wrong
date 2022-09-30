#include "NewSceneEvent.h"

NewSceneEvent::NewSceneEvent(SceneManager* sm, IScene* scene, bool clearFirst, bool atFront):
	sceneManager(sm), newScene(scene), clearFirst(clearFirst), atFront(atFront)
{
}

void NewSceneEvent::Start()
{
	// If clearFirst is true, all existing scenes should be cleared before adding
	// the new one.
	if (clearFirst) {
		sceneManager->ClearAllScenes();
	}

	// If atFront is true, the new scene will be added to the front of sceneManager's deque
	if (atFront) {
		sceneManager->AddFrontScene(newScene);
	}
	// Otherwise, it's instead added to the back
	else {
		sceneManager->AddBackScene(newScene);
	}

	isFinished = true;
}
