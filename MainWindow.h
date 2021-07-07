/*
 * @Date: 2021-07-06 09:13:18
 * @Author: Changjiang Xie
 * @LastEditor: Changjiang Xie
 * @LastEditTime: 2021-07-06 20:29:30
 * @FilePath: \captureInfraredCamera\MainWindow.h
 */
#pragma once
#include "C:\Qt\Qt5.12.5\5.12.5\msvc2017_64\include\QtWidgets\qmainwindow.h"
#include <QPushButton>
#include "ui_MainWindow.h"
#include "ImgWindow.h"
#include "QCAP.h"
#include <string>
#include <qdir.h>
#include <QThread>
using namespace std;

class MainWindow :
    public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
private slots:
    void createDevice();
    void destroyDevice();
    void startRecord();
    void stopRecord();
    void snapshot();
    void connectToCaptureCard();
private:
    void QCAPRegister();
    void QCAPSetInputProperty();
    void queryNumActivePoint();
protected:
    void mousePressEvent(QMouseEvent* event);
public:
    Ui::MainWindow ui;
    QLineEdit* lineEditPointPtr[5];
    QLineEdit* lineEditTemperaturePtr[5];

    HWND hAttachedWindow = nullptr;
    PVOID pDevice = nullptr;
    ImgWindow *imgWindow;
    bool isSnapshotDone = false;
    QPoint p;
    int numActivePoint = 0;
};

QRETURN no_signal_detected(PVOID pDevice, ULONG nVideoInput, ULONG nAudioInput, PVOID pUserData);
QRETURN signal_removed_detected(PVOID pDevice, ULONG nVideoInput, ULONG nAudioInput, PVOID pUserData);
QRETURN signal_format_changed(
    PVOID pDevice,
	ULONG nVideoput,
	ULONG nAudioput,
	ULONG nVideoWidth,
	ULONG nVideoHeight,
	BOOL bVideoIsterleaved,
	double dVideoFrameRate,
	ULONG nAudioChannels,
	ULONG nAudioBitsPerSample,
	ULONG nAudioSampleFrequency,
	PVOID pUserData);
QRETURN video_preview_callback(
    PVOID pDevice,
    double dSampleTime,
    BYTE* pFrameBuffer,
    ULONG nFrameBufferLen,
    PVOID pUserData);
QRETURN audio_preview_callback(
    PVOID pDevice,
    double dSampleTime,
    BYTE* pFrameBuffer,
    ULONG nFrameBufferLen,
    PVOID pUserData);
QRETURN on_snapshot_stream_callback(
    PVOID pDevice, 
    CHAR* pszFilePathName,
    BYTE* pStreamBuffer,
    ULONG nStreamBufferLen,
    PVOID pUserData);
QRETURN on_snapshot_done_callback(
    PVOID pDevice,
    CHAR* pszFilePathName,
    PVOID pUserData);
