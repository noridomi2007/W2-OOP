#ifndef VCB_PAYMENT_H
#define VCB_PAYMENT_H

#include "BankAccountPayment.h"

class VCBPayment : public BankAccountPayment {
public:
    VCBPayment(const std::string& accountNumber, double balance);
    double calculateFee(double amount) const override;
};

#endif // VCB_PAYMENT_H