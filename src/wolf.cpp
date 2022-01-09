#include "wolf.hpp"
#include "constantes.hpp"
#include "rd_distrib.hpp"


//constructeur
Wolf::Wolf()
{
    this->setRadius(RAYON_WOLF);
    this->setFillColor(COULEUR_WOLF);
    this->setPointCount(4);
}

//destructeur
Wolf::~Wolf() {}


/**
 * Interaction Wolf vs Sheep
 * Lorsqu'un loup est près d'un mouton, le loup mange le mouton (oui je sais c'est cruelle mais c'est la nature).
 * Le loup obtient des points vie et le mouton est mort !
 * 
 * @param foods liste de moutons
 * @return return 1 si le mouton est tué, 0 sinon
 * 
 */
int Wolf::eat(std::list<Sheep> &sheeps)
{

    sf::Vector2f positionSheep;
    sf::Vector2f positionWolf;
    float d;
    for (std::list<Sheep>::iterator it = sheeps.begin(); it != sheeps.end(); it++)
    {
        positionSheep = it->getPosition();
        d = distance(positionWolf, positionSheep);
        if (d <= this->getRadius() + it->getRadius())
        {
            // Le loup mange le mouton
            resetPv();
            it = sheeps.erase(it);
            return 1;
        }
    }
    return 0;

}

/**
* Fonction pour l'interaction entre deux loups. Lorsqu'un loup est proche d'un autre, 
un nouveau loup est créer avec une certaine probabilité.
* @param wolf : un loup
* @return true si il y a un nouveau loup, false sinon.

*/

bool Wolf::reproduce(Wolf &wolf)const
{
    float d = distance(wolf.getPosition(), this->getPosition());
    return(d <= this->getRadius() && RAND_DISTRIBUTION(RANDOM_ENGINE) <= PROBA_REPRODUCTION_WOLF);
}

/**
* Operator + entre deux loups
* Return true si il y a une reproduction entre 2 loups
* @param wolf : un loup
* @return true si il y a nouveau wolf, false sinon
*/
bool Wolf::operator+(Wolf &wolf)const
{
    return this->reproduce(wolf);
}