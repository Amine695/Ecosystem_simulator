#pragma once
#include <random>
#include "constantes.hpp"

/*
Ce header contient nos distributions aléatoire 
*/

// moteur pour la génération des nombre aléatoires 
static std::random_device rd;
static std::default_random_engine RANDOM_ENGINE(rd());

//on veut générer nos nombres de manière uniforme entre 0 et 1000
static std::uniform_real_distribution<float> TIME_DISTRIBUTION(0,1000);
static std::uniform_real_distribution<float> X_DISTRIBUTION(0, LARGEUR_FENETRE);
static std::uniform_real_distribution<float> Y_DISTRIBUTION(0, HAUTEUR_FENETRE);
static std::uniform_real_distribution<float> RAND_DISTRIBUTION(0, 1);
