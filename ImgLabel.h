/*
 * @Date: 2021-07-06 14:42:21
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 14:42:21
 * @FilePath: \captureInfraredCamera\ImgLabel.h
 */
#pragma once
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
class ImgLabel : public QLabel
{
    Q_OBJECT
public:
    ImgLabel();
protected:
    void paintEvent(QPaintEvent*);
};