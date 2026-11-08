#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

#include "BankAccountPayment.h"
#include <vector>
#include <memory>

class PaymentGateway {
private:
    std::vector<std::shared_ptr<BankAccountPayment>> methods;

public:
    void addPaymentMethod(std::shared_ptr<BankAccountPayment> method);
    void displaySupportedBanks() const;
    std::shared_ptr<BankAccountPayment> selectBank(int index) const;
    size_t getBankCount() const;
};

#endif // PAYMENT_GATEWAY_H