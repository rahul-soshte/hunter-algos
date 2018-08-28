import sys
from PyQt4 import QtGui

app = QtGui.QApplication(sys.argv)

frame = QtGui.QMainWindow()
frame.setGeometry(200, 200, 600, 400)
frame.setWindowTitle('FrameTitle')

frame.show()

sys.exit(app.exec_())