#include "MainWindow.h"
#include <qdebug.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <qdatetime.h>
using namespace cv;
MainWindow::MainWindow()
{
	ui.setupUi(this);
	connect(ui.btnStartRecord, &QPushButton::clicked, this, &MainWindow::startRecord);
	connect(ui.btnStopRecord, &QPushButton::clicked, this, &MainWindow::stopRecord);
	connect(ui.btnSnapshot, &QPushButton::clicked, this, &MainWindow::snapshot);
	connect(ui.btnConnect, &QPushButton::clicked, this, &MainWindow::snapshot);
	ui.btnSnapshot->setEnabled(false);
	ui.btnStartRecord->setEnabled(false);
	ui.btnStopRecord->setEnabled(false);
}

MainWindow::~MainWindow()
{
	destroyDevice();
}

void MainWindow::createDevice()
{
	hAttachedWindow = HWND(this->ui.label->winId());
	qDebug() << "QRETURN" << QCAP_CREATE("UB3300 USB", 0, hAttachedWindow, &pDevice, TRUE);
}

void MainWindow::destroyDevice()
{
	qDebug() << "QRESULT" << QCAP_DESTROY(pDevice);
}

void MainWindow::startRecord()
{
	QDir folderPath;
	if (!folderPath.mkpath(QString("./rec")))
	{
		qDebug() << "startRecord mkpath error";
	}
	if (startRecordFlag)
	{
		qDebug() << "RS set_audio_record_property:" << QCAP_SET_AUDIO_RECORD_PROPERTY(pDevice, 0, QCAP_ENCODER_TYPE_SOFTWARE, QCAP_ENCODER_FORMAT_AAC);
		qDebug() << "RS set_video_record_property:" << QCAP_SET_VIDEO_RECORD_PROPERTY(pDevice, 0, QCAP_ENCODER_TYPE_SOFTWARE, QCAP_ENCODER_FORMAT_H264, QCAP_RECORD_MODE_VBR, 8000, 0, 30, 0, 0, QCAP_DOWNSCALE_MODE_OFF);
		startRecordFlag = false;
	}
	qDebug() << "RS start record:" << QCAP_START_RECORD(pDevice, 0, "./rec/REC_%Y_%M_%D_%h_%m.MP4", QCAP_RECORD_FLAG_FULL, 0.0, 0.0, 0.0, 0, NULL);
	ui.btnStartRecord->setEnabled(false);
	ui.btnStopRecord->setEnabled(true);
}

void MainWindow::stopRecord()
{
	qDebug() << "RS stop record:" << QCAP_STOP_RECORD(pDevice, 0, FALSE, 0) << endl;
	ui.btnStartRecord->setEnabled(true);
	ui.btnStopRecord->setEnabled(false);
}

void MainWindow::snapshot()
{
	imgWindow = new ImgWindow();
	imgWindow->show();
	QString _time = QDateTime::currentDateTime().toString("yyMMdd/HHmmss");
	QString folderName = _time.section('/', 0, 0);
	qDebug() << folderName;
	QString fileHeader("./img/");
	fileHeader.append(folderName);
	QDir filepath;
	if (!filepath.mkpath(fileHeader))
	{
		qDebug() << "snapshot mkpath error";
	}
	QByteArray byteArray = QString("./img/%1.jpg").arg(_time).toLatin1();
	QCAP_SNAPSHOT_JPG(pDevice, byteArray.data(), 100);
}

void MainWindow::connectToCaptureCard()
{
	createDevice();
	QCAPRegister();
	QCAP_RUN(pDevice);
	ui.btnSnapshot->setEnabled(true);
	ui.btnStartRecord->setEnabled(true);
	ui.btnConnect->setEnabled(false);
}

void MainWindow::QCAPRegister()
{
	// 基本
	QCAP_REGISTER_NO_SIGNAL_DETECTED_CALLBACK(pDevice, no_signal_detected, this);
	QCAP_REGISTER_SIGNAL_REMOVED_CALLBACK(pDevice, signal_removed_detected, this);
	QCAP_REGISTER_FORMAT_CHANGED_CALLBACK(pDevice, signal_format_changed, this);
	// 注册音视频流回调函数
	QCAP_REGISTER_VIDEO_PREVIEW_CALLBACK(pDevice, video_preview_callback, this);
	QCAP_REGISTER_AUDIO_PREVIEW_CALLBACK(pDevice, audio_preview_callback, this);
	// 注册快照回调函数
	QCAP_REGISTER_SNAPSHOT_STREAM_CALLBACK(pDevice, on_snapshot_stream_callback, this);
	QCAP_REGISTER_SNAPSHOT_DONE_CALLBACK(pDevice, on_snapshot_done_callback, this);
}

void MainWindow::QCAPSetInputProperty()
{
	QCAP_SET_VIDEO_INPUT(pDevice, QCAP_INPUT_TYPE_HDMI);
	QCAP_SET_AUDIO_INPUT(pDevice, QCAP_INPUT_TYPE_EMBEDDED_AUDIO);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QPoint pos = event->pos();
		if (pos.x() > 640 || pos.y() > 480)
		{
			qDebug() << "mouse position out of range!";
			return;
		}
		p.x = pos.x(); p.y = pos.y();
		//qDebug() << p.x << p.y;
		stringstream stream;
		stream << p.x << "," << p.y;
		qDebug() << stream.str().c_str();
		switch (ui.comboBoxPos->currentIndex())
		{
		case 0:
			ui.lineEditPos0->setText(stream.str().c_str());
			break;
		case 1:
			ui.lineEditPos1->setText(stream.str().c_str());
			break;
		case 2:
			ui.lineEditPos2->setText(stream.str().c_str());
			break;
		case 3:
			ui.lineEditPos3->setText(stream.str().c_str());
			break;
		case 4:
			ui.lineEditPos4->setText(stream.str().c_str());
			break;
		default:
			break;
		}
	}
}

QRETURN no_signal_detected(PVOID pDevice, ULONG nVideoInput, ULONG nAudioInput, PVOID pUserData)
{
	qDebug() << "no_signal_detected was triggled";
	return QCAP_RT_OK;
}

QRETURN signal_removed_detected(PVOID pDevice, ULONG nVideoInput, ULONG nAudioInput, PVOID pUserData)
{
	qDebug() << "signal_removed_detected was triggled";
	return QCAP_RT_OK;
}

QRETURN signal_format_changed(PVOID pDevice,
	ULONG nVideoput,
	ULONG nAudioput,
	ULONG nVideoWidth,
	ULONG nVideoHeight,
	BOOL bVideoIsterleaved,
	double dVideoFrameRate,
	ULONG nAudioChannels,
	ULONG nAudioBitsPerSample,
	ULONG nAudioSampleFrequency,
	PVOID pUserData)
{
	if (nVideoWidth == 0 || nVideoHeight == 0)
		printf("NO SOURCE\n");
	qDebug() << "signal_format_changed was triggle!";
	return QCAP_RT_OK;
}
//bool i = true;
QRETURN video_preview_callback(PVOID pDevice,
	double dSampleTime,
	BYTE* pFrameBuffer,
	ULONG nFrameBufferLen,
	PVOID pUserData)
{
	if (pFrameBuffer == NULL || nFrameBufferLen == 0)
	{
		printf("NO DATA\n");
		return QCAP_RT_OK;
	}
	//process video data here
	//qDebug() << "nFrameBufferLen" << nFrameBufferLen;
	//if (i)
	//{
	MainWindow* m = (MainWindow*)pUserData;
	Mat src(480, 640, CV_8UC2, pFrameBuffer); //YUY2 YUV422Packed
	Mat dst(480, 640, CV_8UC3);
	cvtColor(src, dst, COLOR_YUV2BGR_YUY2);

	Vec3b bgr1 = dst.at<Vec3b>(m->p.y, m->p.x); // Mat是矩阵，先行后列
	float avg = (bgr1[0] + bgr1[1] + bgr1[2]) / 3.0;
	//qDebug() << "avg" << avg;
	float temperature = 31.0 / 256 * avg + 20.0;
	m->ui.lineEditTemperature0->setText(to_string(temperature).c_str());
	//qDebug() << temperature;
	//imwrite("./741816.jpg", dst);
		//i = false;
	//}
	return QCAP_RT_OK;
}

QRETURN audio_preview_callback(PVOID pDevice,
	double dSampleTime,
	BYTE* pFrameBuffer,
	ULONG nFrameBufferLen,
	PVOID pUserData)
{
	if (pFrameBuffer == NULL || nFrameBufferLen == 0) printf("NO DATA\n");
	//process audio data here
	//MainWindow* m = (MainWindow*)pUserData;

	return QCAP_RT_OK;
}

QRETURN on_snapshot_stream_callback(PVOID pDevice, CHAR* pszFilePathName, BYTE* pStreamBuffer, ULONG nStreamBufferLen, PVOID pUserData)
{
	if (pStreamBuffer == NULL || nStreamBufferLen == 0) printf("NO DATA\n");
	qDebug() << "nStreamBufferLen: " << nStreamBufferLen;
	//Mat src = imdecode(*pStreamBuffer, IMREAD_UNCHANGED);
	//imwrite("./1154.bmp", src);
	//QImage dst((unsigned char*)src.data, 1280, 958, QImage::Format_Grayscale8);
	return QCAP_RT_OK;
}

QRETURN on_snapshot_done_callback(PVOID pDevice, CHAR* pszFilePathName, PVOID pUserData)
{
	MainWindow* p = (MainWindow*)pUserData;
	qDebug() << pszFilePathName;
	p->imgWindow->pixmap = new QPixmap(pszFilePathName);
	//if (!pixmap.load(pszFilePathName)) qDebug() << "snapshot have not done";
	p->imgWindow->ui.label->setPixmap(*p->imgWindow->pixmap);
	return QCAP_RT_OK;
}
