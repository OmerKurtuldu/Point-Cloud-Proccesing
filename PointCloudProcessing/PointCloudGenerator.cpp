#include "PointCloudGenerator.h"
#include"Transform.h"

//PointCloudGenerator i�in yap�c�(constructor) fonskiyonu
PointCloudGenerator::PointCloudGenerator()
{

}
//Setleme i�lem yapar parametre olarak transform nesnesin�i al�r bu classdaki transforma kopyalar
void PointCloudGenerator::setTransform(Transform tr) {

	transform = tr;
}
// bu fonksiyon transform nesnesini d�nd�r�r
Transform PointCloudGenerator::getTransform() {

	return transform;

}
