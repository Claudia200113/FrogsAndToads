#include "raylib_controller.hpp"
#include "raylib.h"
#include "board_layout.hpp"
#include <iostream>


namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {

		//KeyBoard inputs
		const int key = GetKeyPressed();
		int index{ 0 };

		if (key == KEY_R) {
			model.reset();
			return;
		}


		
		// Numbered keys select zero-based cells by subtracting '1'.
		// In this way, '1' maps to 0, '2' to 1, '3' to 2, etc.
		index = key - KEY_ZERO;
		model.tryMove(index - 1);


		//Mouse inputs
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			std::optional<int> index = BoardLayout::cellAt(GetMousePosition());
			if (index != std::nullopt) {
				model.tryMove(index.value());
			}
		//Prevents not valid input.
		}else if (key < KEY_ONE || key > KEY_NINE || key > KEY_ZERO + model.BoardSize) {
			//Adds KEY_ZERO due to the code is key contains.
			return;
		}
	}
}
