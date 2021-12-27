#pragma once
#include <SFML/Audio.hpp>

/*
Cette classe s'occupe de la partie audio du jeu, pour le rendre plus immersif !
*/

class Music
{
    protected:
        sf::Music WolfSound;
        sf::Music StartSound;
        sf::Music GameSound;
        sf::Music MenuSound;
        
    public:
        void WolfMusic();
        void MenuMusicStop();
        void MenuMusic();
        void inGameMusic();
        void StartMusic();
};