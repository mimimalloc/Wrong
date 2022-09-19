#pragma once
#include "Entity.h"
#include <string>
#include "raylib.h"

class ImageEntity : public Entity
{
public:
	ImageEntity(std::string path, float x, float y, float w, float h, float opacity = 1.0f);
	~ImageEntity();

	void Draw();
private:
	Texture2D image;
};

