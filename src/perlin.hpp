#pragma once

/*
Ce header va permettre d'implémenter le bruit d'interpolation de Perlin en 1D (cf Rapport)
Le but étant de déplacer les animaux d'une manière naturelle d'une manière pseudo-aléatoire
Pour plus de détail : https://fr.wikipedia.org/wiki/Bruit_de_Perlin#Interpolation
*/

/**
 * Fonction pour interpoler linéairement entre a0 et a1
 * Le poids w doit être compris entre [0.0, 1.0]
*/
namespace Perlin 
{
    float interpolate(float a0, float a1, float w); 
    float randNoise(int t);
    float noise(float x);
}