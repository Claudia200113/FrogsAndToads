#pragma once
#include "interfaces.hpp"
#include "raylib.h"
#include <string>


namespace FrogToad {
    /**
     * @brief Presents the board with Raylib (student exercise).
     * Construct after InitWindow() and destroy before CloseWindow(); load textures
     * once in the constructor and unload them in the destructor.
     */
    class RaylibView : public IView {
    public:
        /** @brief Render the current model using already loaded resources. */
        void draw(const BoardModel& model) override;
        void drawCells();
        void setText(const float& posX, const float& posY, std::string& tex);

        /** @brief Window width in pixels, available before view construction. */
        static int windowW();
        /** @brief Window height in pixels, available before view construction. */
        static int windowH();
    };
}
