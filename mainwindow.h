#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QLabel>
#include<QTimer>
#include<QSerialport>
#include<QSerialportinfo>
#include <QMessageBox>
#include<thread>
#include"flycam.h"
#include"ImageProcess.h"
#include<future>

using namespace std;
enum ArduinoCmd
{
	start,
	stop,
	CCW,
	CW
};


namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void ShowImage(QLabel * lbl, Mat ImageShow);
	//	FlyCam Cam;
	bool CheckSerialPortConnected();
	bool isCamOpen = false;
	uint m_frameCounter = 0;
	QTimer *timer1;
	QList<FlyCam*> CamList;
	QList<Mat> ImageList;

private slots:
	void on_btn_Start_clicked();
	void on_btn_Connect_clicked();
	void on_m_timer_update_trigger();
	void on_ckBox_CW_clicked();
	void on_ckBox_CCW_clicked();

	void  GetImage(int index,Mat frame);
	

	void on_serialPort1_DataRecieved();

	void on_btn_Stop_clicked();

	void on_btn_Capture_clicked();

	void on_btn_DisConnect_clicked();
	void on_btn_RefreshCom_clicked();
private:

	QSerialPort *serialPort1;
	void ComRefresh();
	Ui::MainWindow *ui;

	QByteArray cmd2Arduino;
	std::thread m_thread;
	QTimer *m_timer_update;
};

#endif // MAINWINDOW_H
