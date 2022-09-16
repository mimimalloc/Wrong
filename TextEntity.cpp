#include "TextEntity.h"

TextEntity::TextEntity(std::string text, float x, float y, int size, Color color, float opacity, Font font) :
	Entity(x, y, 0, 0, opacity),
	messageText(text), fontSize(size), font(font), color(color)
{
}

void TextEntity::Draw()
{
	DrawTextEx(font, messageText.c_str(), Vector2{ rect.x, rect.y }, fontSize, 1, Fade(color, opacity));
}

