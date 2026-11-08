#include "VCBPayment.h"

VCBPayment::VCBPayment(const std::string& accountNumber, double balance)
    : BankAccountPayment("VCB", "Vietcombank", accountNumber, balance) {}

double VCBPayment::calculateFee(double amount) const {
    return 1100.0; // Phí cố định 1,100 VND
}