#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;


public: 
    BankAccount(int accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance), interestRate(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Депосит $" << amount << " введите аккаунт " << accountNumber << std::endl;
        }
        else {
            std::cout << "Ошибка: неверная сумма депозита." << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Снято $" << amount << " со счета " << accountNumber << std::endl;
            return true;
        }
        else {
            std::cout << "Ошибка: недостаточно средст или неверная сумма." << std::endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
        std::cout << "Процентная ставка установлена " << interestRate * 100 << "%" << std::endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "Перевод $" << amount << " с счета  " << from.accountNumber << " на счет" << to.accountNumber << std::endl;
        return true;
    }
    else {
        std::cout << "Ошибка: недостаточно средств для." << std::endl;
        return false;
    }
}

int main() {
    int acNum1, acNum2;
    double nachBalances1, nachBalances2;
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер счета для счета 1: ";
    std::cin >> acNum1;
    std::cout << "Введите начльный баланс для счета 1: ";
    std::cin >> nachBalances1;

    BankAccount ac1(acNum1, nachBalances1);

    std::cout << "Введите номер счета для счета 2: ";
    std::cin >> acNum2;
    std::cout << "Введите начльный баланс для счета 2: ";
    std::cin >> nachBalances2;

    BankAccount ac2(acNum2, nachBalances2);

    double depositAmount, transferAmount, interestRate;

    std::cout << "Введите сумму депозита для счета 1: ";
    std::cin >> depositAmount;
    ac1.deposit(depositAmount);

    std::cout << "Введите процентную ставку для счета 1 (в десятичной форме): ";
    std::cin >> interestRate;
    ac1.setInterestRate(interestRate);

    std::cout << "Введите сумму перевода со счета 1 на счет 2 : ";
    std::cin >> transferAmount;

    transfer(ac1, ac2, transferAmount);

    std::cout << "Счет " << ac1.getAccountNumber() << " баланс: $" << ac1.getBalance() << std::endl;
    std::cout << "Счет " << ac2.getAccountNumber() << " баланс: $" << ac2.getBalance() << std::endl;

    return 0;
}
