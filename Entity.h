#pragma once
#include "raylib.h"

/**
	[ Entity ]
	An Entity is anything that exists in the game's coordinate space
	and/or is drawn and updated. Entity pointers can be passed into 
	general events that affect them in various ways.
*/
class Entity
{
protected:
	// The rectangle representing the Entity's position, width, and height
	Rectangle rect;

	// The opacity with which the Entity is drawn
	float opacity;
public:
	Entity(float x, float y, float width, float height, float opacity):
		rect(Rectangle{x, y, width, height}), opacity(opacity) {}

	// Basic getters and setters (some reach into the rect's struct)
	inline Rectangle GetRect() { return rect; }
	inline float GetX() { return rect.x; }
	inline float GetY() { return rect.y; }
	inline float GetWidth() { return rect.width; }
	inline float GetHeight() { return rect.height; }
	inline float GetOpacity() { return opacity; }

	inline void SetRect(Rectangle newRect) { rect = newRect; }
	inline void SetX(float newX) { rect.x = newX; }
	inline void SetY(float newY) { rect.y = newY; }
	inline void SetWidth(float newWidth) { rect.width = newWidth; }
	inline void SetHeight(float newHeight) { rect.height = newHeight; }
	inline void SetOpacity(float newOpacity) { opacity = newOpacity; }

	virtual void Update(float dt) {}
	virtual void Draw() {}
};

