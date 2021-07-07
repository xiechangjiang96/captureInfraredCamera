/*
 * @Date: 2021-07-06 14:42:29
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-07 09:47:18
 * @FilePath: \captureInfraredCamera\ImgLabel.cpp
 */
#include "ImgLabel.h"

ImgLabel::ImgLabel(QWidget* parent = nullptr) : QLabel(parent)
{
	pixmap = new QPixmap(640, 480);
	pixmap->fill(Qt::black);
	setPixmap(*pixmap);
}

void ImgLabel::paintEvent(QPaintEvent* paintEvent)
{
	// QPainter painter(this);
	// QPixmap pix(20, 20);
	// pix.fill(Qt::transparent);
	QPainter painterPix(pixmap);
	painterPix.drawEllipse(QPoint(10,10), 10, 10);
	// painter.drawPixmap(0, 0, *pixmap);
	setPixmap(*pixmap);
}