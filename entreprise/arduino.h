#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>

class Arduino
{
    QSerialPort *serial;//=new QSerialPort();
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_product_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
public:

    Arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(int);
    QByteArray read_from_arduino();
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
private: slots
    void readdata();
};

#endif // ARDUINO_H
