#include "food.hpp"
#include "constantes.hpp"
#include "rd_distrib.hpp"

//constructeur
Food::Food()
{
    this->setOrigin(RAYON_FOOD,RAYON_FOOD);
    this->setRadius(RAYON_FOOD);
    this->setFillColor(COULEUR_NOURRITURE);
    this->setOutlineColor(COULEUR_BORDURE_CERCLE);
    this->setOutlineThickness(EPAISSEUR_CERCLE);
    move();
}

//destructeur
Food::~Food() {}


// Déplacer la nourriture de manière aléatoire
void Food::move()
{
    this->setPosition(X_DISTRIBUTION(RANDOM_ENGINE), Y_DISTRIBUTION(RANDOM_ENGINE));
}