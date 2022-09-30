#include "OverlayEntity.h"

OverlayEntity::OverlayEntity():
	Entity(0, 0, 800, 600, 1.0f)
{
}

void OverlayEntity::Draw()
{
	DrawRectangleRec(rect, Fade(BLACK, opacity));
}
