#include "qrwidget.h"
#include <QPainter>
#include <QDebug>
#include "qrcode.h"

using qrcodegen::QrCode;
using qrcodegen::QrSegment;

qrwidget::qrwidget(QWidget *parent) :
    QWidget(parent),
    data("Hello QR")//Note: The encoding fails with empty string so I just default to something else. Use the setQRData() call to change this.
{}

void qrwidget::paintEvent(QPaintEvent *pe){
    qDebug() <<"hewo";
    (void)*pe;
    QPainter painter(this);
    //NOTE: I have hardcoded some parameters here that would make more sense as variables.


    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(data.toStdString().c_str(), qrcodegen::QrCode::Ecc::LOW);
    const int s=qr.getSize()>0?qr.getSize():1;
    const double w=sz->width();
    const double h=sz->height();
    const double aspect=w/h;
    const double size=((aspect>1.0)?h:w);
    const double scale=size/(s+2);
    // NOTE: For performance reasons my implementation only draws the foreground parts in supplied color.
    // It expects background to be prepared already (in white or whatever is preferred).
    painter.setPen(Qt::NoPen);
    painter.setBrush(*fg);
    for(int y=0; y<s; y++) {
        for(int x=0; x<s; x++) {
            const int color=qr.getModule(x, y);  // 0 for white, 1 for black
            if(0!=color) {
                const double rx1=(x+1)*scale, ry1=(y+1)*scale;
                QRectF r(rx1, ry1, scale, scale);
                painter.drawRects(&r,1);
            }
        }
    }
}
