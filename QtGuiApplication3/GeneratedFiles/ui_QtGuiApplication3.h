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
    QPushButton *pushButtonSalir;
    QPushButton *pushButtonAbrir;
    QSlider *horizontalSliderTITA;
    QLineEdit *lineEditTITA;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSliderPHI;
    QLineEdit *lineEditPHI;
    QLabel *label_pic;
    QLabel *label_5;
    QPushButton *pushButtonValProm;
    QPushButton *pushButtonValInd;
    QPushButton *pushButtonReestVal;
    QPushButton *pushButtonGuardar;
    QLabel *label_6;
    QLabel *labelTITA;
    QLabel *labelPHI;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtGuiApplication3Class)
    {
        if (QtGuiApplication3Class->objectName().isEmpty())
            QtGuiApplication3Class->setObjectName(QStringLiteral("QtGuiApplication3Class"));
        QtGuiApplication3Class->resize(756, 537);
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
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(122, 122, 122, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        QBrush brush4(QColor(68, 68, 68, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush5(QColor(86, 86, 86, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        QtGuiApplication3Class->setPalette(palette);
        centralWidget = new QWidget(QtGuiApplication3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette1;
        QBrush brush7(QColor(188, 188, 188, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush8(QColor(75, 75, 75, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        centralWidget->setPalette(palette1);
        pushButtonSalir = new QPushButton(centralWidget);
        pushButtonSalir->setObjectName(QStringLiteral("pushButtonSalir"));
        pushButtonSalir->setGeometry(QRect(660, 450, 75, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButtonSalir->setFont(font);
        pushButtonSalir->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSalir->setStyleSheet(QStringLiteral("background-color: rgb(254, 178, 180);"));
        pushButtonAbrir = new QPushButton(centralWidget);
        pushButtonAbrir->setObjectName(QStringLiteral("pushButtonAbrir"));
        pushButtonAbrir->setGeometry(QRect(530, 10, 211, 31));
        QFont font1;
        font1.setPointSize(12);
        pushButtonAbrir->setFont(font1);
        horizontalSliderTITA = new QSlider(centralWidget);
        horizontalSliderTITA->setObjectName(QStringLiteral("horizontalSliderTITA"));
        horizontalSliderTITA->setGeometry(QRect(530, 140, 211, 19));
        horizontalSliderTITA->setMinimum(0);
        horizontalSliderTITA->setMaximum(9999);
        horizontalSliderTITA->setSliderPosition(0);
        horizontalSliderTITA->setOrientation(Qt::Horizontal);
        horizontalSliderTITA->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTITA->setTickInterval(999);
        lineEditTITA = new QLineEdit(centralWidget);
        lineEditTITA->setObjectName(QStringLiteral("lineEditTITA"));
        lineEditTITA->setGeometry(QRect(690, 110, 51, 20));
        QPalette palette2;
        QBrush brush9(QColor(42, 42, 42, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        QBrush brush10(QColor(65, 65, 65, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        lineEditTITA->setPalette(palette2);
        QFont font2;
        font2.setPointSize(10);
        lineEditTITA->setFont(font2);
        lineEditTITA->setFrame(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 110, 111, 16));
        QPalette palette3;
        QBrush brush11(QColor(207, 207, 207, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        label->setPalette(palette3);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 170, 71, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        label_2->setPalette(palette4);
        label_2->setFont(font1);
        horizontalSliderPHI = new QSlider(centralWidget);
        horizontalSliderPHI->setObjectName(QStringLiteral("horizontalSliderPHI"));
        horizontalSliderPHI->setGeometry(QRect(530, 200, 211, 19));
        horizontalSliderPHI->setMaximum(9999);
        horizontalSliderPHI->setOrientation(Qt::Horizontal);
        horizontalSliderPHI->setTickPosition(QSlider::TicksBelow);
        horizontalSliderPHI->setTickInterval(999);
        lineEditPHI = new QLineEdit(centralWidget);
        lineEditPHI->setObjectName(QStringLiteral("lineEditPHI"));
        lineEditPHI->setGeometry(QRect(690, 170, 51, 20));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        lineEditPHI->setPalette(palette5);
        lineEditPHI->setFont(font2);
        label_pic = new QLabel(centralWidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(10, 10, 501, 461));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_pic->sizePolicy().hasHeightForWidth());
        label_pic->setSizePolicy(sizePolicy);
        label_pic->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(560, 240, 151, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        label_5->setPalette(palette6);
        label_5->setFont(font1);
        pushButtonValProm = new QPushButton(centralWidget);
        pushButtonValProm->setObjectName(QStringLiteral("pushButtonValProm"));
        pushButtonValProm->setGeometry(QRect(530, 278, 211, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush12(QColor(227, 227, 227, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush13(QColor(247, 247, 247, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        pushButtonValProm->setPalette(palette7);
        pushButtonValProm->setFont(font1);
        pushButtonValInd = new QPushButton(centralWidget);
        pushButtonValInd->setObjectName(QStringLiteral("pushButtonValInd"));
        pushButtonValInd->setGeometry(QRect(530, 308, 211, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush12);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        pushButtonValInd->setPalette(palette8);
        pushButtonValInd->setFont(font1);
        pushButtonReestVal = new QPushButton(centralWidget);
        pushButtonReestVal->setObjectName(QStringLiteral("pushButtonReestVal"));
        pushButtonReestVal->setGeometry(QRect(530, 360, 211, 31));
        QPalette palette9;
        QBrush brush14(QColor(255, 174, 176, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush14);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush14);
        QBrush brush15(QColor(255, 85, 88, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush15);
        QBrush brush16(QColor(246, 246, 246, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        QBrush brush17(QColor(51, 153, 255, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush17);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        pushButtonReestVal->setPalette(palette9);
        pushButtonReestVal->setFont(font1);
        pushButtonReestVal->setStyleSheet(QStringLiteral("background-color: rgb(255, 174, 176);"));
        pushButtonGuardar = new QPushButton(centralWidget);
        pushButtonGuardar->setObjectName(QStringLiteral("pushButtonGuardar"));
        pushButtonGuardar->setGeometry(QRect(530, 410, 211, 31));
        pushButtonGuardar->setFont(font1);
        pushButtonGuardar->setStyleSheet(QStringLiteral("background-color: rgb(165, 174, 254);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(570, 60, 151, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        label_6->setPalette(palette10);
        label_6->setFont(font1);
        labelTITA = new QLabel(centralWidget);
        labelTITA->setObjectName(QStringLiteral("labelTITA"));
        labelTITA->setEnabled(true);
        labelTITA->setGeometry(QRect(630, 110, 51, 16));
        QPalette palette11;
        QBrush brush18(QColor(206, 206, 206, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush18);
        QBrush brush19(QColor(236, 236, 236, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush19);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        QBrush brush20(QColor(149, 149, 149, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush20);
        QBrush brush21(QColor(184, 184, 184, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush21);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush19);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush20);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        labelTITA->setPalette(palette11);
        labelTITA->setLayoutDirection(Qt::RightToLeft);
        labelPHI = new QLabel(centralWidget);
        labelPHI->setObjectName(QStringLiteral("labelPHI"));
        labelPHI->setEnabled(true);
        labelPHI->setGeometry(QRect(630, 170, 51, 16));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush18);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush19);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush20);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush21);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush19);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush20);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        labelPHI->setPalette(palette12);
        labelPHI->setLayoutDirection(Qt::RightToLeft);
        QtGuiApplication3Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtGuiApplication3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication3Class->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtGuiApplication3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 21));
        QPalette palette13;
        QBrush brush22(QColor(194, 194, 194, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush22);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush22);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush22);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        menuBar->setPalette(palette13);
        QtGuiApplication3Class->setMenuBar(menuBar);

        retranslateUi(QtGuiApplication3Class);

        QMetaObject::connectSlotsByName(QtGuiApplication3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication3Class)
    {
        QtGuiApplication3Class->setWindowTitle(QApplication::translate("QtGuiApplication3Class", "QtGuiApplication3", nullptr));
        pushButtonSalir->setText(QApplication::translate("QtGuiApplication3Class", "SALIR", nullptr));
        pushButtonAbrir->setText(QApplication::translate("QtGuiApplication3Class", "Abrir Imagen", nullptr));
        lineEditTITA->setText(QApplication::translate("QtGuiApplication3Class", "0.0", nullptr));
        label->setText(QApplication::translate("QtGuiApplication3Class", "Luminosidad:", nullptr));
        label_2->setText(QApplication::translate("QtGuiApplication3Class", "Tono:", nullptr));
        lineEditPHI->setText(QApplication::translate("QtGuiApplication3Class", "0.0", nullptr));
        label_pic->setText(QString());
        label_5->setText(QApplication::translate("QtGuiApplication3Class", "Valores autom\303\241ticos:", nullptr));
        pushButtonValProm->setText(QApplication::translate("QtGuiApplication3Class", "Valores promedio", nullptr));
        pushButtonValInd->setText(QApplication::translate("QtGuiApplication3Class", "Valores individuales", nullptr));
        pushButtonReestVal->setText(QApplication::translate("QtGuiApplication3Class", "Reestablecer valores", nullptr));
        pushButtonGuardar->setText(QApplication::translate("QtGuiApplication3Class", "Guardar Imagen", nullptr));
        label_6->setText(QApplication::translate("QtGuiApplication3Class", "Valores manuales:", nullptr));
        labelTITA->setText(QString());
        labelPHI->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication3Class: public Ui_QtGuiApplication3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION3_H
