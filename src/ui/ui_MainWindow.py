# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'MainWindow.ui'
##
## Created by: Qt User Interface Compiler version 6.4.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QAbstractItemView, QApplication, QHBoxLayout, QLayout,
    QListView, QMainWindow, QMenu, QMenuBar,
    QPushButton, QSizePolicy, QSpacerItem, QVBoxLayout,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.setWindowModality(Qt.NonModal)
        MainWindow.resize(760, 630)
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMinimumSize(QSize(0, 0))
        MainWindow.setMaximumSize(QSize(16777215, 16777215))
        MainWindow.setIconSize(QSize(128, 128))
        self.open_file = QAction(MainWindow)
        self.open_file.setObjectName(u"open_file")
        self.open_folder = QAction(MainWindow)
        self.open_folder.setObjectName(u"open_folder")
        self.edit_params = QAction(MainWindow)
        self.edit_params.setObjectName(u"edit_params")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        sizePolicy1 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.centralwidget.sizePolicy().hasHeightForWidth())
        self.centralwidget.setSizePolicy(sizePolicy1)
        self.centralwidget.setMaximumSize(QSize(1920, 1080))
        self.horizontalLayout = QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.horizontalLayout.setContentsMargins(4, 0, 4, 0)
        self.listView = QListView(self.centralwidget)
        self.listView.setObjectName(u"listView")
        self.listView.setMaximumSize(QSize(280, 16777215))
        font = QFont()
        font.setPointSize(10)
        self.listView.setFont(font)
        self.listView.setEditTriggers(QAbstractItemView.NoEditTriggers)

        self.horizontalLayout.addWidget(self.listView)

        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.last_button = QPushButton(self.centralwidget)
        self.last_button.setObjectName(u"last_button")
        self.last_button.setMinimumSize(QSize(100, 28))
        self.last_button.setMaximumSize(QSize(16777215, 24))
        font1 = QFont()
        font1.setPointSize(14)
        self.last_button.setFont(font1)

        self.horizontalLayout_2.addWidget(self.last_button)

        self.detect_button = QPushButton(self.centralwidget)
        self.detect_button.setObjectName(u"detect_button")
        self.detect_button.setMinimumSize(QSize(120, 28))
        self.detect_button.setMaximumSize(QSize(16777215, 24))
        self.detect_button.setFont(font1)

        self.horizontalLayout_2.addWidget(self.detect_button)

        self.next_button = QPushButton(self.centralwidget)
        self.next_button.setObjectName(u"next_button")
        self.next_button.setMinimumSize(QSize(100, 28))
        self.next_button.setMaximumSize(QSize(16777215, 24))
        self.next_button.setFont(font1)

        self.horizontalLayout_2.addWidget(self.next_button)


        self.verticalLayout.addLayout(self.horizontalLayout_2)

        self.verticalSpacer = QSpacerItem(20, 10, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.verticalLayout.addItem(self.verticalSpacer)


        self.horizontalLayout.addLayout(self.verticalLayout)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menuBar = QMenuBar(MainWindow)
        self.menuBar.setObjectName(u"menuBar")
        self.menuBar.setGeometry(QRect(0, 0, 760, 22))
        self.file_menu = QMenu(self.menuBar)
        self.file_menu.setObjectName(u"file_menu")
        self.file_menu.setMouseTracking(False)
        self.menu = QMenu(self.menuBar)
        self.menu.setObjectName(u"menu")
        MainWindow.setMenuBar(self.menuBar)

        self.menuBar.addAction(self.file_menu.menuAction())
        self.menuBar.addAction(self.menu.menuAction())
        self.file_menu.addAction(self.open_file)
        self.file_menu.addAction(self.open_folder)
        self.menu.addAction(self.edit_params)

        self.retranslateUi(MainWindow)
        self.detect_button.clicked.connect(MainWindow.detect)
        self.last_button.clicked.connect(MainWindow.last)
        self.next_button.clicked.connect(MainWindow.next)
        self.open_file.triggered.connect(MainWindow.open_file)
        self.open_folder.triggered.connect(MainWindow.open_folder)
        self.listView.clicked.connect(MainWindow.select)
        self.edit_params.triggered.connect(MainWindow.edit_params)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Detector", None))
        self.open_file.setText(QCoreApplication.translate("MainWindow", u"\u6253\u5f00\u6587\u4ef6", None))
        self.open_folder.setText(QCoreApplication.translate("MainWindow", u"\u6253\u5f00\u6587\u4ef6\u5939", None))
        self.edit_params.setText(QCoreApplication.translate("MainWindow", u"\u53c2\u6570", None))
        self.last_button.setText(QCoreApplication.translate("MainWindow", u"\u4e0a\u4e00\u5f20", None))
        self.detect_button.setText(QCoreApplication.translate("MainWindow", u"\u68c0\u6d4b", None))
        self.next_button.setText(QCoreApplication.translate("MainWindow", u"\u4e0b\u4e00\u5f20", None))
        self.file_menu.setTitle(QCoreApplication.translate("MainWindow", u"\u6587\u4ef6", None))
        self.menu.setTitle(QCoreApplication.translate("MainWindow", u"\u8bbe\u7f6e", None))
    # retranslateUi

