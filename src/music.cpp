#include <iostream>
#include "music.hpp"
#include "constantes.hpp"

void Music::WolfMusic()
{
    if(!WolfSound.openFromFile(WOLF_SOUND))
        std::cerr << "Error !" << WOLF_SOUND << "can't be loaded" << std::endl;
    WolfSound.setLoop(true);
    WolfSound.setVolume(70);
    WolfSound.play();

}



void Music::StartMusic()
{
    if(!StartSound.openFromFile(CLICK_SOUND))
        std::cerr << "Error !" << CLICK_SOUND << "can't be loaded" << std::endl;
    StartSound.setVolume(70);
    StartSound.play();
}


void Music::MenuMusic()
{
    if(!MenuSound.openFromFile(MENU_SOUND))
        std::cerr << "Error !" << MENU_SOUND << "can't be loaded" << std::endl;
    MenuSound.setVolume(30);
    MenuSound.play();
}

void Music::MenuMusicStop()
{
    WolfSound.stop();
    MenuSound.stop();
}

void Music::inGameMusic()
{
    if(!GameSound.openFromFile(GAME_SOUND))
        std::cerr << "Error !" << GAME_SOUND << "can't be loaded" << std::endl;
    GameSound.setVolume(50);
    GameSound.setLoop(true);
    GameSound.play();
}
