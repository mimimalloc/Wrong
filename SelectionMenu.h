#pragma once
#include <string>
#include <vector>
#include "Entity.h"
#include "raylib.h"

/**
	[ SelectionMenu ]
	A simple UI entity that displays a menu of options,
	with the "selected" option highlighted with a blue
	outline.

	Does not handle input or have external influence;
	all it does is expose the index of the selected
	option for other objects to use.
*/
class SelectionMenu : public Entity
{
public:
	SelectionMenu(std::string fontPath, int fontSize, int verticalSpacing, float x, float y, float w, float h);
	~SelectionMenu();

	// Add an option to the menu
	void AddOption(std::string option);
	// Returns the index for the option currently selected
	int GetSelection();
	// Moves the selection index "down" (increases by 1, resets to 0 after passing the last option)
	void Down();
	// Moves the selection index "up" (decreases by 1, resets to the last option after passing the first option)
	void Up();

	void Update(float dt);
	void Draw();
private:
	// The font that the menu uses (loaded from the fontPath in the constructor)
	Font textFont;
	// The size of the font in the menu
	int fontSize;
	// The spacing in between options in the menu
	int verticalSpacing;
	// The vector containing the menu options
	std::vector<std::string> selections;
	// The index of the currently selected option
	int selectionIDX;
};

