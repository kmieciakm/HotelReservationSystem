#ifndef PAYMENT_H
#define PAYMENT_H

#include <chrono>

class Payment {
private:
    float rental;
    std::tm deadline;
public:
    Payment(float _rental, std::tm _deadline);
    ~Payment() = default;
    float GetRental();
    std::tm GetDeadline();
    void SetDeadline(std::tm newDeadline);
    bool IsPaidUp();
    bool HasExpired();
    void Pay(float sum);
};

#endif
