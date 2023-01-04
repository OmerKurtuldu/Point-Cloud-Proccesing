#include "ThreeDGridMap.h"
#include<iostream>

using namespace std;


ThreeDGridMap::ThreeDGridMap(int depth, double gridSize) : depth(depth), gridSize(gridSize) {
    // T�m k�plerin de�erini false yap
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                map[i][j][k] = false;
            }
        }
    }
}

//Set get fonksiyonlar�

void ThreeDGridMap::setDepth(int depth)
{
    this->depth = depth;
};

int ThreeDGridMap::getDepth() const
{

    return this->depth;

};

void ThreeDGridMap::setGridSize(double gridSize)
{

    this->gridSize = gridSize;


};

double ThreeDGridMap::getGridSize() const
{

    return this->gridSize;

};


//void ThreeDGridMap::insertPointCloud(PointCloud& pc) {
//    // PointCloud'taki her bir noktay� haritaya ekle
//    list <Point> p1;
//    p1 = pc.getPoint();
//
//    
//
//}

//void ThreeDGridMap::insertPoint(Point& p) {
//    // Noktan�n hangi k�pte oldu�unu hesapla
//    list<Point>::iterator iter;
//    
//    int i = iter./ gridSize;
//    int j = p.getY() / gridSize;
//    int k = p.getZ() / gridSize;
//
//    // K�p� true olarak i�aretle
//    map[i][j][k] = true;
//};


bool ThreeDGridMap::loadMap(const string& fileName) {
    // Haritay� dosyadan oku
    return true;
};


bool ThreeDGridMap::saveMap(const string& fileName) {

    // Haritay� dosyaya kaydet
    return true;
};


