#pragma once
#include "Entity.h"
#include "raylib.h"

/**
	[ OverlayEntity ]
	This is one of the simplest possible entities,
	a box that is drawn to cover the screen and hide
	elements that are drawn behind it. Its opacity can
	be manipulated for fade effects.
*/
class OverlayEntity : public Entity
{
public:
	OverlayEntity();

	void Draw();
};

