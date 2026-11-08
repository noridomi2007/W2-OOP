#include "MBBankPayment.h"

MBBankPayment::MBBankPayment(const std::string& accountNumber, double balance)
    : BankAccountPayment("MBB", "MBBank", accountNumber, balance) {}

double MBBankPayment::calculateFee(double amount) const {
    return amount * 0.002; // Phí bằng 0.2% số tiền giao dịch
}