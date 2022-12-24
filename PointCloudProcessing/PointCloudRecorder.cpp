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
void PointCloudRecorder::setFile(string& File)
{
	this->File = File;
}
/**
* @brief getFile fonksiyonu dosya ismini d�nd�r�r.
*/
string PointCloudRecorder::getFile()const
{
	return File;
}
/**
* @brief nokta bulutunu  dosyaya kaydeden fonksiyon olusturuldu.
*/
bool PointCloudRecorder::Save(const PointCloud& pc)const
{
	bool success = false;
	ofstream outputFile(File);
	if (outputFile.is_open()) {
		for (int i = 0; i < pc.getPointNumber(); ++i) {
			outputFile << pc.getPointX(i) << "\t" << pc.getPointY(i) << "\t" << pc.getPointZ(i) << "\n";
		}
		success = true;
	}

	return success;
}
