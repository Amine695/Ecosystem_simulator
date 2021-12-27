#pragma once
#include <list>
#include <SFML/Graphics.hpp>

/*
Cette classe représente un groupe d'animaux.
T doit avoir comme type Animal
*/

template<typename T>
class Animals : public sf::Drawable
{
    private:
        std::list<T> animals;
        unsigned int nbEaten;
        unsigned int nbBirths;
        void add(const unsigned int nbAnimals);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    public:
        Animals();
        ~Animals();
        std::list<T>* getList();
        unsigned int getNb() const;
        unsigned int getNbEaten() const;
        unsigned int getNbBirths() const;
        bool empty() const;
        template<typename U>
        void update(std::list<U> &eatList, const float timeSpeed);
        void init(const unsigned int nbAnimals);
};

/**
 * Ajouter un animal à la list
 * @param nbAnimals
*/
template<typename T>
void Animals<T>::add(const unsigned int nbAnimals)
{
    for(unsigned int i = 0; i < nbAnimals; i++)
        animals.emplace_back();
}


/**
 * Animals constructor
 */
template<typename T>
Animals<T>::Animals() : nbEaten(0), nbBirths(0) {}

/**
 * Animals destructor
 */
template<typename T>
Animals<T>::~Animals() {}

/**
 * Get the list of animals
 * 
 * @return list of animals
 */
template<typename T>
std::list<T>* Animals<T>::getList()
{
    return &animals;
}

/**
 * Get the number of animals
 * 
 * @return size of the list animals
 */
template<typename T>
unsigned int Animals<T>::getNb() const
{
    return animals.size();
}

/**
 * Get the number of objects eaten
 * 
 * @return number of objects eaten
 */
template<typename T>
unsigned int Animals<T>::getNbEaten() const
{
    return nbEaten;
}

/**
 * Get the number of births
 * 
 * @return number of births
 */
template<typename T>
unsigned int Animals<T>::getNbBirths() const
{
    return nbBirths;
}

/**
 * Return true if the list of animals is empty
 * 
 * @return true if size(animals) = 0
 */
template<typename T>
bool Animals<T>::empty() const
{
    return animals.empty();
}

/**
 * Update the animals
 * 
 * @param eatList objects to eat
 * @param timeSpeed speed of the simulation
 */
template<typename T>
template<typename U>
void Animals<T>::update(std::list<U> &eatList, const float timeSpeed)
{
    unsigned int nbNewAnimals = 0;
    for (auto it = animals.begin(); it != animals.end(); ++it)
    {
        // Move
        it->move(timeSpeed);
        // Eat
        nbEaten += it->eat(eatList);
        if (it->isDead())
        {
            // Remove animal
            it = animals.erase(it);
        }
        else {
            // Reproduce
            for (auto it2 = it; it2 != animals.end(); ++it2)
            {
                if ((it2 != it) && (*it + *it2))
                {
                    nbNewAnimals++;
                    break;
                }
            }
        }
    }
    nbBirths += nbNewAnimals;
    // Create new animals
    add(nbNewAnimals);
}

/**
 * Init the animals
 * 
 * @param nbAnimals number of animals
 */
template<typename T>
void Animals<T>::init(const unsigned int nbAnimals)
{
    animals.clear();
    add(nbAnimals);
    nbEaten = 0;
    nbBirths = 0;
}

/**
 * Draw animals to the target
 */
template<typename T>
void Animals<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto it = animals.begin(); it != animals.end(); ++it)
    {
        target.draw(*it);
    }
}