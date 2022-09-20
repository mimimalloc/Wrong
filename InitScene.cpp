#include "InitScene.h"

extern OverlayEntity* g_overlay;

InitScene::InitScene(EventQueue* eq, SceneManager* sm):
	eventQueue(eq), suppressUpdates(false), sceneManager(sm), entityManager(new EntityManager)
{
	
}

InitScene::~InitScene()
{
	
}

void InitScene::Initialize()
{
	Font font = LoadFont("resources/RaccoonSerif-Monospace.ttf");
	TextEntity* text1 = new TextEntity("Developed by", 40, 80, 24, WHITE, 1.0f, font);
	TextEntity* text2 = new TextEntity("Noemi Banks (mimimalloc)", 60, 120, 32, WHITE, 1.0f, font);

	entityManager->AddEntity("text1", text1);
	entityManager->AddEntity("text2", text2);
	
	IScene* newScene = new TitleScene(eventQueue, sceneManager);

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.3f));
	eventQueue->QueueEvent(new WaitEvent(2));
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.7f));
	eventQueue->QueueEvent(new NewSceneEvent(sceneManager, newScene));
}

bool InitScene::Update(float dt)
{
	entityManager->Update(dt);
	return suppressUpdates;
}

void InitScene::Draw()
{
	entityManager->Draw();
}
