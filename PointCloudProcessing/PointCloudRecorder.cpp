/**
* @file PointCloudRecorder.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2022
* @brief nokta bulutlarini dosyaya kaydetme islemi
*/
#include "PointCloudRecorder.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
/**
* @brief Yapici fonsiyon olusturuldu.
*/
PointCloudRecorder::PointCloudRecorder()
{
}

/**
* @brief setFile fonksiyonu, PointCloudRecorder s�n�f�n�n fileName �zelli�ine bir dosya ad� atamas� yapar. Bu fonksiyon, kullan�c�n�n belirtti�i bir dosya ad�n� al�r ve fileName �zelli�ine atar.
*/
void PointCloudRecorder::setFile(string& fileName)
{
	this->fileName = fileName;
}
/**
* @brief getFile fonksiyonu dosya ismini d�nd�r�r.
*/
string PointCloudRecorder::getfileName()const
{
	return fileName;
}
/**
* @brief nokta bulutunu  dosyaya kaydeden fonksiyon olusturuldu.
*/
bool PointCloudRecorder::Save(PointCloud& pcl)const
{
	bool success = false;
	ofstream outputFile(fileName);
	if (outputFile.is_open()) {
		for (int i = 0; i < pcl.getPointNumber(); ++i) {
			outputFile << pcl.getPointX(i) << "\t" << pcl.getPointY(i) << "\t" << pcl.getPointZ(i) << "\n";
		}
		success = true;
	}

	return success;
}
