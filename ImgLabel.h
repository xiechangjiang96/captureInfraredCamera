/*
 * @Date: 2021-07-06 14:42:21
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 15:23:23
 * @FilePath: \captureInfraredCamera\ImgLabel.h
 */
#pragma once
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
class ImgLabel : public QLabel
{
    Q_OBJECT
public:
    ImgLabel(QWidget* parent);
public:
    QPoint* p = nullptr;
    QPixmap* pixmap = nullptr;
protected:
    void paintEvent(QPaintEvent*);
};