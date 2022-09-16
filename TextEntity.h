#pragma once
#include "Entity.h"
#include <string>
#include "raylib.h"

class TextEntity : public Entity
{
public:
	TextEntity(std::string text, float x, float y, int size, Color color = WHITE, float opacity = 1.0f, Font font = GetFontDefault());

	inline std::string GetMessageText() { return messageText; }
	inline int GetFontSize() { return fontSize; }
	inline Font GetFont() { return font; }

	inline void SetMessageText(std::string newText) { messageText = newText; }
	inline void SetFontSize(int newFontSize) { fontSize = newFontSize; }
	inline void SetFont(Font newFont) { font = newFont; }

	void Draw();
private:
	std::string messageText;
	int fontSize;
	Color color;
	Font font;
};

