#ifndef BANK_ACCOUNT_PAYMENT_H
#define BANK_ACCOUNT_PAYMENT_H

#include <string>

class BankAccountPayment {
protected:
    std::string bankCode;
    std::string bankName;
    std::string accountNumber;
    double balance;

public:
    BankAccountPayment(const std::string& bankCode, const std::string& bankName,
                       const std::string& accountNumber, double balance);
    virtual ~BankAccountPayment() = default;

    std::string getBankCode() const;
    std::string getBankName() const;
    std::string getAccountNumber() const;
    double getBalance() const;

    // Phương thức thuần ảo tính phí giao dịch
    virtual double calculateFee(double amount) const = 0;

    // Phương thức xử lý thanh toán chung
    virtual bool pay(double amount);
};

#endif // BANK_ACCOUNT_PAYMENT_H