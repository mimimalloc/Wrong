#pragma once
#include "Entity.h"
#include <string>
#include "raylib.h"

/**
	[ ImageEntity ]
	An entity that stores and displays a basic
	image as a texture.
*/
class ImageEntity : public Entity
{
public:
	ImageEntity(std::string path, float x, float y, float w, float h, float opacity = 1.0f);
	~ImageEntity();

	void Draw();
private:
	// The entity's image, stored as a texture
	Texture2D image;
};

