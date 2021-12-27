#include "sheep.hpp"
#include "constantes.hpp"
#include "rd_distrib.hpp"

//sheep constructeur
Sheep::Sheep()
{
    this->setRadius(RAYON_SHEEP);
    this->setFillColor(COULEUR_SHEEP);
}

//destructeur
Sheep::~Sheep() {}

/**
 * Fonction qui va permettre au moutons de manger (miam miam !)
 * Lorsqu'un mouton est près d'une nourriture, le mouton l'a mange.
 * Le mouton obtient des points vie et la nourriture disparaît !
 * 
 * @param foods liste de nourriture
 * @return return 1 si une nourriture est mangé, 0 sinon
 * 
 */
int Sheep::eat(std::list<Food> &foods)
{
    sf::Vector2f positionFood;
    sf::Vector2f positionSheep = this->getPosition();
    float d;
    for(std::list<Food>::iterator it = foods.begin(); it != foods.end(); ++it)
    {
        positionFood = it->getPosition();
        d = distance(positionSheep,positionFood);

        // si la distance entre le mouton et la nourriture
        // est plus petite que la somme du rayon du cercle et du 
        // rayon de la nourriture
        if(d <= this->getRadius() + it->getRadius())
        {
            // Le mouton mange la nourriture
            resetPv();
            it->move();
            return 1;

        }
    }

    return 0;
}

/**
* Fonction pour l'interaction entre deux moutons. Lorsqu'un mouton est proche d'un autre, 
un nouveau mouton est créer avec une certaine probabilité.
* @param sheep : un mouton
* @return true si il y a un nouveau mouton, false sinon.

*/
bool Sheep::reproduce(Sheep &sheep) const 
{
    float d = distance(sheep.getPosition(), this->getPosition());
    return (d <= this->getRadius() && RAND_DISTRIBUTION(RANDOM_ENGINE) <= PROBA_REPRODUCTION_SHEEP);
}

/**
* Operator + entre deux moutons
* Return true si il y a une reproduction entre 2 moutons
* @param sheep : un mouton
* @return true si il y a nouveau sheep, false sinon
*/
bool Sheep::operator+(Sheep &sheep)const
{
    return this->reproduce(sheep);
}