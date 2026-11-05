#pragma once
#include <optional> // std::optional &  std::nullopt in cellAt()
#include "raylib.h"

namespace FrogToad {
    /** @brief Pixel geometry of the game board. Used by both RaylibView and RaylibController.
      *
      * All methods are static and so are called like this: Rectangle cell{ FrogToad::BoardLayout::cellRect(3) };
      * Some methods will need to query the model. See cellRect for a use of BoardModel::BoardSize
      */
    struct BoardLayout {
        static constexpr float CellSize = 520 / BoardModel::BoardSize; // Allows size to adapt to the number of cells declared on the model.
        static constexpr float Left = 40.0f;     // Window x coord of the board's left edge.
        static constexpr float Top = 105.0f;      // Window y coord of the board's top edge.

        /** @brief Raylib screen rectangle that perfectly wraps all N cells. */
        static Rectangle board();

        /** @brief Screen rectangle of a zero-based cell. Assertion: The index must be valid. */
        static Rectangle cellRect(int index);

        /** @brief Zero-based cell under a point, or nullopt if the point is off the board.
         *
         * Example @code
         * if (std::optional<int> cell{ FrogToad::BoardLayout::cellAt(GetMousePosition()) }) {
         *     std::cout << "The mouse is over cell " << *cell << "!\n";
         * } else {
         *     std::cout << "The mouse is not over a cell.\n";
         * }
         * @endcode
         */
        static std::optional<int> cellAt(Vector2 point);
    };
}
