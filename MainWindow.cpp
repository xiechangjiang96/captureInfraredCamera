#include "MainWindow.h"
#include <qdebug.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <qdatetime.h>
MainWindow::MainWindow()
{
	ui.setupUi(this);
	imgWindow = new ImgWindow();
	connect(ui.btnStartRecord, &QPushButton::clicked, this, &MainWindow::startRecord);
	connect(ui.btnStopRecord, &QPushButton::clicked, this, &MainWindow::stopRecord);
	connect(ui.btnSnapshot, &QPushButton::clicked, this, &MainWindow::snapshot);
	connect(ui.btnConnect, &QPushButton::clicked, this, &MainWindow::connectToCaptureCard);
	ui.btnSnapshot->setEnabled(false);
	ui.btnStartRecord->setEnabled(false);
	ui.btnStopRecord->setEnabled(false);
	// coordinates of 5 points, pointer array
    QLineEdit* _lineEditContainer[5] = {ui.lineEditPos0, ui.lineEditPos1, ui.lineEditPos2, ui.lineEditPos3, ui.lineEditPos4};
	memcpy(lineEditPointPtr,_lineEditContainer,sizeof(QLineEdit*) * 5);
	// temperature of 5 points, pointer array
	QLineEdit* _lineEditTemperatureContainer[5] = {ui.lineEditTemperature0, ui.lineEditTemperature1, ui.lineEditTemperature2, ui.lineEditTemperature3, ui.lineEditTemperature4};
	memcpy(lineEditTemperaturePtr,_lineEditTemperatureContainer,sizeof(QLineEdit*) * 5);
	// query the number of active lineEdit of point coordinate
	queryNumActivePoint();
}

MainWindow::~MainWindow()
{
	if (!ui.btnConnect->isEnabled())
	{
		destroyDevice();
	}
}

void MainWindow::createDevice()
{
	hAttachedWindow = HWND(this->ui.labelMat->winId());
	qDebug() << "QRETURN" << QCAP_CREATE("UB3300 USB", 0, hAttachedWindow, &pDevice, TRUE);
}

void MainWindow::destroyDevice()
{
	qDebug() << "QRESULT" << QCAP_DESTROY(pDevice);
}

void MainWindow::startRecord()
{
	QDir folderPath;
	QString _time = QDateTime::currentDateTime().toString("yyMMdd");
	if (!folderPath.mkpath(QString("./rec/").append(_time)))
	{
		qDebug() << "startRecord mkpath error";
	}
	QByteArray recPath = QString("./rec/").append(_time).append("/REC_%Y_%M_%D_%h_%m.MP4").toLatin1();
	qDebug() << "RS start record:" << QCAP_START_RECORD(pDevice, 0, recPath.data(), QCAP_RECORD_FLAG_FULL, 0.0, 0.0, 0.0, 0, NULL);
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
	imgWindow->show();
	QString _time = QDateTime::currentDateTime().toString("yyMMdd/HHmmss");
	QString folderName = _time.section('/', 0, 0);
	// qDebug() << folderName;
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

void MainWindow:: connectToCaptureCard()
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
	// 鍩烘湰
	QCAP_REGISTER_NO_SIGNAL_DETECTED_CALLBACK(pDevice, no_signal_detected, this);
	QCAP_REGISTER_SIGNAL_REMOVED_CALLBACK(pDevice, signal_removed_detected, this);
	QCAP_REGISTER_FORMAT_CHANGED_CALLBACK(pDevice, signal_format_changed, this);
	// 娉ㄥ唽闊宠棰戞祦鍥炶皟鍑芥暟
	QCAP_REGISTER_VIDEO_PREVIEW_CALLBACK(pDevice, video_preview_callback, this);
	QCAP_REGISTER_AUDIO_PREVIEW_CALLBACK(pDevice, audio_preview_callback, this);
	// 娉ㄥ唽蹇収鍥炶皟鍑芥暟
	QCAP_REGISTER_SNAPSHOT_STREAM_CALLBACK(pDevice, on_snapshot_stream_callback, this);
	QCAP_REGISTER_SNAPSHOT_DONE_CALLBACK(pDevice, on_snapshot_done_callback, this);
	// 视频设置
	qDebug() << "RS set_audio_record_property:" << QCAP_SET_AUDIO_RECORD_PROPERTY(pDevice, 0, QCAP_ENCODER_TYPE_SOFTWARE, QCAP_ENCODER_FORMAT_AAC);
	qDebug() << "RS set_video_record_property:" << QCAP_SET_VIDEO_RECORD_PROPERTY(pDevice, 0, QCAP_ENCODER_TYPE_SOFTWARE, QCAP_ENCODER_FORMAT_H264, QCAP_RECORD_MODE_VBR, 8000, 0, 30, 0, 0, QCAP_DOWNSCALE_MODE_OFF);
}

void MainWindow::QCAPSetInputProperty()
{
	QCAP_SET_VIDEO_INPUT(pDevice, QCAP_INPUT_TYPE_HDMI);
	QCAP_SET_AUDIO_INPUT(pDevice, QCAP_INPUT_TYPE_EMBEDDED_AUDIO);
}

void MainWindow::queryNumActivePoint()
{
	numActivePoint = 0;
	for (int i = 0; i < 5; i++)
	{
		if (!(lineEditPointPtr[i]->text().isEmpty()))
		{
			numActivePoint++;
		}
	}
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		p = event->pos();
		if (p.x() > 640 || p.y() > 480)
		{
			qDebug() << "mouse position out of range!";
			return;
		}
		stringstream stream;
		stream << p.x() << "," << p.y();
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
		queryNumActivePoint();
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

int downsampleFlag = 0;
Scalar pointColor[5] = {Scalar(0,0,255), Scalar(0,255,0), Scalar(255,0,0), Scalar(0,85,170), Scalar(127,85,255)};

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
	if (downsampleFlag == 3)
	{
		downsampleFlag = 0;
		MainWindow* m = (MainWindow*)pUserData;
		Mat src(480, 640, CV_8UC2, pFrameBuffer); //YUY2 YUV422Packed
		Mat dst(480, 640, CV_8UC3);
		cvtColor(src, dst, COLOR_YUV2RGB_YUY2);

		for (int i = 0; i < m->numActivePoint; i++)
		{
			int c = m->lineEditPointPtr[i]->text().section(',',0,0).toInt();
			int r = m->lineEditPointPtr[i]->text().section(',',1,1).toInt();
			Vec3b bgr = dst.at<Vec3b>(r, c); // Mat是数组，先行后列
			circle(dst, Point(c, r), 3, pointColor[i]);
			// float avg = (bgr[0] + bgr[1] + bgr[2]) / 3.0;
			int lowerLimit = m->ui.lineEditFloor->text().toInt();
			int upperLimit = m->ui.lineEditCeil->text().toInt();
			int bandWidth = upperLimit - lowerLimit;
			float temperature = bandWidth / 256.0 * (bgr[0] + bgr[1] + bgr[2]) / 3.0 + lowerLimit;
			// // keep 3 decimal places
			// temperature = floor(temperature * pow(10, 2) + 0.5) / pow(10, 2);
			string temperatureStr = to_string(temperature);
			int location = temperatureStr.find('.');
			temperatureStr.erase(location + 3);
			m->lineEditTemperaturePtr[i]->setText(temperatureStr.c_str());
		}
		QImage tempImg (dst.data, 640, 480, QImage::Format_RGB888);
		QPixmap tempPix = QPixmap::fromImage(tempImg);
		m->ui.label->setPixmap(tempPix);
	}
	else
	{
		downsampleFlag++;
	}
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
	p->imgWindow->pixmap = new QPixmap(pszFilePathName);
	p->imgWindow->ui.label->setPixmap(*(p->imgWindow->pixmap));
	return QCAP_RT_OK;
}
