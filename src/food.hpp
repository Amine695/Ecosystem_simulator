#pragma once
#include <SFML/Graphics.hpp>

/*
Cette classe représente une nourriture
*/

class Food : public sf::CircleShape
{
    public:
        Food();
        ~Food();
        void move();
};