#include "ImageEntity.h"

ImageEntity::ImageEntity(std::string path, float x, float y, float w, float h, float opacity):
	Entity(x, y, w, h, opacity)
{
	image = LoadTexture(path.c_str());
}

ImageEntity::~ImageEntity()
{
	UnloadTexture(image);
}

void ImageEntity::Draw()
{
	DrawTexture(image, rect.x, rect.y, Fade(WHITE, opacity));
}
