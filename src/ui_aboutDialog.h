/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created: Sat Mar 5 22:41:00 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *dialog_b_ok;
    QLabel *logoLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_programName;
    QLabel *label_programVersion;
    QLabel *label_author;
    QTextEdit *textEdit;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->setWindowModality(Qt::WindowModal);
        AboutDialog->resize(488, 338);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setMinimumSize(QSize(488, 338));
        AboutDialog->setMaximumSize(QSize(488, 338));
        AboutDialog->setModal(true);
        dialog_b_ok = new QPushButton(AboutDialog);
        dialog_b_ok->setObjectName(QString::fromUtf8("dialog_b_ok"));
        dialog_b_ok->setGeometry(QRect(6, 306, 129, 27));
        logoLabel = new QLabel(AboutDialog);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setGeometry(QRect(18, 12, 181, 101));
        verticalLayoutWidget = new QWidget(AboutDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(212, 12, 267, 107));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_programName = new QLabel(verticalLayoutWidget);
        label_programName->setObjectName(QString::fromUtf8("label_programName"));
        QFont font;
        font.setPointSize(15);
        label_programName->setFont(font);
        label_programName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_programName);

        label_programVersion = new QLabel(verticalLayoutWidget);
        label_programVersion->setObjectName(QString::fromUtf8("label_programVersion"));
        QFont font1;
        font1.setPointSize(12);
        label_programVersion->setFont(font1);
        label_programVersion->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_programVersion);

        label_author = new QLabel(verticalLayoutWidget);
        label_author->setObjectName(QString::fromUtf8("label_author"));
        label_author->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_author);

        textEdit = new QTextEdit(AboutDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(6, 130, 475, 169));
        textEdit->setReadOnly(true);

        retranslateUi(AboutDialog);
        QObject::connect(dialog_b_ok, SIGNAL(clicked()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "O programie...", 0, QApplication::UnicodeUTF8));
        dialog_b_ok->setText(QApplication::translate("AboutDialog", "OK", 0, QApplication::UnicodeUTF8));
        logoLabel->setText(QString());
        label_programName->setText(QApplication::translate("AboutDialog", "ProgramName", 0, QApplication::UnicodeUTF8));
        label_programVersion->setText(QApplication::translate("AboutDialog", "Version", 0, QApplication::UnicodeUTF8));
        label_author->setText(QApplication::translate("AboutDialog", "Author", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">This program is free software; you can redistribute it and/or</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">modify it under the terms of the GNU General Public License</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">as published by the Free Software Foundation; either version 2</p>\n"
"<p style=\""
                        " margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">of the License, or (at your option) any later version.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">This program is distributed in the hope that it will be useful,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">but WITHOUT ANY WARRANTY; without even the implied warranty of</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">MERCHANTABILITY "
                        "or FITNESS FOR A PARTICULAR PURPOSE.  See the</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">GNU General Public License for more details.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">You should have received a copy of the GNU General Public License</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\">along with this program; if not, write to the Free Software</p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        "; font-family:'Courier New,courier';\">Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
