/********************************************************************************
** Form generated from reading UI file 'webcamwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBCAMWIDGET_H
#define UI_WEBCAMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebcamWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelCam_;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *WebcamWidget)
    {
        if (WebcamWidget->objectName().isEmpty())
            WebcamWidget->setObjectName(QStringLiteral("WebcamWidget"));
        WebcamWidget->resize(624, 492);
        horizontalLayout = new QHBoxLayout(WebcamWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelCam_ = new QLabel(WebcamWidget);
        labelCam_->setObjectName(QStringLiteral("labelCam_"));
        labelCam_->setAutoFillBackground(true);

        horizontalLayout->addWidget(labelCam_);

        label = new QLabel(WebcamWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(WebcamWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAutoFillBackground(true);

        horizontalLayout->addWidget(label_2);


        retranslateUi(WebcamWidget);

        QMetaObject::connectSlotsByName(WebcamWidget);
    } // setupUi

    void retranslateUi(QWidget *WebcamWidget)
    {
        WebcamWidget->setWindowTitle(QApplication::translate("WebcamWidget", "WebcamWidget", Q_NULLPTR));
        labelCam_->setText(QString());
        label->setText(QApplication::translate("WebcamWidget", "Traitement <> Webcam", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WebcamWidget: public Ui_WebcamWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBCAMWIDGET_H
