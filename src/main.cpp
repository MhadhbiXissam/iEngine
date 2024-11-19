#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <rfb/rfbclient.h>
class MyWidget : public QWidget {
public:
    rfbClient* cl;
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Load the image
        image = QImage();
    }
    void connect2Vnc(){
        cl = rfbGetClient(8, 3, 4);
        cl->format.depth = 24;
        cl->format.depth = 16;
        cl->format.bitsPerPixel = 16;
        cl->format.redShift = 11;
        cl->format.greenShift = 5;
        cl->format.blueShift = 0;
        cl->format.redMax = 0x1f;
        cl->format.greenMax = 0x3f;
        cl->format.blueMax = 0x1f;
        cl->appData.compressLevel = 9;
        cl->appData.qualityLevel = 1;
        cl->appData.encodingsString = "tight ultra";
        cl->FinishedFrameBufferUpdate = nullptr;
        cl->serverHost = strdup("127.0.0.1");
        cl->serverPort = 5910;
        cl->appData.useRemoteCursor = TRUE;
    }
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Draw the image
        if (!image.isNull()) {
            painter.drawImage(0, 0, image);
        } else {
            painter.drawText(rect(), Qt::AlignCenter, "Failed to load image");
        }
    }

private:
    QImage image;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.connect2Vnc() ; 
    widget.resize(400, 300);
    widget.show();

    return app.exec();
}
