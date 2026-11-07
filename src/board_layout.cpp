#include "board_model.hpp"
#include "board_layout.hpp"
#include <cassert> // assert() in cellRect()

namespace FrogToad {
    Rectangle BoardLayout::board() {
        // TODO by You.
        return { Left, Top, BoardModel::BoardSize * CellSize, CellSize }; // Rectangle covering all cells.
    }

    Rectangle BoardLayout::cellRect(int index) {
        // Assert that the index is valid:
        assert(index >= 0 && index < BoardModel::BoardSize);
        return { Left + index * CellSize, Top, CellSize, CellSize }; // Calculated rectangle for cell at zero-based position index.
    }

    std::optional<int> BoardLayout::cellAt(Vector2 point) {
        Rectangle b = board();
        //First checks if the mouse is inside the board itself.
        if (CheckCollisionPointRec(point, b)) {
            //If inside the board, will check each individual cell. 
            for (int i = 0; i < BoardModel::BoardSize; i++) {
                Rectangle ib = cellRect(i);
                if (CheckCollisionPointRec(point, ib)) {
                    return i;
                }
            }
        }
        else {
            // Return nullopt only when the point is off the board.
            return std::nullopt;
        }
    }
}