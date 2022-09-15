#include "FadeEvent.h"
#include "raylib.h"

FadeEvent::FadeEvent(Entity* entity, FadeDirection dir, float rate) :
	fadeEntity(entity), direction(dir), rate(rate)
{

}

void FadeEvent::Start()
{
	isRunning = true;
}

void FadeEvent::Run(float dt)
{
	if (direction == fadeout) {
		// To fadeout, lower the Entity's opacity by (rate * dt)
		fadeEntity->SetOpacity(fadeEntity->GetOpacity() - rate * dt);
		// When it reaches 0.0f, the FadeEvent has finished
		if (fadeEntity->GetOpacity() <= 0.0f) {
			fadeEntity->SetOpacity(0.0f);
			isRunning = false;
			isFinished = true;
		}
	} else {
		// To fadein, increase the Entity's opacity by (rate * dt)
		fadeEntity->SetOpacity(fadeEntity->GetOpacity() + rate * dt);
		// When it reaches 1.0f, the FadeEvent has finished
		if (fadeEntity->GetOpacity() >= 1.0f) {
			fadeEntity->SetOpacity(1.0f);
			isRunning = false;
			isFinished = true;
		}
	}
}
