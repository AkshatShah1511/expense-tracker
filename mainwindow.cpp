#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QListWidget>
#include <QTextBrowser>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Create central widget and main layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(15, 15, 15, 15); // Consistent margins

    // Header Section
    QWidget *headerWidget = new QWidget(this);
    headerWidget->setObjectName("headerWidget");
    headerWidget->setFixedHeight(90);
    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    QLabel *titleLabel = new QLabel("Expense Tracker", this);
    titleLabel->setStyleSheet("font-size: 28px; font-weight: 700; color: #ffffff;");
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();

    // Input Card
    QWidget *inputCard = new QWidget(this);
    inputCard->setObjectName("inputCard");
    inputCard->setMinimumHeight(200); // Adjusted height to fit content better
    QGridLayout *inputLayout = new QGridLayout(inputCard);
    inputLayout->setVerticalSpacing(5); // Reduced spacing between rows
    inputLayout->setHorizontalSpacing(10); // Adjusted horizontal spacing
    inputLayout->setContentsMargins(20, 20, 20, 20); // Inner padding for better fit

    // Input Fields
    QLabel *amountLabel = new QLabel("Amount:", this);
    amountLineEdit = new QLineEdit(this);
    amountLineEdit->setObjectName("amountLineEdit");
    amountLineEdit->setMinimumWidth(300); // Consistent width

    QLabel *categoryLabel = new QLabel("Category:", this);
    categoryLineEdit = new QLineEdit(this);
    categoryLineEdit->setObjectName("categoryLineEdit");
    categoryLineEdit->setMinimumWidth(300);

    QLabel *descriptionLabel = new QLabel("Description:", this);
    descriptionLineEdit = new QLineEdit(this);
    descriptionLineEdit->setObjectName("descriptionLineEdit");
    descriptionLineEdit->setMinimumWidth(300);

    addButton = new QPushButton("Add Expense", this);
    addButton->setObjectName("addButton");

    // Grid Layout Setup with proper alignment
    inputLayout->addWidget(amountLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    inputLayout->addWidget(amountLineEdit, 0, 1, 1, 1, Qt::AlignLeft);
    inputLayout->addWidget(categoryLabel, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    inputLayout->addWidget(categoryLineEdit, 1, 1, 1, 1, Qt::AlignLeft);
    inputLayout->addWidget(descriptionLabel, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    inputLayout->addWidget(descriptionLineEdit, 2, 1, 1, 1, Qt::AlignLeft);
    inputLayout->addWidget(addButton, 3, 0, 1, 2, Qt::AlignCenter); // Centered button

    // Tab Widget
    tabWidget = new QTabWidget(this);
    tabWidget->setObjectName("tabWidget");

    // Expenses Tab
    QWidget *expensesTab = new QWidget();
    QVBoxLayout *expensesLayout = new QVBoxLayout(expensesTab);
    // Search and Filter Section
    QWidget *searchWidget = new QWidget();
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setObjectName("searchLineEdit");
    searchLineEdit->setPlaceholderText("Search by category, description, or amount...");
    filterComboBox = new QComboBox(this);
    filterComboBox->setObjectName("filterComboBox");
    filterComboBox->addItems({"All", "Category", "Description", "Amount"});
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(filterComboBox);
    expensesLayout->addWidget(searchWidget);

    expenseListWidget = new QListWidget(this);
    expenseListWidget->setObjectName("expenseListWidget");
    expensesLayout->addWidget(expenseListWidget);
    tabWidget->addTab(expensesTab, "Expenses");

    // Summary Tab
    QWidget *summaryTab = new QWidget();
    QVBoxLayout *summaryLayout = new QVBoxLayout(summaryTab);
    summaryTextBrowser = new QTextBrowser(this);
    summaryTextBrowser->setObjectName("summaryTextBrowser");
    summaryLayout->addWidget(summaryTextBrowser);
    tabWidget->addTab(summaryTab, "Summary");

    // Add all to main layout
    mainLayout->addWidget(headerWidget);
    mainLayout->addWidget(inputCard);
    mainLayout->addWidget(tabWidget);

    // Connect signals
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(filterComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onFilterChanged);
    tabWidget->setUsesScrollButtons(false);

    // Placeholder text
    amountLineEdit->setPlaceholderText("Enter amount (e.g. 120.50)");
    categoryLineEdit->setPlaceholderText("Enter category (e.g. Food)");
    descriptionLineEdit->setPlaceholderText("Optional description");

    // Updated Styling
    this->setStyleSheet(R"(
    /* Global Settings */
    QWidget {
        font-family: 'Poppins', 'Segoe UI', sans-serif;
        font-size: 15px;
        color: #e0e6f0;
        background-color: #1a1f2b;
    }

    QMainWindow {
        background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,
                                  stop:0 #1a1f2b, stop:0.5 #222b3c, stop:1 #2d3446);
    }

    /* Header */
    #headerWidget {
        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                  stop:0 #9b59b6, stop:0.5 #8e44ad, stop:1 #7d3c98);
        border-radius: 20px;
        padding: 20px;
        margin: 15px;
    }

    /* Input Card */
    #inputCard {
        background: #2c3e50;
        border-radius: 20px;
        padding: 20px;
        margin: 15px;
        box-shadow: 0 4px 15px rgba(0, 0, 0, 0.3);
    }

    /* Line Edits */
    QLineEdit {
        background-color: #34495e;
        color: #ecf0f1;
        border: 2px solid #3498db;
        border-radius: 10px;
        padding: 10px 15px;
        selection-background-color: #9b59b6;
        selection-color: #ffffff;
        transition: all 0.3s;
    }

    QLineEdit:focus {
        border: 2px solid #9b59b6;
        background-color: #3d566e;
        box-shadow: 0 0 8px rgba(155, 89, 182, 0.4);
    }

    QLineEdit::placeholder {
        color: #bdc3c7;
        font-style: italic;
    }

    /* Button */
    QPushButton {
        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                  stop:0 #9b59b6, stop:1 #8e44ad);
        color: #ffffff;
        border: none;
        border-radius: 10px;
        padding: 12px 25px;
        font-weight: 600;
        box-shadow: 0 4px 12px rgba(155, 89, 182, 0.3);
        transition: all 0.3s;
    }

    QPushButton:hover {
        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                  stop:0 #a66bbe, stop:1 #9b59b6);
        box-shadow: 0 6px 15px rgba(155, 89, 182, 0.5);
        transform: translateY(-2px);
    }

    QPushButton:pressed {
        background: #7d3c98;
        box-shadow: 0 2px 8px rgba(155, 89, 182, 0.2);
        transform: translateY(1px);
    }

    /* Tab Widget */
    QTabWidget::pane {
        border: none;
        background: #2c3e50;
        border-radius: 20px;
        padding: 15px;
        margin: 15px;
        box-shadow: 0 4px 15px rgba(0, 0, 0, 0.3);
    }

    QTabBar::tab {
        background: #34495e;
        color: #bdc3c7;
        padding: 12px 25px;
        margin-right: 8px;
        border-radius: 10px;
        border: none;
        font-weight: 500;
    }

    QTabBar::tab:selected {
        background: #9b59b6;
        color: #ffffff;
        font-weight: 600;
        box-shadow: 0 2px 10px rgba(155, 89, 182, 0.3);
    }

    QTabBar::tab:hover:!selected {
        background: #415a70;
        color: #ecf0f1;
    }

    /* List and Summary */
    QListWidget, QTextBrowser {
        background: #34495e;
        color: #ecf0f1;
        border: none;
        border-radius: 10px;
        padding: 15px;
        margin: 8px;
    }

    QListWidget::item {
        padding: 10px;
        border-bottom: 1px solid #3d566e;
        transition: background-color 0.2s;
    }

    QListWidget::item:hover {
        background-color: #415a70;
    }

    /* Labels */
    QLabel {
        color: #ecf0f1;
        font-weight: 600;
        padding: 5px;
        background: transparent;
        font-size: 16px; /* Slightly larger for better visibility */
    }

    /* Search and Filter */
    #searchLineEdit, #filterComboBox {
        background-color: #34495e;
        color: #ecf0f1;
        border: 2px solid #3498db;
        border-radius: 10px;
        padding: 8px 12px;
        margin-right: 10px;
    }

    #searchLineEdit:focus {
        border: 2px solid #9b59b6;
        background-color: #3d566e;
        box-shadow: 0 0 8px rgba(155, 89, 182, 0.4);
    }

    #filterComboBox {
        min-width: 120px;
    }

    #filterComboBox::drop-down {
        border: none;
    }

    #filterComboBox QAbstractItemView {
        background-color: #34495e;
        color: #ecf0f1;
        selection-background-color: #9b59b6;
    }

    /* Scroll Bars */
    QScrollBar:vertical {
        border: none;
        background: #34495e;
        width: 10px;
        border-radius: 5px;
    }

    QScrollBar::handle:vertical {
        background: #9b59b6;
        border-radius: 5px;
        min-height: 20px;
    }

    QScrollBar::handle:vertical:hover {
        background: #a66bbe;
    }
)");

    setWindowTitle("Expense Tracker");
    setMinimumSize(900, 700);

    // Initial update
    updateExpenseList();
    updateSummary();
}

MainWindow::~MainWindow() {
}

void MainWindow::onAddButtonClicked() {
    double amount = amountLineEdit->text().toDouble();
    QString category = categoryLineEdit->text().trimmed();
    QString description = descriptionLineEdit->text().trimmed();

    if (amount <= 0 || category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount and category.");
        return;
    }

    manager.addExpense(amount, category, description);
    updateExpenseList();
    updateSummary();

    amountLineEdit->clear();
    categoryLineEdit->clear();
    descriptionLineEdit->clear();
}

void MainWindow::updateExpenseList() {
    expenseListWidget->clear();
    QString searchText = searchLineEdit->text().trimmed().toLower();
    QString filterType = filterComboBox->currentText();

    for (const auto& expense : manager.getExpenses()) {
        QString text = QString("₹%1 - %2 (%3)")
                           .arg(expense.amount, 0, 'f', 2)
                           .arg(expense.category)
                           .arg(expense.description.isEmpty() ? "No description" : expense.description);
        QString textLower = text.toLower();

        bool matches = true;
        if (!searchText.isEmpty()) {
            if (filterType == "Category") {
                matches = expense.category.toLower().contains(searchText);
            } else if (filterType == "Description") {
                matches = expense.description.toLower().contains(searchText) ||
                          (expense.description.isEmpty() && searchText.isEmpty());
            } else if (filterType == "Amount") {
                matches = QString::number(expense.amount, 'f', 2).contains(searchText);
            } else { // All
                matches = textLower.contains(searchText);
            }
        }

        if (matches) {
            expenseListWidget->addItem(text);
        }
    }
}

void MainWindow::updateSummary() {
    summaryTextBrowser->clear();
    auto topCategories = manager.getTopCategories();

    if (topCategories.empty()) {
        summaryTextBrowser->setText("No expenses yet.");
        return;
    }

    summaryTextBrowser->append("Top Spending Categories:");
    for (const auto& [category, total] : topCategories) {
        summaryTextBrowser->append(QString("• %1: ₹%2").arg(category).arg(total, 0, 'f', 2));
    }
}

void MainWindow::onSearchTextChanged(const QString &text) {
    updateExpenseList();
}

void MainWindow::onFilterChanged(const QString &text) {
    updateExpenseList();
}
