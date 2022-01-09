#pragma once
#include <SFML/Graphics.hpp>

/*
Ce header contient tous les paramètres de notre simulation (à faire varier pour expérimentation !)
*/

// PARAMETRES FENETRE MENU
const unsigned int LARGEUR_FENETRE_MENU = 1600;
const unsigned int HAUTEUR_FENETRE_MENU = 750;
const char FENETRE_MENU[] = "Welcome to the Game Of Life !";
const std::string POLICE_MENU = "font/PlayMeGames-Demo.ttf";
const std::string POLICE_MENU2 = "font/Lobster_1.3.ttf";
const std::string BUTTON_IMG = "img/start.png";
const std::string BACKGROUNG_MENU = "img/menu.jpg";


// PARAMETRES FENETRE SIMULATION
const unsigned int LARGEUR_FENETRE = 1700;
const unsigned int HAUTEUR_FENETRE = 900;
const unsigned int FREQUENCE_RAFRAICHISSEMENT_IMG = 60;
const unsigned int TAILLE_POLICE = 24;
const std::string BACKGROUNG_IMG = "img/bg4.jpg";
const char FENETRE_JEU[] = "GameOfLife";
const std::string POLICE = "font/ComicRelief.ttf";
const sf::Vector2f POSITION_STATISTIQUE(5,5);
const sf::Vector2f POSITION_COMMANDE(1580,10);
const float EPAISSEUR_CERCLE = 1;

//PARAMETRES SONS 
const std::string WOLF_SOUND = "sound/wolf.ogg";
const std::string CLICK_SOUND = "sound/start.wav";
const std::string MENU_SOUND = "sound/epic.ogg";
const std::string GAME_SOUND = "sound/finalbattle.ogg";


// PARAMETRES ANIMAUX
const unsigned int NB_SHEEPS_DEBUT = 30;
const unsigned int NB_WOLVES_DEBUT = 8;
const float RAYON_SHEEP = 14;
const float RAYON_WOLF = 18;
const float RAYON_DEFAULT_ANIMAL = 10;
const unsigned int NB_PV_MAX_ANIMAL = 1000;
const float PROBA_REPRODUCTION_SHEEP = 0.3;
const float PROBA_REPRODUCTION_WOLF = 0.3;

// PARAMETRES FOOD
const unsigned int NB_FOODS = 12;
const unsigned int RAYON_FOOD = 6;

// PARAMETRES COULEURS
const sf::Color COULEUR_TXT_MENU(211, 146, 213);
const sf::Color COULEUR_TEXT = sf::Color::Black;
const sf::Color COULEUR_TXT_PLAY(211,238,245);
const sf::Color COULEUR_ANIMAL = sf::Color::Black;
const sf::Color COULEUR_SHEEP(247,42,24,250); //rouge
const sf::Color COULEUR_WOLF(33, 64,243,250); //bleu
const sf::Color COULEUR_NOURRITURE(72,247,24);// vert
const sf::Color COULEUR_BORDURE_CERCLE = sf::Color::Black;
