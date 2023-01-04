/**
* @file PointCloudRecorder.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2022
* @brief PointCloud.h s�n�f� olu�turuldu.
*/
#pragma once
#include <iostream>
#include "PointCloud.h"
#include <list>
#include <iterator>
using namespace std;
/**
* @brief Constructor fonksiyonu olusturuldu
*/
PointCloud::PointCloud()
{
	pointNumber = 0;//varsay�lan atandi.


}


/**
* @brief Destructor fonksiyonu olusturuldu
*/
PointCloud::~PointCloud()
{
}
/**
* @brief set fonsiyonlari olusturuldu.
*/
void PointCloud::setPointX(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getX();
}

void PointCloud::setPointY(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getY();
}

void PointCloud::setPointZ(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getZ();
}

void PointCloud::setPointNumber(int pointNumber)
{
	this->pointNumber = pointNumber;
}

/**
* @brief point cloudun icindeki pointleri point objesi kullanarak�atayan foksiyon olusturuldu.
*/
void PointCloud::setPoint(list <Point> p)
{
	this->points = p;
}

double PointCloud::getPointX(int index)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getX();

}

double PointCloud::getPointY(int index)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getY();
}

double PointCloud::getPointZ(int index)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getZ();
}
/**
* @brief point cloudun icindeki pointleri point objesi kullanarak verilere�erisen foksiyon olusturuldu.
*/
list<Point> PointCloud::getPoint()const
{
	return points;
}

int PointCloud::getPointNumber()const
{
	return pointNumber;
}
/**
* @brief + operator fonsiyonu iki nokta bulutunun sahip oldu�u noktalara sahip tek bir nokta bulutunu d�nd�r�r
*/
PointCloud PointCloud::operator+(PointCloud pcl)
{
	list<Point> p1, p2;//point nesneleri liste g�nderilir.
	list<Point>::iterator iter1, iter2;//p1 ve p2 de gezinmek i�in yaz�lmistir.

	PointCloud sum;
	p1 = this->getPoint();
	p2 = pcl.getPoint();
	sum.setPointNumber(p1.size() + p2.size()); //noktalar toplan�r.
	iter1 = p1.begin();
	iter2 = p2.begin();
	for (int i = 0; i < p1.size() + p2.size(); i++)
	{
		if (i < p1.size())
		{
			sum.points.push_back(*iter1++);//p1 listesindeki eleman say�s� kadar toplan�r.
		}
		else
		{
			sum.points.push_back(*iter2++);////p2 listesindeki eleman say�s� kadar toplan�r.
		}
	}
	return sum;

}
/**
* @brief = operator fonsiyonu bu fonksiyon "pcl" nesnesinin "points" listesi i�indeki t�m ��eleri, "this" nesnesinin "points" listesine kopyalar.
*/
void PointCloud::operator=(PointCloud* pcl)
{

	list<Point>::iterator iter;
	for (iter = this->points.begin(); iter != this->points.end(); iter++)//listteki t�m �geleri d�nd�r�r
	{
		pcl->points.push_back(*iter);//point listesinin sonuna iterde bulunan �geyi ekler
	}
}
/**
* @brief deleteMovePoint fonsiyonu secilen pointi listeden silmek ve silinen pointten sonraki degerleri bir �ncekine tasiyan fonksiyondur.
*/

PointCloud PointCloud::deleteMovePoint(int index)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	this->points.erase(iter);
	return *this;
}

