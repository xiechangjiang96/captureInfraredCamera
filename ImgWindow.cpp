/*
 * @Date: 2021-07-06 09:13:18
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 10:00:08
 * @FilePath: \captureInfraredCamera\ImgWindow.cpp
 */
#include "ImgWindow.h"
using namespace cv;
using namespace std;
ImgWindow::ImgWindow()
{
	ui.setupUi(this);
	//QString str("./731921.jpg");
	//src.load(str, "jpg");
	//qDebug() << src.depth();
	//QPixmap pixmap = QPixmap::fromImage(src);
	//ui.label->setPixmap(pixmap);
	//ui.label->setAlignment(Qt::AlignLeft & Qt::AlignTop);
}

//void ImgWindow::getSize()
//{
//	qDebug() << ui.gridLayout->cellRect(0, 0);
//	qDebug() << ui.gridLayout->cellRect(0, 1);
//}

void ImgWindow::displayMousePos(QPoint* pos)
{
	stringstream stream;
	stream << pos->x() << "," << pos->y();
	ui.lineEditPos->setText(stream.str().c_str());
	grayscaleMapToTemperature(pos);
}

void ImgWindow::grayscaleMapToTemperature(QPoint* pos)
{
	QRgb rgb = pixmap->toImage().pixel(*pos);
	qDebug() << hex << rgb;
	k = 8;
	decToHex(rgb);
	qDebug() << "decToHex: " << result;
	int r = arrayToIntHH(result[2]) * 16 + arrayToIntHH(result[3]);
	int g = arrayToIntHH(result[4]) * 16 + arrayToIntHH(result[5]);
	int b = arrayToIntHH(result[6]) * 16 + arrayToIntHH(result[7]);
	qDebug() << r << g << b;
	float avg = (r + g + b) / 3.0;
	float temperature = 31.0 / 256 * avg + 20;
	ui.lineEdiTemperature->setText(to_string(temperature).c_str());
}

void ImgWindow::decToHex(unsigned int n)
{
	if (n < 16)
	{
		result[--k] = digit[n];
		return;
	}
	result[--k] = digit[n % 16];
	decToHex(n / 16);
}

int ImgWindow::arrayToIntHH(char c)
{
	for (int i = 0; i < 16; i++)
	{
		if (digit[i] == c)
		{
			return i;
		}
	}
	return -1;
}

void ImgWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QPoint pos = event->pos();
		if (pos.x() > 640 || pos.y() > 480)
		{
			qDebug() << "mouse position out of range!";
			return;
		}
		displayMousePos(&pos);
	}
}