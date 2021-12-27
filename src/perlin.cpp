#include "perlin.hpp"
using namespace Perlin;
// Implémentation du bruit de Perlin en 1D

/**
 * Fonction pour effectuer une interpolation linéaire entre a0 at a1
 * Le poid w doit être compris entre [0.0, 1.0].
 * 
 * @param a0
 * @param a1
 * @param w weight
 * @return interpolation entre a0 et a1
 */
float Perlin::interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * w + a0;
}

/**
 * Return un bruit aléatoire depuis t.
 * 
 * Pour plus d'info : https://cochoy-jeremy.developpez.com/tutoriels/2d/introduction-bruit-perlin/
 * 
 * @param t temps
 * @return float bruit aléatoire
 */
float Perlin::randNoise(int t)
{
    t = (t<<13) ^ t;
    t = (t * (t * t * 15731 + 789221) + 1376312589);
    return 1.0 - (t & 0x7fffffff) / 1073741824.0;
}

/**
 * Créer un bruit de Perlin au temps t.
 * 
 * @param t temps
 * @return float bruit aléatoire
 */
float Perlin::noise(float t)
{
    int t0 = (int)t;
    int t1 = t0 + 1;
    float sx = t - (float)t0;

    double n0 = randNoise(t0);
    double n1 = randNoise(t1);

    return interpolate(n0, n1, sx);
}
