#include "InitScene.h"

extern OverlayEntity* g_overlay;

InitScene::InitScene(EventQueue* eq, SceneManager* sm):
	eventQueue(eq), suppressUpdates(false), sceneManager(sm)
{
	Font font = LoadFont("resources/Charcoal.ttf");
	text = new TextEntity("Hello, worm", 20, 20, 32, WHITE, 1.0f, font);
}

InitScene::~InitScene()
{
	delete text;
}

void InitScene::Initialize()
{
	IScene* newScene = new TitleScene(eventQueue, sceneManager);

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.3f));
	eventQueue->QueueEvent(new WaitEvent(2));
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.7f));
	eventQueue->QueueEvent(new NewSceneEvent(sceneManager, newScene));
}

bool InitScene::Update(float dt)
{
	return suppressUpdates;
}

void InitScene::Draw()
{
	text->Draw();
}
