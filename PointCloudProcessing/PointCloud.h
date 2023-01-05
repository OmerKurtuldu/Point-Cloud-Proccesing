/**
* @file PointCloudTest.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aral�k 2022
* @brief Point.h s�n�f� olu�turuldu.
*/
#pragma once
#include "Point.h"
using namespace std;
#include <list>
#include <string>
#include <iterator>
class PointCloud
{
private:
	int pointNumber;
	list <Point> points;
public:
	PointCloud();
	~PointCloud();
	//Point s�n�f�ndan setPoint fonksiyonlar� al�nd�
	void setPointX(int, double);
	void setPointY(int, double);
	void setPointZ(int, double);
	void setPointNumber(int); //point cloudun icindeki pointleri point objesi kullanarak�setleyen foksiyon olusturuldu.
	void setPoint(list <Point>); // point class�ndaki indexi pointin indexine esitler.
	//Point s�n�f�ndan getPoint fonksiyonlar� al�nd� sabit kalmas� i�in const kullan�ld�.
	double getPointX(int);
	double getPointY(int);
	double getPointZ(int);
	list<Point> getPoint()const;////point cloudun icindeki pointleri point objesi kullanarak�objeye erisen foksiyon olusturuldu.
	int getPointNumber()const;//pointNumberi d�nd�r�r.
	PointCloud operator+(PointCloud); //iki nokta bulutunun sahip oldu�u noktalara sahip tek bir nokta bulutunu d�nd�r�r.
	void operator=(PointCloud* pcl); //bir nokta bulutunun ba�ka bir nokta bulutuna kopyalanmas�n� sa�lar.

	PointCloud deleteMovePoint(int);//secilen pointi listeden siler ve silinen pointten sonraki degerleri bir �ncekine tasir.

};

