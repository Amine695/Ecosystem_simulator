#pragma once

/*
Ce header va permettre d'implémenter le bruit d'interpolation de Perlin en 1D (cf Rapport)
Le but étant d'avoir un meilleur effet visuel de notre jeu.
Pour plus de détail : https://fr.wikipedia.org/wiki/Bruit_de_Perlin#Interpolation
*/

namespace Perlin 
{
    float interpolate(float a0, float a1, float w); 
    //Fonction pour interpoler linéairement entre a0 et a1 
    // Le poids w doit être compris entre [0.0, 1.0]
    float randNoise(int t);
    float noise(float x);
}