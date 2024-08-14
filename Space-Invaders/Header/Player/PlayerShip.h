#pragma once
#include<SFML/Graphics.hpp>

namespace Player {
    class PlayerController;
    class PlayerShip {
    private:
        PlayerController* player_controller;
    public:

        PlayerShip();
        ~PlayerShip();

        void initialize();
        void update();
        void render();

    };
}