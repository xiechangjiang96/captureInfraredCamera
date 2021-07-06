/*
 * @Date: 2021-07-06 14:42:29
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 14:48:12
 * @FilePath: \captureInfraredCamera\ImgLabel.cpp
 */
#include "ImgLabel.h"

ImgLabel::ImgLabel()
{

}

void ImgLabel::paintEvent(QPaintEvent* paintEvent)
{
	QPainter painter(this);
	QPixmap pix(640, 480);
	pix.fill(Qt::transparent);
	QPainter painterPix(&pix);
	painterPix.drawEllipse(p, 10, 10);
	painter.drawPixmap(0, 0, pix);
}