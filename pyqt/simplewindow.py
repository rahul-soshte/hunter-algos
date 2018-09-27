import sys
from PyQt4 import QtGui

app = QtGui.QApplication(sys.argv)

frame = QtGui.QMainWindow()
frame.setGeometry(200, 200, 1000, 1000)
frame.setWindowTitle('FrameTitle')
frame.showMaximized()
frame.show()

sys.exit(app.exec_())