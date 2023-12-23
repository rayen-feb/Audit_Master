#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"videoplayerwidget.h"
int main(int argc, char *argv[])
{
    Connection c;
    bool test=c.createconnect();
    QApplication a(argc, argv);
    MainWindow w;


    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to continue."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
    QWidget  mainWindow;

    // Creating the video player widget.
    VideoPlayerWidget videoPlayerWidget(&mainWindow);

    // Creating a button to trigger video playback.
    QPushButton playButton("Play Video", &mainWindow);

    // Connecting the button's clicked signal to the playVideo slot of the video player widget.
    QObject::connect(&playButton, &QPushButton::clicked, [&videoPlayerWidget]() {
        videoPlayerWidget.playVideo("C:/Users/SOSORDINATEUR/Videos/Jeu.mp4");
    });

    // Setting up the layout for the main window.
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);
    layout->addWidget(&playButton);
    layout->addWidget(&videoPlayerWidget);

    // Setting the layout for the main window.
    mainWindow.setLayout(layout);

    // Showing the main window.
    mainWindow.show();

    // Executing the application event loop.
    return a.exec();


}
