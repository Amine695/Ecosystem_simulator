#pragma once
#include <SFML/Graphics.hpp>
#include "pbPlots/pbPlots.hpp"
#include "pbPlots/supportLib.hpp"
/*
Cette classe va permettre de génerer des plots sur nos résultats grâce 
à la librairie pbPlots

Pour plus d'information : https://github.com/InductiveComputerScience/pbPlots
*/

class Plot : public sf::Drawable
{
    private:
        RGBABitmapImageReference *imageReference;
        ScatterPlotSeries *seriesSheeps;
        ScatterPlotSeries *seriesWolves;
        ScatterPlotSettings *settings;
        std::vector<double> timeVect;
        std::vector<double> sheepsVect;
        std::vector<double> wolvesVect;
        std::vector<double> *pngdataVect;
        void initSheepSeries();
        void initWolvesSeries();
        void initSettings();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    public:
        Plot();
        ~Plot();
        void update(const double time, const double nbSheeps, const double nbWolves);
        void savePNG();
        void reset();
};