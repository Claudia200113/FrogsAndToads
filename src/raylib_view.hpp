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
        void drawText(const float& posX, const float& posY, const std::string text, const float& fontSize,const Color color);
        void drawPieces(const BoardModel& model);
        void drawFrog(int x, int size);
        void drawToad(int x, int size);

        /** @brief Window width in pixels, available before view construction. */
        static int windowW();
        /** @brief Window height in pixels, available before view construction. */
        static int windowH();
    };
}
