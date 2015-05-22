#ifndef LINKOPERATE_H
#define LINKOPERATE_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "CommonSetting.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mman.h>

class LinkOperate : public QObject
{
    Q_OBJECT
public:
    explicit LinkOperate(QObject *parent = 0);
    ~LinkOperate();
    void OpenDevice();
    void BuzzerOn();
    void PowerLedOn();
    void RelayPowerOn();

public slots:
    void slotDoorState();
    void slotBuzzerOff();
    void slotPowerLedState();
    void slotRelayPowerOff();

public:
    int DoorFd;//防拆开关
    int BuzzerFd;//蜂鸣器
    int PowerLedFd;//电源指示灯
    int RelayFd;//开关量

    QTimer *DoorTimer;
    QTimer *BuzzerTimer;
    QTimer *PowerLedTimer;
    QTimer *RelayTimer;//用来控制继电器
};

#endif // LINKOPERATE_H
