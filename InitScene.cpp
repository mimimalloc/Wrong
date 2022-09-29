#include "InitScene.h"

extern OverlayEntity* g_overlay;

InitScene::InitScene(EventQueue* eq, SceneManager* sm, AudioManager* am):
	eventQueue(eq), suppressUpdates(false), sceneManager(sm), audioManager(am),
	entityManager(new EntityManager())
{
	
}

InitScene::~InitScene()
{
	delete entityManager;
}

void InitScene::Initialize()
{
	Font font = LoadFont("resources/RaccoonSerif-Monospace.ttf");
	TextEntity* text1 = new TextEntity("Developed by", 40, 80, 24, WHITE, 1.0f, font);
	TextEntity* text2 = new TextEntity("Noemi Banks (mimimalloc)", 60, 120, 32, WHITE, 1.0f, font);

	entityManager->AddEntity("text1", text1);
	entityManager->AddEntity("text2", text2);
	
	IScene* newScene = new TitleScene(eventQueue, sceneManager, audioManager);

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.9f));
	eventQueue->QueueEvent(new WaitEvent(2));
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.9f));
	eventQueue->QueueEvent(new NewSceneEvent(sceneManager, newScene));
}

SceneStatus InitScene::Update(float dt)
{
	entityManager->Update(dt);
	return CONTINUE_UPDATES;
}

void InitScene::Draw()
{
	entityManager->Draw();
}
