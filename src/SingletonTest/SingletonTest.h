/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QThread>
#include <QTcpSocket>
#include <QGeoCoordinate>
#include <QUrl>
#include "Vehicle.h"
#include "Drivers/src/rtcm.h"
#include "RTCM/RTCMMavlink.h"
#include "QGCApplication.h"
#include "MAVLinkInspectorController.h"
#include "MultiVehicleManager.h"

class SingletonTest : public QObject{
    Q_OBJECT

public:
    SingletonTest();
    virtual ~SingletonTest();
    Q_PROPERTY(QString          test1     READ test1   WRITE setTest1   NOTIFY test1Changed)
    Q_PROPERTY(bool          isboat     READ isboat   WRITE setIsboat   NOTIFY isboatChanged)
    // QGCTool overrides
    QString         test1           ()
    {
        return _test1;
    }
    bool         isboat           ()
    {
        return _isboat;
    }
    void setTest1(QString   test1);
    void setIsboat(bool   isboat);
signals:
    void    test1Changed();
    void    isboatChanged();
public slots:

private slots:
void _mavlinkMessageReceived            (LinkInterface* link, mavlink_message_t message);
    void send_mavlink();

private:
    void _handleGpsRawInt            (mavlink_message_t& message);
    void _handleADSBVehicle            (mavlink_message_t& message);
    void _handlesensor            (mavlink_message_t& message);
    QTimer timer;
    //Vehicle*      _vehicle;
    QmlObjectListModel* _vehiclelist;
    QGCToolbox*         _toolbox = nullptr;
    MAVLinkProtocol*    _mavlink = nullptr;
    QString  _test1="A";
    bool _isboat="true";

};
