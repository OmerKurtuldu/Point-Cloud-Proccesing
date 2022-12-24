#include "Transform.h"
#include "DepthCamera.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>



int main() {

	Transform t1, t2, t3, t4;

	Point p1;



	DepthCamera d1, d2, d3, d4;
	PointCloud pc1, pc2, pc3, pc4;

	ofstream cam1sonuc("cam1sonuc.txt");
	ofstream cam2sonuc("cam2sonuc.txt");
	ofstream cam3sonuc("cam3sonuc.txt");
	ofstream cam4sonuc("cam4sonuc.txt");


	d1.setfileName("cam.txt");
	d2.setfileName("cam1.txt");
	d3.setfileName("cam2.txt");
	d4.setfileName("cam3.txt");

	double array[9] = {
		  -0.7076050, 0.0065031, -0.7065783,
		   0.7066082, 0.0065134, -0.7075750,
		   0.0000008, -0.9999576, -0.0092041

	};
	double array2[9] = {
		  -0.6638364, -0.0068830, 0.7478462,
		  -0.7478778, 0.0061099, -0.6638082,
		  -0.0000002, -0.9999576, -0.0092036

	};
	double array3[9] = {
		 0.8762180, 0.0044351, -0.4818945,
		 0.4819149, -0.0080638, 0.8761809,
		 0.0000001, -0.9999577, -0.0092030

	};
	double array4[9] = {
		  0.3597052, -0.0085871, 0.9330265,
		 -0.9330660, -0.0033108, 0.3596900,
		  0.0000003, -0.9999576, -0.0092033

	};
	//cam1 icin
	pc1 = d1.capture();
	t1.setRotation(array);
	t1.setTrans(1.95704, 1.93000, 1.05707);
	t1.setTranslation();

	//cam2 icin
	pc2 = d2.capture();
	t2.setRotation(array2);
	t2.setTrans(-1.91288, 1.94412, 1.05465);
	t2.setTranslation();

	//cam3 icin
	pc3 = d3.capture();
	t3.setRotation(array3);
	t3.setTrans(1.96978, -1.94622, 1.05264);
	t3.setTranslation();

	//cam4 icin
	pc4 = d4.capture();
	t4.setRotation(array4);
	t4.setTrans(-1.87445, -1.95027, 1.06432);
	t4.setTranslation();



	pc1 = t1.doTransform(pc1);
	pc2 = t2.doTransform(pc2);
	pc3 = t3.doTransform(pc3);
	pc4 = t4.doTransform(pc4);



	for (int i = 0; i < pc1.getPointNumber(); i++) {
		cam1sonuc << pc1.getPointX(i) << " " << pc1.getPointY(i) << " " << pc1.getPointZ(i) << endl;



	}
	cam1sonuc.close();

	for (int i = 0; i < pc2.getPointNumber(); i++) {
		cam2sonuc << pc2.getPointX(i) << " " << pc2.getPointY(i) << " " << pc2.getPointZ(i) << endl;



	}
	cam2sonuc.close();

	for (int i = 0; i < pc3.getPointNumber(); i++) {
		cam3sonuc << pc3.getPointX(i) << " " << pc3.getPointY(i) << " " << pc3.getPointZ(i) << endl;



	}
	cam3sonuc.close();

	for (int i = 0; i < pc4.getPointNumber(); i++) {
		cam4sonuc << pc4.getPointX(i) << " " << pc4.getPointY(i) << " " << pc4.getPointZ(i) << endl;



	}
	cam4sonuc.close();



	return 0;


}