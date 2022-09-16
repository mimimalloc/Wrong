#pragma once
#include "Entity.h"
#include <string>
#include "raylib.h"

/**
	[ TextEntity ]
	An entity that draws some text to the screen.
	This text can be modified in various ways
	after the entity has been created through
	setters.
*/
class TextEntity : public Entity
{
public:
	TextEntity(std::string text, float x, float y, int size, Color color = WHITE, float opacity = 1.0f, Font font = GetFontDefault());

	// Getters and setters
	inline std::string GetMessageText() { return messageText; }
	inline int GetFontSize() { return fontSize; }
	inline Font GetFont() { return font; }

	inline void SetMessageText(std::string newText) { messageText = newText; }
	inline void SetFontSize(int newFontSize) { fontSize = newFontSize; }
	inline void SetFont(Font newFont) { font = newFont; }

	void Draw();
private:
	// The text displayed
	std::string messageText;
	// The size of the font
	int fontSize;
	// The color of the text
	Color color;
	// The font being used
	Font font;
};

