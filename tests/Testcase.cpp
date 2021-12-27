// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <list>

//src's headers
#include "animals.hpp"
#include "sheep.hpp"
#include "foods.hpp"
#include "rd_distrib.hpp"
#include "ecosysteme.hpp"
#include "perlin.hpp"


TEST_CASE("1: Tests on Animals")
{
    Animals<Sheep> sheeps,wolves;
    REQUIRE(sheeps.empty());
    REQUIRE(wolves.empty());
    REQUIRE(sheeps.getNb() == 0);
    REQUIRE(wolves.getNb() == 0);
    REQUIRE(sheeps.getNbEaten() == 0);
    REQUIRE(wolves.getNbEaten() == 0);
    REQUIRE(sheeps.getNbBirths() == 0);
    REQUIRE(wolves.getNbBirths() == 0);
    wolves.init(10);
    sheeps.init(30);
    REQUIRE(sheeps.getNb() == 30);
    REQUIRE(wolves.getNb() == 10);
    REQUIRE_FALSE(sheeps.empty());

}

TEST_CASE("2: Tests on Foods")
{
    Foods foods;
    foods.init(12);
    REQUIRE(foods.getList()->size() == 12);
}

TEST_CASE("3: Tests on Random distribution")
{
    float n;
    for(size_t i = 0; i < 100; i++)
    {
        n = RAND_DISTRIBUTION(RANDOM_ENGINE);
        REQUIRE((0 <= n && n <= 1));
    }
}

TEST_CASE("4: Tests on Perlin Noise")
{
    float n;
    for(size_t i = 0; i < 100; i++)
    {
        n = Perlin::noise(i);
        REQUIRE((-1 <= n && n <= 1));
    }
}

