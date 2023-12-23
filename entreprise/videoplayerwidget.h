#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>

/**
* @class VideoPlayerWidget
* Represents a widget that can play videos using Qt's multimedia framework.
*/
class VideoPlayerWidget : public QWidget {
private:
    QMediaPlayer* mediaPlayer; // The media player object for video playback.
    QVideoWidget* videoWidget; // The video widget for displaying the video.

public:
    /**
    * Constructs a VideoPlayerWidget.
    *
    * @param parent The parent widget.
    */
    VideoPlayerWidget(QWidget* parent = nullptr) : QWidget(parent) {
        // Creating the media player and video widget.
        mediaPlayer = new QMediaPlayer(this);
        videoWidget = new QVideoWidget(this);

        // Setting up the layout for the widget.
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(videoWidget);

        // Setting the layout for the widget.
        setLayout(layout);

        // Setting the video output for the media player.
        mediaPlayer->setVideoOutput(videoWidget);
    }

    /**
    * Loads and plays a video file.
    *
    * @param filePath The path to the video file.
    */
    void playVideo(const QString& filePath) {
        // Loading the video file into the media player.
        mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));

        // Playing the video.
        mediaPlayer->play();
    }
};
#endif // VIDEOPLAYERWIDGET_H
