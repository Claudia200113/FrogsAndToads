#include "raylib_controller.hpp"
#include "raylib.h"

namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {

		//KeyBoard inputs
			const int key = GetKeyPressed();
			int index{ 0 };

			if (key == KEY_R) {
				model.reset();
				return;
			}

			//Prevents not valid input.
			if(key < KEY_ONE || key > KEY_NINE || key > KEY_ZERO + model.BoardSize) {
				//Adds KEY_ZERO due to the code is key contains.
				return;
			}

			// Numbered keys select zero-based cells by subtracting '1'.
			// In this way, '1' maps to 0, '2' to 1, '3' to 2, etc.
			index = key - KEY_ZERO;
			model.tryMove(index - 1);

		//Mouse inputs
			if (IsMouseButtonPressed(1)) {
				Vector2 mousePos = GetMousePosition();
			}
	}
}
