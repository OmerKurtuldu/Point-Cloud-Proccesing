#include "Map.h"
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

Map::Map(){

}

Map::~Map()
{
}
/**
* @brief getPointClouds fonksiyonu map s�n�f�n�n pointClouds vekt�r�n�n kopyas�n� al�p parametre olarak ald��� pointClouds vekt�r�ne kopyalar.
*/

void Map::getPointClouds(vector<PointCloud> pointClouds)
{
    pointClouds = this->pointClouds;

}
/**
* @brief setPointClouds fonksiyonu parametre olarak ald��� pointClouds vekt�r�n� Map s�n�f�n�n pointClouds vekt�r�ne atar
*/

void Map::setPointClouds(vector<PointCloud> pointClouds)
{
    this->pointClouds = pointClouds;
}
/**
* @brief insertPointCloud fonksiyonu PointCloud s�n�f�ndan bir nesnenin Map s�n�f�n�n pointClouds vekt�r�ne eklenmesini sa�lar. 
*/

void Map::insertPointCloud(PointCloud& pc)
{
    this->pointClouds.push_back(pc);
}
/**
* @brief insertPointCloud fonksiyonu parametre olarak ald��� p de�i�kenini Map s�n�f�n�n points vekt�r�ne push_back ile ekler. 
*/
void Map::insertPoint(Point& p)
{
    this->points.push_back(p);
}
/**
* @brief loadMap fonksiyonu, harita verisi i�eren bir dosyay� okuyarak Map s�n�f�n�n �yelerini doldurmay� sa�lar.
*/
bool Map::loadMap(std::string fileName)
{
	return false;
}
/**
* @brief saveMap fonksiyonu fileName dosyas�na haritan�n pointCloud nesnelerini kaydeder.
*/

bool Map::saveMap(std::string fileName)
{
    ofstream mapFile(fileName);
    if (mapFile.is_open())
    {
        for (int i = 0; i < pointClouds.size(); ++i)
        {
            for (int j = 0; j < pointClouds[i].getPointNumber(); ++j)
            {
                mapFile << pointClouds[i].getPointX(j) << "\t" << pointClouds[i].getPointY(j) << "\t" << pointClouds[i].getPointZ(j) << "\n";
            }
        }
        return true;
    }
    else {
        cout << "Dosya ac�lamad� kontrol edin!!" << endl;
        return false;
        
    }
    
}
