#include "ExpenseManager.h"

void ExpenseManager::addExpense(double amount, const QString& category, const QString& description) {
    expenses.push_back({amount, category, description});
    categoryTotals[category] += amount;
}

const std::vector<Expense>& ExpenseManager::getExpenses() const {
    return expenses;
}

std::map<QString, double> ExpenseManager::getCategoryTotals() const {
    return categoryTotals;
}

std::vector<std::pair<QString, double>> ExpenseManager::getTopCategories(int topN) {
    std::priority_queue<std::pair<double, QString>> pq;

    for (const auto& entry : categoryTotals) {
        pq.push({entry.second, entry.first});
    }

    std::vector<std::pair<QString, double>> topCategories;
    while (topN-- && !pq.empty()) {
        auto top = pq.top(); pq.pop();
        topCategories.push_back({top.second, top.first});
    }

    return topCategories;
}
