/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication3.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION3_H
#define UI_QTGUIAPPLICATION3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication3Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonAceptar;
    QPushButton *pushButtonAbrir;
    QSlider *horizontalSliderLumi;
    QLineEdit *lineEditLumi;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSliderTITA;
    QSlider *horizontalSliderPHI;
    QLineEdit *lineEditTITA;
    QLineEdit *lineEditPHI;
    QLabel *label_pic;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuSalir;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication3Class)
    {
        if (QtGuiApplication3Class->objectName().isEmpty())
            QtGuiApplication3Class->setObjectName(QStringLiteral("QtGuiApplication3Class"));
        QtGuiApplication3Class->resize(601, 368);
        QPalette palette;
        QBrush brush(QColor(100, 100, 100, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(91, 91, 91, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(194, 194, 194, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(122, 122, 122, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush4);
        QBrush brush5(QColor(68, 68, 68, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush6(QColor(86, 86, 86, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QBrush brush7(QColor(120, 120, 120, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        QtGuiApplication3Class->setPalette(palette);
        centralWidget = new QWidget(QtGuiApplication3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette1;
        QBrush brush8(QColor(188, 188, 188, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush9(QColor(75, 75, 75, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        centralWidget->setPalette(palette1);
        pushButtonAceptar = new QPushButton(centralWidget);
        pushButtonAceptar->setObjectName(QStringLiteral("pushButtonAceptar"));
        pushButtonAceptar->setGeometry(QRect(360, 20, 75, 23));
        pushButtonAceptar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAbrir = new QPushButton(centralWidget);
        pushButtonAbrir->setObjectName(QStringLiteral("pushButtonAbrir"));
        pushButtonAbrir->setGeometry(QRect(360, 50, 75, 23));
        horizontalSliderLumi = new QSlider(centralWidget);
        horizontalSliderLumi->setObjectName(QStringLiteral("horizontalSliderLumi"));
        horizontalSliderLumi->setGeometry(QRect(360, 130, 160, 19));
        horizontalSliderLumi->setOrientation(Qt::Horizontal);
        lineEditLumi = new QLineEdit(centralWidget);
        lineEditLumi->setObjectName(QStringLiteral("lineEditLumi"));
        lineEditLumi->setGeometry(QRect(440, 110, 31, 20));
        QPalette palette2;
        QBrush brush10(QColor(42, 42, 42, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        QBrush brush11(QColor(65, 65, 65, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        lineEditLumi->setPalette(palette2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 110, 81, 16));
        QPalette palette3;
        QBrush brush12(QColor(207, 207, 207, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        label->setPalette(palette3);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 170, 81, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_2->setPalette(palette4);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 230, 81, 16));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_3->setPalette(palette5);
        horizontalSliderTITA = new QSlider(centralWidget);
        horizontalSliderTITA->setObjectName(QStringLiteral("horizontalSliderTITA"));
        horizontalSliderTITA->setGeometry(QRect(360, 190, 160, 19));
        horizontalSliderTITA->setOrientation(Qt::Horizontal);
        horizontalSliderPHI = new QSlider(centralWidget);
        horizontalSliderPHI->setObjectName(QStringLiteral("horizontalSliderPHI"));
        horizontalSliderPHI->setGeometry(QRect(360, 250, 160, 19));
        horizontalSliderPHI->setOrientation(Qt::Horizontal);
        lineEditTITA = new QLineEdit(centralWidget);
        lineEditTITA->setObjectName(QStringLiteral("lineEditTITA"));
        lineEditTITA->setGeometry(QRect(450, 170, 31, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        lineEditTITA->setPalette(palette6);
        lineEditPHI = new QLineEdit(centralWidget);
        lineEditPHI->setObjectName(QStringLiteral("lineEditPHI"));
        lineEditPHI->setGeometry(QRect(440, 230, 31, 20));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        lineEditPHI->setPalette(palette7);
        label_pic = new QLabel(centralWidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(10, 10, 301, 301));
        label_pic->setFrameShape(QFrame::Box);
        QtGuiApplication3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        menuBar->setPalette(palette8);
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuSalir = new QMenu(menuBar);
        menuSalir->setObjectName(QStringLiteral("menuSalir"));
        QtGuiApplication3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication3Class->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuSalir->menuAction());

        retranslateUi(QtGuiApplication3Class);
        QObject::connect(pushButtonAceptar, SIGNAL(pressed()), QtGuiApplication3Class, SLOT(close()));

        QMetaObject::connectSlotsByName(QtGuiApplication3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication3Class)
    {
        QtGuiApplication3Class->setWindowTitle(QApplication::translate("QtGuiApplication3Class", "QtGuiApplication3", nullptr));
        pushButtonAceptar->setText(QApplication::translate("QtGuiApplication3Class", "Aceptar", nullptr));
        pushButtonAbrir->setText(QApplication::translate("QtGuiApplication3Class", "Abrir Imagen", nullptr));
        lineEditLumi->setText(QApplication::translate("QtGuiApplication3Class", "1.0", nullptr));
        label->setText(QApplication::translate("QtGuiApplication3Class", "Luminosidad:", nullptr));
        label_2->setText(QApplication::translate("QtGuiApplication3Class", "Colores A: TITA", nullptr));
        label_3->setText(QApplication::translate("QtGuiApplication3Class", "Colores B: PHI", nullptr));
        lineEditTITA->setText(QApplication::translate("QtGuiApplication3Class", "0.2", nullptr));
        lineEditPHI->setText(QApplication::translate("QtGuiApplication3Class", "0.3", nullptr));
        label_pic->setText(QString());
        menuMenu->setTitle(QApplication::translate("QtGuiApplication3Class", "Abrir", nullptr));
        menuSalir->setTitle(QApplication::translate("QtGuiApplication3Class", "Salir", nullptr));
    } // retranslateUi


	void cargarImagenEnLabel(QMainWindow *QtGuiApplication3Class) {
		// YO
		QPixmap pix("C:/Users/Irena/Downloads/Ire_SQ_glitch.jpg");
		int al = label_pic->width();
		int an = label_pic->height();
		//ui.label_pic->setScaledContents(true);
		label_pic->setPixmap(pix.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
																		  //ui.label_pic->setPixmap(pix);
	}


};

namespace Ui {
    class QtGuiApplication3Class: public Ui_QtGuiApplication3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION3_H
