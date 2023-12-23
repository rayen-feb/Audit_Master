#include "randomstringgenerator.h"
#include <QDebug>
#include <QTime>

void initializeRandomSeed() {
    QTime time = QTime::currentTime();
        qsrand(static_cast<uint>(time.msec()));
}

QString generateRandomString(int length) {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
      QString randomString;

      // Seed the random number generator
      qsrand(QTime::currentTime().msec());

      for (int i = 0; i < length; ++i) {
          int index = qrand() % possibleCharacters.length();
          QChar nextChar = possibleCharacters.at(index);
          randomString.append(nextChar);
      }

      qDebug() << "Generated Random String:" << randomString;

      return randomString;
    }
