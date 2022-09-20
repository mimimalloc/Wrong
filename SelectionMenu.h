#pragma once
#include <string>
#include <vector>
#include "Entity.h"
#include "raylib.h"
class SelectionMenu : public Entity
{
public:
	SelectionMenu(std::string fontPath, int fontSize, int verticalSpacing, float x, float y, float w, float h);
	~SelectionMenu();

	void AddOption(std::string option);
	int GetSelection();
	void Down();
	void Up();

	void Update(float dt);
	void Draw();
private:
	Font textFont;
	int fontSize;
	int verticalSpacing;
	std::vector<std::string> selections;
	int selectionIDX;
};

