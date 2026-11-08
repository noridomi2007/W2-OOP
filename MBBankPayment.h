#ifndef MBBANK_PAYMENT_H
#define MBBANK_PAYMENT_H

#include "BankAccountPayment.h"

class MBBankPayment : public BankAccountPayment {
public:
    MBBankPayment(const std::string& accountNumber, double balance);
    double calculateFee(double amount) const override;
};

#endif // MBBANK_PAYMENT_H