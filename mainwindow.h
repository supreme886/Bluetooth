#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "switchbutton.h"
#include "deviceinfoitem.h"
#include "bluetoothagent.h"

#include <QtBluetooth/qbluetoothdeviceinfo.h>
#include <QtBluetooth/qbluetoothaddress.h>
#include <QtBluetooth/qbluetoothtransferrequest.h>
#include <QtBluetooth/qbluetoothtransferreply.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothdevicediscoveryagent.h>
#include <QtBluetooth/qbluetoothservicediscoveryagent.h>
#include <QtBluetooth/qbluetoothserviceinfo.h>
#include <polkit-qt5-1/PolkitQt1/Authority>


#include <KF5/BluezQt/bluezqt/adapter.h>
#include <KF5/BluezQt/bluezqt/manager.h>
#include <KF5/BluezQt/bluezqt/initmanagerjob.h>
#include <KF5/BluezQt/bluezqt/device.h>
#include <KF5/BluezQt/bluezqt/agent.h>
#include <KF5/BluezQt/bluezqt/pendingcall.h>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QFrame>
#include <QSystemTrayIcon>
#include <QFont>
#include <QMetaType>
#include <QSizePolicy>
#include <QWidget>
#include <QScrollArea>
#include <QMenu>
#include <QTimer>

class SwitchButton;

using namespace PolkitQt1;

namespace BluezQt
{
extern void bluezqt_initFakeBluezTestRun();
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void InitMainTopUI();
    void InitMainbottomUI();
    void startDiscovery();
    void InitTray();
    ~MainWindow();
protected:

private slots:
    void onClick_Open_Bluetooth(bool);
    void serviceDiscovered(BluezQt::DevicePtr);

    void receiveConnectsignal(BluezQt::DevicePtr);
//    void receive
    void bluetoothPairError(QBluetoothLocalDevice::Error);
    void pairingDisplayPinCode(QBluetoothAddress,QString);
    void pairingDisplayConfirmation(QBluetoothAddress,QString);
    void pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing);

    void Refresh_load_Label_icon();
private:
    QVBoxLayout *main_layout;
    QSystemTrayIcon * tray;
    QWidget *main_widget;
    QWidget *frame_top;
    QWidget *frame_bottom;
    QLabel *bluetooth_name;

    QVBoxLayout *bottom_layout;
    QScrollArea *device_area;
    QWidget *device_list;
    QVBoxLayout *device_list_layout;

//    QBluetoothLocalDevice *m_localDevice;
    BluetoothAgent *Agent;
    BluezQt::Manager *m_manager;
    BluezQt::InitManagerJob  *job;
    BluezQt::AdapterPtr m_localDevice;

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;

    SwitchButton *open_bluetooth;
    SwitchButton *show_panel;

    QSystemTrayIcon *pSystemTray;

    QLabel *loadLabel;
    QTimer *m_timer;
    int i = 7;
};
#endif // MAINWINDOW_H
