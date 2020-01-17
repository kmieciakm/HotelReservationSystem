#include <boost/test/unit_test.hpp>

#include "Payment.h"

BOOST_AUTO_TEST_SUITE(PaymentSuiteCorrect)

BOOST_AUTO_TEST_CASE(PaymentConstructor_InitialValues_AllCorrect) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(100, deadline);
    BOOST_REQUIRE_EQUAL(payment.GetRental(), 100);
    BOOST_REQUIRE_EQUAL(payment.IsPaidUp(), false);
    BOOST_REQUIRE_EQUAL(payment.HasExpired(), false);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_hour, deadline.tm_hour);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_mday, deadline.tm_mday);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_mon, deadline.tm_mon);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_year, deadline.tm_year);
}

BOOST_AUTO_TEST_CASE(Payment_ChangeToValidDeadline_DeadlineCorrect) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(100, deadline);

    std::tm newDeadline = {0, 0, 10, 17, 0, 400};
    payment.SetDeadline(newDeadline);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_mday, newDeadline.tm_mday);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_mon, newDeadline.tm_mon);
    BOOST_REQUIRE_EQUAL(payment.GetDeadline().tm_year, newDeadline.tm_year);
}

BOOST_AUTO_TEST_CASE(Payment_ChangeToInvalidDeadline_ThrowException) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(100, deadline);

    std::tm newDeadline = {0, 0, 10, 17, 0, 300};
    BOOST_REQUIRE_THROW(payment.SetDeadline(newDeadline), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Payment_DeadlineExpired_ReturnTrue) {
    std::tm deadline = {0, 0, 10, 14, 0, 100};
    Payment payment(100, deadline);
    BOOST_REQUIRE_EQUAL(payment.HasExpired(), true);
}

BOOST_AUTO_TEST_CASE(Payment_RentalEqualZero_IsPaidUp) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(0, deadline);
    BOOST_REQUIRE_EQUAL(payment.IsPaidUp(), true);
}

BOOST_AUTO_TEST_CASE(Payment_PayAllRental_IsPaidUp) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(100, deadline);
    payment.Pay(100);
    BOOST_REQUIRE_EQUAL(payment.IsPaidUp(), true);
}

BOOST_AUTO_TEST_CASE(Payment_PayMoreThenRental_ThrowException) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(50, deadline);
    BOOST_REQUIRE_THROW(payment.Pay(100), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Payment_PayAlreadyPaidUp_ThrowException) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(0, deadline);
    BOOST_REQUIRE_THROW(payment.Pay(100), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Payment_PayNegativeSum_ThrowException) {
    std::tm deadline = {0, 0, 10, 14, 0, 400};
    Payment payment(0, deadline);
    BOOST_REQUIRE_THROW(payment.Pay(-100), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()
