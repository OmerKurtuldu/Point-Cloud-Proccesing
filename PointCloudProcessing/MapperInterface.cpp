#include "MapperInterface.h";
#include "PointCloudRecorder.h";
#include "DepthCamera.h";
MapperInterface::MapperInterface()
{
	map = NULL;
	recorder = NULL;
}
MapperInterface::~MapperInterface()
{
	delete map;
	delete recorder;
}
void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
	generators.push_back(generator);
}

void MapperInterface::setRecorder(PointCloudRecorder* newRecorder)
{
	recorder = newRecorder;
}
/**
* @brief generators �yesinde bulunan t�m nesnelerden captureFor fonksiyonu �a�r�larak nokta bulutlar� sa�lan�r.
* Daha sonra her bir nokta bulutu pointCloud �yesine eklenir.
*/
bool MapperInterface::generate()
{
	for (vector<PointCloudGenerator*>::iterator generator = generators.begin(); generator != generators.end(); ++generator) {//generators �yesinde bulunan t�m nesneler itere edilir.
		patch = (*generator)->captureFor(); //generators �yesinde bulunan t�m nesnelerden captureFor fonksiyonu cagrilir.
		pointCloud.getPoint().insert(pointCloud.getPoint().end(), patch.getPoint().begin(), patch.getPoint().end());//points nesnesine direkt erisilemedigi icin getPoint kullanildi.
	}
	return true;//elde edilen her bir nokta bulutu pointCloud �yesine eklenir.
}
/**
* @brief recordPointCloud fonksiyonu pointCloud'u dosyaya ekleyen fonksiyondur.
*/
bool MapperInterface::recordPointCloud()
{
	if (recorder == NULL) {
		return false;
	}
	else {
		recorder->Save(pointCloud);//pointCloud'u dosyaya eklendi.
		return true;
	}
}
/**
* @brief recordMap fonksiyonu haritay� dosyaya kaydeden fonksiyondur.
*/

//bool MapperInterface::recordMap()
//{
//	PointCloudRecorder recorder;
//	recorder.setFile("map.txt");
//	PointCloud map;
//	map.setPoint(pointClouds);
//	return recorder.Save(map);//recorder.Save(map) fonksiyonu true de�erini d�nd�r�rse true d�ner.
//}


/**
* @brief insertMap fonksiyonu nokta bulutlar�n� haritaya isler.
*/
bool MapperInterface::insertMap()
{
	map->insertPointCloud(pointCloud);//pointcloduddaki nokta bulutunu map s�n�f�ndaki insertPointCloud fonksiyonuna g�nderir.
	return true;//g�ncellenirse true d�ner
}

//buray� s�ras� g�r�ns�n diye ekledim.
//int main() {
//    MapperInterface mapper;
//
//    PointCloudRecorder recorder;
//    3DGridMap map;
//    PointCloudGenerator generator;
//
//    mapper.generators.push_back(recorder);
//    mapper.generators.push_back(generator);
//
//    mapper.generate();
//    mapper.insertMap();
//    mapper.recordPointCloud();
//    mapper.recordMap();
//
//    return 0;
//}