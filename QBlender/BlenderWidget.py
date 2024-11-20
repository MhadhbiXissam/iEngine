import sys
import threading
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPainter, QImage
from PyQt5.QtWidgets import QWidget, QApplication
import grpc
from concurrent import futures
import blender_pb2
import blender_pb2_grpc


class ImageService(blender_pb2_grpc.ImageServiceServicer):
    def __init__(self, update_callback):
        self.update_callback = update_callback

    def ReceiveImage(self, request, context):
        # Convert the received image data into an image
        image_data = request.image_data

        # Use the callback to update the GUI with the image
        self.update_callback(image_data)
        return blender_pb2.ImageResponse(message="Image received and GUI updated.")


class QBlender(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('PyQt5 Paint Event Example with Image Fitting')
        self.setGeometry(100, 100, 400, 300)

        # Initialize variables to hold the image
        self.image = None
        self.framebuffer = None

        # Start the gRPC server in a separate thread
        self.server_thread = threading.Thread(target=self.run_server, daemon=True)
        self.server_thread.start()

    def run_server(self):
        def update_gui(image_data):
            print(image_data)
            # Convert the raw image data to a QImage
            self.framebuffer = QImage.fromData(image_data)
            print(self.framebuffer)
            # Scale the image to fit the widget using FastTransformation for better clarity
            self.image = self.framebuffer.scaled(
                self.size(), Qt.IgnoreAspectRatio, Qt.FastTransformation
            )
            # Trigger a repaint of the widget
            self.update()

        server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        blender_pb2_grpc.add_ImageServiceServicer_to_server(
            ImageService(update_gui), server
        )
        server.add_insecure_port('[::]:50051')
        server.start()
        server.wait_for_termination()

    def resizeEvent(self, event):
        # Rescale the image to fit the widget when the window is resized
        if self.framebuffer:
            self.image = self.framebuffer.scaled(
                self.size(), Qt.IgnoreAspectRatio, Qt.FastTransformation
            )
        self.update()
        super().resizeEvent(event)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        # Clear the canvas
        painter.fillRect(self.rect(), Qt.white)

        # If an image is available, draw it centered in the widget
        if self.image:
            x = (self.width() - self.image.width()) // 2
            y = (self.height() - self.image.height()) // 2
            painter.drawImage(x, y, self.image)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    widget = QBlender()
    widget.show()
    sys.exit(app.exec_())

