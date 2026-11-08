#include "BankAccountPayment.h"
#include <iostream>
#include <iomanip>

BankAccountPayment::BankAccountPayment(const std::string& bankCode, const std::string& bankName,
                                       const std::string& accountNumber, double balance)
    : bankCode(bankCode), bankName(bankName), accountNumber(accountNumber), balance(balance) {}

std::string BankAccountPayment::getBankCode() const {
    return bankCode;
}

std::string BankAccountPayment::getBankName() const {
    return bankName;
}

std::string BankAccountPayment::getAccountNumber() const {
    return accountNumber;
}

double BankAccountPayment::getBalance() const {
    return balance;
}

bool BankAccountPayment::pay(double amount) {
    if (amount <= 0) {
        std::cout << "\n[LOI] So tien giao dich phai lon hon 0 VND!\n";
        return false;
    }

    double fee = calculateFee(amount);
    double totalDeduction = amount + fee;

    if (balance >= totalDeduction) {
        balance -= totalDeduction;

        std::cout << "\n========================================\n";
        std::cout << "          BIEN LAI GIAO DICH            \n";
        std::cout << "========================================\n";
        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Ngan hang      : " << bankName << " (" << bankCode << ")\n";
        std::cout << "So tai khoan   : " << accountNumber << "\n";
        std::cout << "So tien chuyen : " << amount << " VND\n";
        std::cout << "Phi giao dich  : " << fee << " VND\n";
        std::cout << "Tong tru       : " << totalDeduction << " VND\n";
        std::cout << "So du con lai  : " << balance << " VND\n";
        std::cout << "Trang thai     : THANH CONG\n";
        std::cout << "========================================\n";
        return true;
    } else {
        std::cout << "\n[LOI GIAO DICH] So du khong du de thuc hien thanh toan!\n";
        std::cout << std::fixed << std::setprecision(0);
        std::cout << "  - Can thanh toan (kem phi): " << totalDeduction << " VND\n";
        std::cout << "  - So du hien tai          : " << balance << " VND\n";
        return false;
    }
}