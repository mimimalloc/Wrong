#include "SelectionMenu.h"

SelectionMenu::SelectionMenu(std::string fontPath, int fontSize, int verticalSpacing, float x, float y, float w, float h) :
	Entity(x, y, w, h, 1.0f),
	fontSize(fontSize), verticalSpacing(verticalSpacing), selectionIDX(0)
{
	textFont = LoadFont(fontPath.c_str());
}

SelectionMenu::~SelectionMenu()
{
	UnloadFont(textFont);
}

void SelectionMenu::AddOption(std::string option)
{
	selections.push_back(option);
}

int SelectionMenu::GetSelection()
{
	return selectionIDX;
}

void SelectionMenu::Down()
{
	selectionIDX += 1;
	if (selectionIDX >= selections.size()) {
		selectionIDX = 0;
	}
}

void SelectionMenu::Up()
{
	selectionIDX -= 1;
	if (selectionIDX < 0) {
		selectionIDX = selections.size() - 1;
	}
}

void SelectionMenu::Update(float dt)
{

}

void SelectionMenu::Draw()
{
	DrawRectangleLinesEx(
		Rectangle{ rect.x - 8, rect.y + (verticalSpacing * selectionIDX) - 8, rect.width, rect.height }, 4.0f, DARKBLUE
	);
	for (int i = 0; i < selections.size(); i++) {
		auto text = selections[i].c_str();
		DrawText(text, rect.x, rect.y + (verticalSpacing * i), fontSize, WHITE);
	}
}
