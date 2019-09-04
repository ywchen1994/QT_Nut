#include "flycam.h"

FlyCam::FlyCam(QObject *parent) : QObject(parent)
{

}
bool FlyCam::openCam(int index)
{
	try
	{
		FlyCapture2::Error err;
		BusManager busMgr;
		PGRGuid guid;
		err = busMgr.GetCameraFromIndex(index, &guid);
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));

		err = camera.Connect(&guid);
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));

		
		/*	FlyCapture2::Format7ImageSettings fset;
			fset.height = 1500;
			fset.mode = MODE_0;
			fset.offsetX = 288;
			fset.offsetY = 274;
			fset.pixelFormat = PIXEL_FORMAT_MONO8;
			fset.width = 1472;
			fset.pixelFormat = UNSPECIFIED_PIXEL_FORMAT;
			err = camera.SetFormat7Configuration(&fset, (uint)5520);*/
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
		err = camera.StartCapture();
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));

	}
	catch (const std::string e)
	{
		cerr << e << endl;
		assert(0);
	}
	return true;
}





void FlyCam::run()
{
	while (!m_stop)
	{
		try
		{
			m_mutex.lock();
			Image rawImage;
			FlyCapture2::Error err = camera.RetrieveBuffer(&rawImage);
			if (err != PGRERROR_OK)
				throw exception(err.GetDescription());
			Image rgbImage;

			rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
			unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows();
			emit SendImage(cameraIndex,cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes).clone());
			m_mutex.unlock();
		
		}
		catch (const std::string e)
		{
			cerr << e << endl;
			assert(0);
		}
	}
	camera.StopCapture();
	QMutexLocker locker(&m_mutex);
	m_stop = true;
	sleep(500);
}
