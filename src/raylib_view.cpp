#include "raylib_view.hpp"
#include "board_layout.hpp"
#include <string>

namespace FrogToad {

	
	//Draws only the outline from the cells 
	void RaylibView::drawCells() {
		int leftBuffer = BoardLayout::Left;
		int topBuffer = BoardLayout::Top;
		int boxSize = BoardLayout::CellSize;
		Vector2 mp = GetMousePosition();

		//Stores the location of the mouse so the selected cell can be highlighted
		std::optional<int> index = BoardLayout::cellAt(mp);

		if (index != std::nullopt) {
			//Retrieves the used cell and draws a yellow rectangle on it
			Rectangle r = BoardLayout::cellRect(index.value());
			DrawRectangleRec(r, YELLOW);
		}

		//Draws the cells outline and the numbers on the bottom.
		for (int index{ 0 }; index < BoardModel::BoardSize; index++) {
			DrawRectangleLines(index * boxSize + leftBuffer, topBuffer, boxSize, boxSize, WHITE);
			drawText(index * boxSize + (boxSize/2) + leftBuffer, 200, TextFormat("%d", index + 1), 20, BLACK);
		}

	}

	//Used to write text on the UI.
	void RaylibView::drawText(const float& posX, const float& posY, const std::string text, const float& fontSize, const Color color) {
		Font font = GetFontDefault();
		DrawTextEx(font, text.c_str(), { posX, posY}, fontSize, 1.0f, color);
	}

	//Draws frogs and toads characters depending the type of cell.
	void RaylibView::drawPieces(const BoardModel& model) {
		const float mod{ 500 / BoardModel::BoardSize };

		float posX{ (50 + mod/2) -5 };

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			switch (model.cellAt(index)) {
			case BoardModel::Cell::Frog:
				drawFrog(posX, mod);
				break;
			case BoardModel::Cell::Toad:
				drawToad(posX, mod);
				break;
			case BoardModel::Cell::Empty:
				break;
			}
			posX += mod;
		}

	}

	void RaylibView::drawFrog(int x, int size) {
		DrawCircle(x, 145, size/4, GREEN);
		DrawCircle(x+size/4, 135, size/10, GREEN);
		DrawCircle(x+size/4, 155, size/10, GREEN);
		DrawCircle(x + size / 4, 135, size / 15, WHITE);
		DrawCircle(x + size / 4, 155, size / 15, WHITE);
		DrawCircle(x + size / 4, 135, size / 25, BLACK);
		DrawCircle(x + size / 4, 155, size / 25, BLACK);
	}

	void RaylibView::drawToad(int x, int size) {
		//Adds an offset to the right
		x += 10;
		DrawCircle(x, 145, size / 4, BROWN);
		DrawCircle(x - size / 4, 135, size / 10, BROWN);
		DrawCircle(x - size / 4, 155, size / 10, BROWN);
		DrawCircle(x - size / 4, 135, size / 15, WHITE);
		DrawCircle(x - size / 4, 155, size / 15, WHITE);
		DrawCircle(x - size / 4, 135, size / 25, BLACK);
		DrawCircle(x - size / 4, 155, size / 25, BLACK);
	}


	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(BLACK);
		Rectangle background{25,30,550,250};

		DrawRectangleRounded(background, 0.05, 8, SKYBLUE);
		drawCells();
		drawPieces(model);
		//Sets UI text
		drawText(35, 40, "Frogs and Toads", 30, BLACK);
		drawText(35, 80, TextFormat(" Move using 1 to %d", BoardModel::BoardSize), 20, BLACK);
		drawText(420, 75, "R to restart", 20, BLACK);

		//Updates instruction text and lets the player know if they have lost or win.
		if (model.state() == BoardModel::GameState::Playing) {
			drawText(40, 240, "Choose a piece to move.", 30, DARKBLUE);

		}
		else if (model.state() == BoardModel::GameState::Solved) {
			drawText(40, 240, "Solved! R to restart.", 30, DARKGREEN);

		}
		else if (model.state() == BoardModel::GameState::Lost) {
			drawText(40, 240, "You lose! R to restart.", 30, RED);

		}
	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}