#include<iostream>
#include "Transform.cpp"
#include "DepthCamera.h"
#include "PointCloud.h"
using namespace std;

int main() {


	//DepthCamera dp;
	//dp.setfileName("omer.txt");
	//dp.capture();
	//PointCloud pc;
	//pc.getPoint(10);




	Transform t1;

	Point p1;

	p1.setX(0);
	p1.setY(1);
	p1.setZ(0);

	t1.doTransform(p1);







	return 0;
}