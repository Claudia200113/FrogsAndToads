#include "raylib_view.hpp"
#include <string>

namespace FrogToad {

	void RaylibView::drawCells() {
		float posX{ 50 };
		float mod{500 / BoardModel::BoardSize };

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			DrawRectangleLinesEx({ posX, 105, mod, 80 }, 4, WHITE);
			posX += mod;
		}
	}

	void RaylibView::setText(const float& posX, const float& posY, std::string& text) {
		Font font = GetFontDefault();

		DrawTextEx(font, text.c_str(), { posX, posY}, 20, 1.0f, BLACK);
	}

	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(BLACK);
		// TODO: Draw the board and game status.
		Rectangle background{25,30,550,250};


		DrawRectangleRounded(background, 0.05, 8, SKYBLUE);
		drawCells();
	}

	

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}
