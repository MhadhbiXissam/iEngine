#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <thread>
#include <rfb/rfbclient.h>

class VncViewer : public QWidget {
    Q_OBJECT
public:
    VncViewer(QWidget *parent = nullptr) : QWidget(parent), cl(nullptr), m_vncThread(nullptr) {}
    ~VncViewer() { if (m_vncThread && m_vncThread->joinable()) m_vncThread->join(); }

    void start(const std::string &serverIp, int serverPort) {
        cl = rfbGetClient(8, 3, 4);
        cl->serverHost = strdup(serverIp.c_str());
        cl->serverPort = serverPort;
        cl->FinishedFrameBufferUpdate = finishedFramebufferUpdateStatic;
        rfbClientSetClientData(cl, nullptr, this);

        if (rfbInitClient(cl, nullptr, nullptr)) {
            m_startFlag = true;
            m_vncThread = new std::thread(this {
                while (m_startFlag) {
                    if (WaitForMessage(cl, 500) < 0 || !HandleRFBServerMessage(cl)) {
                        m_startFlag = false;
                        rfbClientCleanup(cl);
                    }
                }
            });
        }
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(this->rect(), m_image);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (m_startFlag) {
            SendPointerEvent(cl, event->x(), event->y(), event->buttons() & Qt::LeftButton);
        }
    }

private:
    static void finishedFramebufferUpdateStatic(rfbClient *cl) {
        VncViewer *viewer = static_cast<VncViewer*>(rfbClientGetClientData(cl, nullptr));
        viewer->finishedFramebufferUpdate(cl);
    }

    void finishedFramebufferUpdate(rfbClient *cl) {
        m_image = QImage(cl->frameBuffer, cl->width, cl->height, QImage::Format_RGB16);
        update();
    }

    bool m_startFlag = false;
    QImage m_image;
    rfbClient *cl;
    std::thread *m_vncThread;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    VncViewer viewer;
    viewer.start("127.0.0.1", 5910);
    viewer.show();
    return app.exec();
}
