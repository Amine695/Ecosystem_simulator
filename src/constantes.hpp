#pragma once
#include <SFML/Graphics.hpp>

/*
Ce header contient tous les paramètres de notre simulatio$n (à faire varier pour expérimentation !)
*/

// PARAMETRES FENETRE MENU
const unsigned int LARGEUR_FENETRE_MENU = 1400;
const unsigned int HAUTEUR_FENETRE_MENU = 973;
const char FENETRE_MENU[] = "Welcome to the Game Of Life !";
const std::string POLICE_MENU = "font/PlayMeGames-Demo.ttf";
const std::string POLICE_MENU2 = "font/Lobster_1.3.ttf";
const std::string BUTTON_IMG = "img/start.png";
const std::string BACKGROUNG_MENU = "img/bgmenu.jpg";


// PARAMETRES FENETRE SIMULATION
const unsigned int LARGEUR_FENETRE = 1700;
const unsigned int HAUTEUR_FENETRE = 900;
const unsigned int FREQUENCE_RAFRAICHISSEMENT_IMG = 60;
const unsigned int TAILLE_POLICE = 24;
const std::string BACKGROUNG_IMG = "img/nature.jpg";
const char FENETRE_JEU[] = "GameOfLife";
const std::string POLICE = "font/ComicRelief.ttf";
const sf::Vector2f POSITION_STATISTIQUE(5,5);
const sf::Vector2f POSITION_COMMANDE(5,HAUTEUR_FENETRE - 190);
const float EPAISSEUR_CERCLE = 1;

//PARAMETRES SONS 
const std::string WOLF_SOUND = "sound/wolf.ogg";
const std::string CLICK_SOUND = "sound/start.wav";
const std::string MENU_SOUND = "sound/epic.ogg";
const std::string GAME_SOUND = "sound/finalbattle.ogg";


// PARAMETRES ANIMAUX
const unsigned int NB_SHEEPS_DEBUT = 30;
const unsigned int NB_WOLVES_DEBUT = 8;
const float RAYON_SHEEP = 10;
const float RAYON_WOLF = 14;
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
const sf::Color COULEUR_TXT_PLAY(172,241,22);
const sf::Color COULEUR_ANIMAL = sf::Color::Black;
const sf::Color COULEUR_SHEEP(249, 148, 13,220);
const sf::Color COULEUR_WOLF(13, 30,249,180);
const sf::Color COULEUR_NOURRITURE(234, 233, 222);
const sf::Color COULEUR_BORDURE_CERCLE = sf::Color::Black;

// PARAMETRE PLOT RESULTAT
const double LARGEUR_PLOT = 900;
const double HAUTEUR_PLOT = 600;
const std::string NOM_PLOT = "plot/resultat.png";
const sf::Vector2f PLOT_POSITION((LARGEUR_FENETRE / 2.0) - (LARGEUR_PLOT / 2.0), (HAUTEUR_FENETRE / 2.0) - (HAUTEUR_PLOT / 2.0));
