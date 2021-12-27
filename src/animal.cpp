#include <cmath>
#include "animal.hpp"
#include "constantes.hpp"
#include "perlin.hpp"
#include "rd_distrib.hpp"

/**
 * Re-maps a number from one range to another.
 * 
 * Inspiré par : https://processing.org/reference/map_.html
 * 
 * @param value the incoming value to be converted
 * @param start1 lower bound of the value's current range
 * @param stop1 upper bound of the value's current range
 * @param start2 lower bound of the value's target range
 * @param stop2 upper bound of the value's target range
 * @return float
 * 
 */

float Animal::map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * (value - start1) / (stop1 - start1);
}

//constructeur
Animal::Animal(): radius(RAYON_DEFAULT_ANIMAL), pv(NB_PV_MAX_ANIMAL)
{
    //variables de temps
    tx = TIME_DISTRIBUTION(RANDOM_ENGINE);
    ty = TIME_DISTRIBUTION(RANDOM_ENGINE);

    //création cercle
    this->setOrigin(radius,radius);
    this->setRadius(radius);
    this->setFillColor(COULEUR_ANIMAL);
    this->setOutlineColor(COULEUR_BORDURE_CERCLE);
    this->setOutlineThickness(EPAISSEUR_CERCLE);
    this->setPosition(x,y);

}

//destructeur
Animal::~Animal() {}

// bouger l'animal en utilisant le bruit de Perlin
// timeSpeed représente la vitesse de la simulation
void Animal::move(const float timeSpeed)
{
    x = map(Perlin::noise(tx), -1, 1, 0, LARGEUR_FENETRE);
    y = map(Perlin::noise(ty), -1, 1, 0, HAUTEUR_FENETRE);
    this->setPosition(x,y);
    tx += 0.01 * timeSpeed;
    ty += 0.01 * timeSpeed;
    pv -= timeSpeed;


}

//fonction bool qui retourne True si l'animal n'as plus de points vie (pv), 
//false sinon
bool Animal::isDead() const
{
    return pv <= 0;
}

//fonction qui reset le nombre de PV
void Animal::resetPv()
{
    pv = NB_PV_MAX_ANIMAL;
}

/**
return la distance entre deux points de la fenêtre
* @param a : vecteur représentant le premier point
* @param b : vecteur représentant le second point
* @return Distance euclidienne entre ces deux points
*/
float Animal::distance(const sf::Vector2f a, const sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));

}

