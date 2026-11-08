#include "TCBPayment.h"

TCBPayment::TCBPayment(const std::string& accountNumber, double balance)
    : BankAccountPayment("TCB", "Techcombank", accountNumber, balance) {}

double TCBPayment::calculateFee(double amount) const {
    return 0.0; // Miễn phí giao dịch
}