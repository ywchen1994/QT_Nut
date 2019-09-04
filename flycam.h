#ifndef FLYCAM_H
#define FLYCAM_H

#include <QObject>
#include<QThread>
#include<QMutex>
#include"FlyCapture2.h"

#include<opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>

using namespace FlyCapture2;
using namespace std;
using namespace cv;
static map<int, string> getCameraInfo()
{
	map<int, string> mCam_Info;
	FlyCapture2::Error error;

	BusManager busMgr;

	unsigned int numCameras;
	Camera* pCameras;
	try
	{
		error = busMgr.GetNumOfCameras(&numCameras);
		if (error != PGRERROR_OK)throw string(error.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
		pCameras = new Camera[numCameras];

		for (unsigned int i = 0; i < numCameras; i++)
		{
			PGRGuid guid;
			error = busMgr.GetCameraFromIndex(i, &guid);
			if (error != PGRERROR_OK)throw string(error.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));


			// Connect to a camera
			error = pCameras[i].Connect(&guid);
			if (error != PGRERROR_OK)throw string(error.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
			
			// Get the camera information
			CameraInfo camInfo;
			error = pCameras[i].GetCameraInfo(&camInfo);
			mCam_Info.insert(pair<int, string>(i, camInfo.modelName));
			if (error != PGRERROR_OK)throw string(error.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
			pCameras[i].Disconnect();
			
		}
		delete[]pCameras;
		return mCam_Info;
	}
	catch (const std::string e)
	{
		delete[]pCameras;
	}
}
class FlyCam : public QObject, public QThread
{
	Q_OBJECT
public:
	explicit FlyCam(QObject *parent = nullptr);
	bool m_stop = false;
	bool openCam(int index = 0);
	void run();
	int cameraIndex=-1;
	QString cameraName;

signals:
	void SendImage(int,Mat);
public slots:
private:
	Camera camera;
	QMutex m_mutex;
};

#endif // FLYCAM_H
