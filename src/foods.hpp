#pragma once
#include <SFML/Graphics.hpp>
#include "food.hpp"
#include <list>

/*
Cette classe représente un groupe de nourriture
*/

class Foods : public sf::Drawable
{
    private:
        std::list<Food> foods;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    public:
        Foods();
        ~Foods();
        std::list<Food>* getList();
        void init(const unsigned int nbFoods);
};