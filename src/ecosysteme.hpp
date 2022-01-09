#pragma once
#include <list>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "sheep.hpp"
#include "wolf.hpp"
#include "animals.hpp"
#include "foods.hpp"
#include "music.hpp"

/*
Cette classe simule un écosystème 
*/

class Ecosystem : public Music
{
    private:
        sf::RenderWindow window;
        sf::Font font,font1,font2;
        sf::Text txt1,txt2,txt3,play,sheepText,WolfText,statText,commandText;
        sf::Texture bgGame,bgMenu,button;
        sf::Clock clock,clock1;
        Animals<Sheep> sheeps;
        Animals<Wolf> wolves;
        Foods foods;
        float timer;
        float timeSpeed;
        bool paused;
        bool finished;
        bool showStats;
        bool checkCursor(sf::FloatRect sprite,sf::Vector2f v);
        void initTextMenu();
        void initTextGame();
        void update();
        void drawStats();
        void drawCommands();
        void redraw();
        void restart();
    public:
        void savetoPNG();
        Ecosystem();
        ~Ecosystem();
        void runMenu();
        void runGame();



};