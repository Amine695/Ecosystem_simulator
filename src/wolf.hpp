#pragma once 
#include <list>
#include "animal.hpp"
#include "sheep.hpp"

/*
Cette classe représente un loup (wolf), elle hérite de la classe Animal
*/

class Wolf : public Animal
{
    public:
        Wolf();
        ~Wolf();
        int eat(std::list<Sheep> &sheeps);
        bool reproduce(Wolf &wolf) const;
        bool operator+(Wolf &wolf) const;
};