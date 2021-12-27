#include "foods.hpp"

//constructeur
Foods::Foods() {}

//destructeur
Foods::~Foods() {}

/**
 * Avoir la liste de nourritures
 * 
 * @return liste de nourritures
 */
std::list<Food>* Foods::getList()
{
    return &foods;
}

/**
 * Initialise la nourriture
 * 
 * @param nbFoods : nombre de nourritures
 */
void Foods::init(const unsigned int nbFoods)
{
    foods.clear();
    for (unsigned int i = 0; i < nbFoods; i++)
    {
        foods.emplace_back();
    }
}


/**
 * Draw la nourriture sur la cible(target)
 */
void Foods::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto it = foods.begin(); it != foods.end(); ++it)
    {
        target.draw(*it);
    }
}