/*
 * @Date: 2021-07-06 09:13:18
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 10:00:17
 * @FilePath: \captureInfraredCamera\ImgWindow.h
 */
#pragma once
#include <qwidget.h>
#include <QMouseEvent>
#include "ui_ImgWindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <qdebug.h>

class ImgWindow :
    public QWidget
{
    Q_OBJECT
public:
    ImgWindow();
private:
    void displayMousePos(QPoint* pos);
    void grayscaleMapToTemperature(QPoint* pos);
    void decToHex(unsigned int n);
    int arrayToIntHH(char c);
private:
    //QImage src;
    char digit[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    char result[8];
    int k = 8;
public:
    QPixmap* pixmap;
    Ui::Form ui;
protected:
    void mousePressEvent(QMouseEvent* event);
};