/********************************************************************************
** Form generated from reading UI file 'codeUpdateDialog.ui'
**
** Created: Wed Apr 6 22:01:34 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEUPDATEDIALOG_H
#define UI_CODEUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CodeUpdateDialog
{
public:
    QProgressBar *progressBar;
    QPushButton *b_cancel;

    void setupUi(QDialog *CodeUpdateDialog)
    {
        if (CodeUpdateDialog->objectName().isEmpty())
            CodeUpdateDialog->setObjectName(QString::fromUtf8("CodeUpdateDialog"));
        CodeUpdateDialog->resize(400, 81);
        progressBar = new QProgressBar(CodeUpdateDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(24, 14, 357, 23));
        progressBar->setValue(0);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        b_cancel = new QPushButton(CodeUpdateDialog);
        b_cancel->setObjectName(QString::fromUtf8("b_cancel"));
        b_cancel->setGeometry(QRect(154, 46, 83, 29));

        retranslateUi(CodeUpdateDialog);

        QMetaObject::connectSlotsByName(CodeUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *CodeUpdateDialog)
    {
        CodeUpdateDialog->setWindowTitle(QApplication::translate("CodeUpdateDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        b_cancel->setText(QApplication::translate("CodeUpdateDialog", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CodeUpdateDialog: public Ui_CodeUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEUPDATEDIALOG_H
