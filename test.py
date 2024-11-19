import sys
from BlenderWidget import QBlender
from PyQt5.QtWidgets import QApplication 



if __name__ == '__main__':
    app = QApplication(sys.argv)
    widget = QBlender()
    widget.show()
    sys.exit(app.exec_())