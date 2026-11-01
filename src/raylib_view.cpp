#include "raylib_view.hpp"
#include <string>

namespace FrogToad {

	const float mod{500 / BoardModel::BoardSize };
	float cellStartPos{ 50 };
	
	//Draws only the outline from the cells 
	void RaylibView::drawCells() {

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			DrawRectangleLinesEx({ cellStartPos, 105, mod, 80 }, 4, WHITE);
			drawText(cellStartPos + mod/2, 200, TextFormat("%d", index+1), 20, BLACK);
			cellStartPos += mod;
		}
	}

	void RaylibView::drawText(const float& posX, const float& posY, const std::string text, const float& fontSize, const Color color) {
		Font font = GetFontDefault();

		DrawTextEx(font, text.c_str(), { posX, posY}, fontSize, 1.0f, color);
	}

	//Draws frogs and toads characters
	void RaylibView::drawPieces(const BoardModel& model) {

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
		drawText(35, 40, "Frogs and Toads", 30, BLACK);
		drawText(35, 80, TextFormat(" Move using 1 to %d", BoardModel::BoardSize), 20, BLACK);
		drawText(420, 75, "R to restart", 20, BLACK);

		if (model.state() == BoardModel::GameState::Playing) {
			drawText(40, 240, "Choose a piece to move.", 30, DARKBLUE);

		}
		else if (model.state() == BoardModel::GameState::Solved) {
			drawText(40, 240, "Solved! R to restart.", 30, DARKGREEN);

		}
		else if (model.state() == BoardModel::GameState::Lost) {
			drawText(40, 240, "Lost! R to restart.", 30, RED);

		}
	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }


	int checkMouseInput(Vector2 mouse) {
		int offset = cellStartPos;
		for (int i{ 0 }; i < BoardModel::BoardSize; ++i) {
			if (mouse.x >= offset && mouse.x > offset + mod && mouse.y > 105 || mouse.y < 185) {
				return i;
			}
			else {
				offset += mod;
			}
		}
		return 0;
	}
}



/*

		std::cout << resetStyles() << background() << clearScreen() << cursorHome() << hideCursor();
	}

	AnsiView::~AnsiView() {
		std::cout << resetStyles() << showCursor() << std::flush;
	}

	void AnsiView::draw(const BoardModel& model) {
		std::cout << cursorHome() << resetStyles() << background();

// Erase text left by a previous, longer frame.
std::cout << eraseAfter() << resetStyles() << std::flush;


*/