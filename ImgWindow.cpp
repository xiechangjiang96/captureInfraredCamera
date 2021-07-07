/*
 * @Date: 2021-07-06 09:13:18
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-07 10:12:39
 * @FilePath: \captureInfraredCamera\ImgWindow.cpp
 */
#include "ImgWindow.h"
using namespace cv;
using namespace std;
ImgWindow::ImgWindow()
{
	ui.setupUi(this);
	pixmap = new QPixmap(640, 480);
	pixmap->fill(Qt::black);
	pen.setWidth(3);
	// pixmap = new QPixmap;
	// pixmap->load("test.jpg");
	// ui.label->setPixmap(*pixmap);
	// ui.label->p = &p;
	// ui.label->pixmap = pixmap;
	// QImage src;
	// QString str("./test.jpg");
	// qDebug() << src.load(str, "jpg");
	// //qDebug() << src.depth();
	// pixmap = &QPixmap::fromImage(src);
	// ui.label->setPixmap(*pixmap);
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
	QPoint pos = event->pos();
	qDebug() << "ImgWindow mouse point" << pos;
	if (event->button() == Qt::LeftButton)
	{
		if (pos.x() > 640 || pos.y() > 480)
		{
			qDebug() << "mouse position out of range!";
			return;
		}
		p = event->pos();
		update();
		displayMousePos(&p);
	}
}

void ImgWindow::paintEvent(QPaintEvent* event)
{
	// QPainter painter(this);
	// QPixmap pix(640, 480);
	// pix.fill(Qt::transparent);
	QPixmap copyPix = pixmap->copy();
	QPainter painterPix(&copyPix);
	painterPix.setPen(pen);
	painterPix.drawPoint(p);
	// painter.drawPixmap(0, 0, pix);
	ui.label->setPixmap(copyPix);
}