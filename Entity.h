#pragma once
#include "raylib.h"

class Entity
{
protected:
	Rectangle rect;
	float opacity;
public:
	Entity(float x, float y, float width, float height, float opacity):
		rect(Rectangle{x, y, width, height}), opacity(opacity) {}

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

