#pragma once
#include <list>
#include "animal.hpp"
#include "food.hpp"

/*
Cette classe représente un mouton (sheep), elle hérite de la classe Animal
*/

class Sheep : public Animal {

    public:
        Sheep();
        ~Sheep();
        int eat(std::list<Food> &foods);
        bool reproduce(Sheep &sheep) const;
        bool operator+(Sheep &sheep) const;

};