#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <map>
#include <queue>
#include <QString>

struct Expense {
    double amount;
    QString category;
    QString description;
};

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    std::map<QString, double> categoryTotals;

public:
    void addExpense(double amount, const QString& category, const QString& description);
    const std::vector<Expense>& getExpenses() const;
    std::map<QString, double> getCategoryTotals() const;
    std::vector<std::pair<QString, double>> getTopCategories(int topN = 3);
};

#endif // EXPENSEMANAGER_H
