#pragma once
#include <SFML/Graphics.hpp>

/*
    Cette classe représente un animal
*/

class Animal: public sf::CircleShape
{
    private:
        float radius;
        float x, y; //position
        float tx, ty; //dérivés 
        float pv; // point vies 
        static float map(float value, float start1, float stop1, float start2, float stop2);

    public:
        Animal();
        ~Animal();
        void move(const float timeSpeed);
        bool isDead() const;
        void resetPv();
        static float distance(const sf::Vector2f a, const sf::Vector2f b);
};