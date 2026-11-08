#ifndef TCB_PAYMENT_H
#define TCB_PAYMENT_H

#include "BankAccountPayment.h"

class TCBPayment : public BankAccountPayment {
public:
    TCBPayment(const std::string& accountNumber, double balance);
    double calculateFee(double amount) const override;
};

#endif // TCB_PAYMENT_H