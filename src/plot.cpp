#include "plot.hpp"
#include "constantes.hpp"

/**
 * Initialisation sheeps series
*/
void Plot::initSheepSeries()
{
    seriesSheeps = GetDefaultScatterPlotSeriesSettings();
    seriesSheeps->xs = &timeVect;
    seriesSheeps->ys = &sheepsVect;
    seriesSheeps->linearInterpolation = true;
    seriesSheeps->lineType = toVector(L"dashed");
    seriesSheeps->lineThickness = 2;
    seriesSheeps->color = GetGray(0.3);

}


/**
 * Initialisation wolves series
*/
void Plot::initWolvesSeries()
{
    seriesWolves = GetDefaultScatterPlotSeriesSettings();
    seriesWolves->xs = &timeVect;
    seriesWolves->ys = &wolvesVect;
    seriesWolves->linearInterpolation = true;
    seriesWolves->lineType = toVector(L"solid");
    seriesWolves->lineThickness = 2;
    seriesWolves->color = GetBlack();
}

/**
 * Paramètres du plot
*/
void Plot::initSettings()
{
    settings = GetDefaultScatterPlotSettings();
    settings->width = LARGEUR_PLOT;
    settings->height = HAUTEUR_PLOT;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = toVector(L"Results of the simulation : Black:Wolves Dashed:Sheeps");
    settings->xLabel = toVector(L"Time (seconds)");
    settings->yLabel = toVector(L"Number of animals");
    settings->scatterPlotSeries->push_back(seriesSheeps);
    settings->scatterPlotSeries->push_back(seriesWolves);

}

/**
 * Constructeur
*/
Plot::Plot()
{
    imageReference = CreateRGBABitmapImageReference();
    initSheepSeries();
    initWolvesSeries();
    initSettings();

}

/**
 * Destructeur
*/
Plot::~Plot()
{
    DeleteImage(imageReference->image);
}

/**
 * Mise à jour des vecteurs nécessaire au plot
 * @param time : temps à ajouter
 * @param nbSheeps : nombre de mouton à ajouter
 * @param nbWolves : nombre de loups à ajouter
*/
void Plot::update(const double time,const double nbSheeps, const double nbWolves)
{
    timeVect.push_back(time);
    sheepsVect.push_back(nbSheeps);
    wolvesVect.push_back(nbWolves);
}

/**
 * Enregistrer le plot au format PNG
*/
void::Plot::savePNG()
{
    DrawScatterPlotFromSettings(imageReference, settings);
    pngdataVect = ConvertToPNG(imageReference->image);
	WriteToFile(pngdataVect, NOM_PLOT);
}

/**
 * reset les vecteurs de nos données
*/
void Plot::reset()
{
    timeVect.clear();
    sheepsVect.clear();
    wolvesVect.clear();
}

/**
 * Draw the scatter plot to the target
*/


void Plot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile(NOM_PLOT);
    sprite.setTexture(texture);
    sprite.setPosition(PLOT_POSITION);
    target.draw(sprite);
}