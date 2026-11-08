#include <iostream>
#include <memory>
#include <string>
#include "PaymentGateway.h"
#include "VCBPayment.h"
#include "TCBPayment.h"
#include "MBBankPayment.h" // Nạp thêm MBBank theo nguyên lý OCP

int main() {
    PaymentGateway gateway;

    // 1. Khởi tạo các ngân hàng mặc định
    gateway.addPaymentMethod(std::make_shared<VCBPayment>("0011001234567", 500000.0));
    gateway.addPaymentMethod(std::make_shared<TCBPayment>("1903123456789", 300000.0));

    // 2. Bổ sung MBBank kiểm tra tính chất OCP (STK: 0987654321, Số dư: 1,000,000 VND)
    gateway.addPaymentMethod(std::make_shared<MBBankPayment>("0987654321", 1000000.0));

    int choice = -1;
    while (true) {
        gateway.displaySupportedBanks();
        std::cout << "Chon ngan hang thanh toan (0 - " << gateway.getBankCount() << "): ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "[LOI] Vui long nhap mot so hop le!\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Cam on ban da su dung he thong thanh toan!\n";
            break;
        }

        std::shared_ptr<BankAccountPayment> selectedBank = gateway.selectBank(choice);
        if (!selectedBank) {
            std::cout << "[LOI] Lua chon khong hop le. Vui long chon lai!\n";
            continue;
        }

        std::string inputAccount;
        double amount = 0.0;

        std::cout << "Nhap so tai khoan xac nhan (goi y: " << selectedBank->getAccountNumber() << "): ";
        std::cin >> inputAccount;

        if (inputAccount != selectedBank->getAccountNumber()) {
            std::cout << "[LOI] So tai khoan khong khop voi tai khoan da dang ky tai " 
                      << selectedBank->getBankName() << "!\n";
            continue;
        }

        std::cout << "Nhap so tien can giao dich (VND): ";
        std::cin >> amount;

        // Gọi phương thức đa hình xử lý thanh toán
        selectedBank->pay(amount);
    }

    return 0;
}