/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "SingletonTest.h"
#include "QGCLoggingCategory.h"
#include "QGCToolbox.h"
#include "QGCApplication.h"
#include "SettingsManager.h"
#include "PositionManager.h"
#include <QTime>
#include <QDateTime>
#include <QLocale>
#include <QQuaternion>

#include <Eigen/Eigen>



#include <QDebug>

SingletonTest::SingletonTest():_toolbox                      (qgcApp()->toolbox())
{
_mavlink = _toolbox->mavlinkProtocol();
connect(_mavlink, &MAVLinkProtocol::messageReceived,        this, &SingletonTest::_mavlinkMessageReceived);
}
SingletonTest::~SingletonTest()
{
}
void SingletonTest::_mavlinkMessageReceived(LinkInterface* link, mavlink_message_t message)
{
switch (message.msgid) {
case MAVLINK_MSG_ID_GPS_RAW_INT:
    _handleGpsRawInt(message);
    break;
}

}
void SingletonTest::_handleGpsRawInt(mavlink_message_t& message)
{
mavlink_gps_raw_int_t gpsRawInt;
mavlink_msg_gps_raw_int_decode(&message, &gpsRawInt);
_test1=QString::number(gpsRawInt.lat/ (double)1E7);
emit test1Changed();
}

void SingletonTest::setTest1(QString   test1)
{
    _test1=test1;
    emit test1Changed();
}


