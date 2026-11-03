#include "board_model.hpp"
#include "board_layout.hpp"
#include <cassert> // assert() in cellRect()

namespace FrogToad {
    Rectangle BoardLayout::board() {
        // TODO by You.
        return { Left, Top, BoardModel::BoardSize * CellSize, CellSize }; // Replace with the rectangle covering all cells.
    }

    Rectangle BoardLayout::cellRect(int index) {
        // Assert that the index is valid:
        assert(index >= 0 && index < BoardModel::BoardSize);

        // TODO by You.
        return { Left + index * CellSize, Top, CellSize, CellSize }; // Replace with the calculated rectangle for cell at zero-based position index.
    }

    std::optional<int> BoardLayout::cellAt(Vector2 point) {
        // TODO by You. 
        Rectangle b = board();
        if (CheckCollisionPointRec(point, b)) {
            for (int i = 0; i < BoardModel::BoardSize; i++) {
                Rectangle ib = cellRect(i);
                if (CheckCollisionPointRec(point, ib)) {
                    return i;
                }
            }
        }
        else {
            // Return nullopt only when the point is off the board. You can use board() to detect this.
            return std::nullopt;
        }
    }
}