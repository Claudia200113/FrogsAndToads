#include "raylib_controller.hpp"
#include "raylib.h"

namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {
		// TODO (student): Implement non-blocking keyboard input.
			/*static_assert(BoardModel::BoardSize <= 9,
				"Single-character commands support at most nine board cells.");*/

			const int key = GetKeyPressed();
			int index{ 0 };

			if (key == KEY_R) {
				model.reset();
				return;
			}

			if(key < KEY_ONE || key > KEY_NINE || key > KEY_ZERO + BoardModel::BoardSize) {
				return;
			}

			// Numbered keys select zero-based cells by subtracting '1'.
			// In this way, '1' maps to 0, '2' to 1, '3' to 2, etc.
			index = key - KEY_ZERO;
			model.tryMove(index - 1);
	}
}
