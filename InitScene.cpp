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
	Font font = LoadFont("resources/Charcoal.ttf");
	TextEntity* text = new TextEntity("Hello, worm", 20, 20, 32, WHITE, 1.0f, font);
	ImageEntity* image = new ImageEntity("resources/raylib_96x96.png", 100, 100, 96, 96);

	entityManager->AddEntity("text", text);
	entityManager->AddEntity("image", image);
	
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
