#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

class Notification : public QSystemTrayIcon
{
    Q_OBJECT

public:
    Notification(QWidget *parent = nullptr) : QSystemTrayIcon(parent)
    {

        QIcon icon(":/C:.../.../.../.../logo.png");
        setIcon(icon);


        QMenu *trayMenu = new QMenu(parent);


        QAction *showNotificationAction = new QAction("Show Notification", parent);
        connect(showNotificationAction, &QAction::triggered, this, &Notification::showNotification);
        trayMenu->addAction(showNotificationAction);


        setContextMenu(trayMenu);
    }

public slots:
    void showNotification()
    {

        QMessageBox::information(nullptr, "done", "votre Rapport est terminer!");
    }
};

#endif // NOTIFICATION_H
