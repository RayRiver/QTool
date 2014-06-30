/********************************************************************************
** Form generated from reading UI file 'glviewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLVIEWWIDGET_H
#define UI_GLVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLViewWidget
{
public:

    void setupUi(QWidget *GLViewWidget)
    {
        if (GLViewWidget->objectName().isEmpty())
            GLViewWidget->setObjectName(QStringLiteral("GLViewWidget"));
        GLViewWidget->resize(400, 300);

        retranslateUi(GLViewWidget);

        QMetaObject::connectSlotsByName(GLViewWidget);
    } // setupUi

    void retranslateUi(QWidget *GLViewWidget)
    {
        GLViewWidget->setWindowTitle(QApplication::translate("GLViewWidget", "GLViewWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class GLViewWidget: public Ui_GLViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLVIEWWIDGET_H
