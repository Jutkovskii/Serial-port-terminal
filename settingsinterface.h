#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QObject>
#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "portsettings.h"

class SettingsInterface : public QObject
{
    Q_OBJECT
    SettingsWindow window;
    PortSettings settings;
public:
    explicit SettingsInterface(QObject *parent = nullptr);

signals:
    void sendSettings(PortSettings);
public slots:
    void getDataBits(int option);
    void getStopBits(int option);
    void getParity(int option);
    void send();
    void show();
    void hide();
};

#endif // SETTINGSINTERFACE_H
