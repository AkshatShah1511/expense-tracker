/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *amountLineEdit;
    QLineEdit *categoryLineEdit;
    QLineEdit *descriptionLineEdit;
    QPushButton *addButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tabExpenses;
    QListWidget *expenseListWidget;
    QWidget *tabTopSpending;
    QTextBrowser *summaryTextBrowser;
    QWidget *tabPieChart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        amountLineEdit = new QLineEdit(centralwidget);
        amountLineEdit->setObjectName("amountLineEdit");
        amountLineEdit->setGeometry(QRect(230, 30, 301, 31));
        categoryLineEdit = new QLineEdit(centralwidget);
        categoryLineEdit->setObjectName("categoryLineEdit");
        categoryLineEdit->setGeometry(QRect(230, 70, 301, 31));
        descriptionLineEdit = new QLineEdit(centralwidget);
        descriptionLineEdit->setObjectName("descriptionLineEdit");
        descriptionLineEdit->setGeometry(QRect(230, 110, 301, 31));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(210, 180, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 35, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 70, 58, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 115, 71, 21));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(110, 230, 381, 241));
        tabExpenses = new QWidget();
        tabExpenses->setObjectName("tabExpenses");
        expenseListWidget = new QListWidget(tabExpenses);
        expenseListWidget->setObjectName("expenseListWidget");
        expenseListWidget->setGeometry(QRect(70, 10, 256, 192));
        tabWidget->addTab(tabExpenses, QString());
        tabTopSpending = new QWidget();
        tabTopSpending->setObjectName("tabTopSpending");
        summaryTextBrowser = new QTextBrowser(tabTopSpending);
        summaryTextBrowser->setObjectName("summaryTextBrowser");
        summaryTextBrowser->setGeometry(QRect(60, 10, 256, 192));
        tabWidget->addTab(tabTopSpending, QString());
        tabPieChart = new QWidget();
        tabPieChart->setObjectName("tabPieChart");
        tabWidget->addTab(tabPieChart, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 43));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Amount :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "category", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExpenses), QCoreApplication::translate("MainWindow", "\360\237\247\276 Expense List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTopSpending), QCoreApplication::translate("MainWindow", "\360\237\223\212 Top Spending", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPieChart), QCoreApplication::translate("MainWindow", "\360\237\245\247 Pie Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
