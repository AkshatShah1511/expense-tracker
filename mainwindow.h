#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QListWidget>
#include <QTextBrowser>
#include <QComboBox>

#include "expensemanager.h" // Replace with your actual manager class header

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onSearchTextChanged(const QString &text);
    void onFilterChanged(const QString &text);

private:
    void updateExpenseList();
    void updateSummary();

    QLineEdit *amountLineEdit;
    QLineEdit *categoryLineEdit;
    QLineEdit *descriptionLineEdit;
    QPushButton *addButton;
    QTabWidget *tabWidget;
    QListWidget *expenseListWidget;
    QTextBrowser *summaryTextBrowser;
    QLineEdit *searchLineEdit; // New search bar
    QComboBox *filterComboBox; // New filter dropdown

    ExpenseManager manager; // Your expense manager class
};

#endif // MAINWINDOW_H
