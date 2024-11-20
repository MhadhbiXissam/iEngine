import sys
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPainter, QImage, QPaintEvent
from PyQt5.QtCore import Qt


class MyWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.image = QImage("apple-touch-icon-144x144-precomposed.png")  # Replace with your image path

    def paintEvent(self, event: QPaintEvent):
        painter = QPainter(self)
        if not self.image.isNull():
            painter.drawImage(0, 0, self.image)
        else:
            painter.drawText(self.rect(), Qt.AlignCenter, "Failed to load image")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = MyWidget()
    widget.resize(400, 300)
    widget.show()
    sys.exit(app.exec_())
