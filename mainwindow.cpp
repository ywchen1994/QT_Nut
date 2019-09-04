#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{


	serialPort1 = new QSerialPort(this);
	m_timer_update = new QTimer(this);
	connect(m_timer_update, SIGNAL(timeout()), this, SLOT(on_m_timer_update_trigger()));
	connect(serialPort1, SIGNAL(readyRead()), this, SLOT(on_serialPort1_DataRecieved()));

	qRegisterMetaType<Mat>("Mat");



	ui->setupUi(this);
	ComRefresh();
	serialPort1->setBaudRate(QSerialPort::Baud57600);
	serialPort1->setDataBits(QSerialPort::DataBits::Data8);
	serialPort1->setParity(QSerialPort::NoParity);
	serialPort1->setStopBits(QSerialPort::StopBits::OneStop);
	cmd2Arduino.append('w'); cmd2Arduino.append('s'); cmd2Arduino.append('a'); cmd2Arduino.append('d');

	m_timer_update->start(30);
}

MainWindow::~MainWindow()
{
	delete ui;
}



void MainWindow::on_btn_Connect_clicked()
{
	FlyCam *Cam = new FlyCam(this);
	connect(Cam, SIGNAL(SendImage(int, Mat)), this, SLOT(GetImage(int, Mat)));
	Cam->cameraIndex = CamList.size();
	Cam->openCam(ui->cBox_Camera->currentIndex());
	Cam->cameraName = ui->cBox_Camera->currentText();
	Cam->start();
	CamList.append(Cam);
	ImageList.append(Mat::zeros(cv::Size(640, 480), CV_8UC3));

}

void MainWindow::on_m_timer_update_trigger()
{
	if (ImageList.size() == 1)
	{
		ShowImage(ui->label, ImageList[0]);

	}
	if (ImageList.size() == 2)
	{
		ShowImage(ui->label, ImageList[0]);
		ShowImage(ui->label_2, ImageList[1]);
	}
}


void MainWindow::on_btn_Start_clicked()
{
	if (CheckSerialPortConnected())
		serialPort1->write(&cmd2Arduino.data()[start], 1);
}
void MainWindow::ShowImage(QLabel *lbl, Mat ImageShow)
{

	if (!ImageShow.empty())
	{
		Mat tmp;
		cv::cvtColor(ImageShow, tmp, CV_BGR2RGB);
		cv::resize(tmp, tmp, cv::Size(lbl->width(), lbl->height()));
		QImage qimg((uchar*)tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888);
		lbl->setPixmap(QPixmap::fromImage(qimg));
	}
	lbl->update();
	lbl->repaint();
}



void MainWindow::on_ckBox_CW_clicked()
{
	if (ui->ckBox_CW->isChecked())
		ui->ckBox_CCW->setChecked(false);
	if (!ui->ckBox_CCW->isChecked() && !ui->ckBox_CW->isChecked())
		ui->ckBox_CW->setChecked(true);


	if (CheckSerialPortConnected())
		serialPort1->write(&cmd2Arduino.data()[CW], 1);
}

void MainWindow::on_ckBox_CCW_clicked()
{

	if (ui->ckBox_CCW->isChecked())
		ui->ckBox_CW->setChecked(false);
	if (!ui->ckBox_CCW->isChecked() && !ui->ckBox_CW->isChecked())
		ui->ckBox_CCW->setChecked(true);
	if (CheckSerialPortConnected())
		serialPort1->write(&cmd2Arduino.data()[CCW], 1);
}
bool MainWindow::CheckSerialPortConnected()
{
	if (!serialPort1->isOpen())
	{
		QString qstr = ui->cBox_PortName->currentText();
		if (qstr != "")
		{
			serialPort1->setPortName(qstr);
			serialPort1->open(QIODevice::ReadWrite);
			return true;
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Plz selsect ComPort");
			msgBox.show();
			return false;
		}
	}
	else
	{
		return true;
	}

}
void MainWindow::GetImage(int index, Mat frame)
{
	if (index < ImageList.size())
	ImageList[index] = frame.clone();

}


void MainWindow::on_serialPort1_DataRecieved()
{
	QByteArray buffer = serialPort1->readLine();
	if (buffer == "Done\r\n")
	{
		/*****************/

		Point2d intersect[6];
		vector<Vec4f> parameter;
		m_thread = std::thread(get_edgeLineParameter, ImageList[0], parameter);
		m_thread.join();

		//circleThread = std::thread(func(m_frame));


		serialPort1->write(&cmd2Arduino.data()[start], 1);
	}


}
void MainWindow::on_btn_Stop_clicked()
{
	if (CheckSerialPortConnected())
		serialPort1->write(&cmd2Arduino.data()[stop], 1);
}

void MainWindow::on_btn_Capture_clicked()
{
	imwrite(".\\ImageData\\" + to_string(m_frameCounter) + ".jpg", ImageList[ui->tabWidget->currentIndex()]);
	m_frameCounter++;

}

void MainWindow::on_btn_DisConnect_clicked()
{

	for (size_t i = 0; i < CamList.size(); i++)
	{
		if (ui->cBox_Camera->currentText() == CamList[i]->cameraName)
		{
			CamList[i]->m_stop = true;
			disconnect(CamList[i], SIGNAL(SendImage(int, Mat)), this, SLOT(GetImage(int, Mat)));

			CamList.removeAt(i);
			ImageList.removeAt(i);
			break;
		}

	}



}

void MainWindow::on_btn_RefreshCom_clicked() {
	ComRefresh();
}

void MainWindow::ComRefresh()
{
	ui->cBox_PortName->clear();
	ui->cBox_Camera->clear();

	foreach(const QSerialPortInfo &qspinfo, QSerialPortInfo::availablePorts())
	{
		ui->cBox_PortName->addItem(qspinfo.portName());

	}
	map<int, string> allCamList = getCameraInfo();
	for (map<int, string>::iterator iter = allCamList.begin(); iter != allCamList.end(); iter++)
	{
		ui->cBox_Camera->addItem(QString::fromStdString(iter->second));
	}
}

