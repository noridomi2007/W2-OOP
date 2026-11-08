#include "PaymentGateway.h"
#include <iostream>
#include <iomanip>

void PaymentGateway::addPaymentMethod(std::shared_ptr<BankAccountPayment> method) {
    if (method != nullptr) {
        methods.push_back(method);
    }
}

void PaymentGateway::displaySupportedBanks() const {
    std::cout << "\n--- DANH SACH NGAN HANG HO TRO ---\n";
    std::cout << std::fixed << std::setprecision(0);
    for (size_t i = 0; i < methods.size(); ++i) {
        std::cout << i + 1 << ". [" << methods[i]->getBankCode() << "] "
                  << methods[i]->getBankName()
                  << " | STK: " << methods[i]->getAccountNumber()
                  << " | So du: " << methods[i]->getBalance() << " VND\n";
    }
    std::cout << "0. Thoat chuong trinh\n";
    std::cout << "----------------------------------\n";
}

std::shared_ptr<BankAccountPayment> PaymentGateway::selectBank(int index) const {
    // Người dùng chọn theo số thứ tự từ 1 -> size()
    if (index < 1 || index > static_cast<int>(methods.size())) {
        return nullptr;
    }
    return methods[index - 1];
}

size_t PaymentGateway::getBankCount() const {
    return methods.size();
}