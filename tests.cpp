#include "gtest/gtest.h"
#include "Complex.h"

TEST(operatorPlus, expTrueSum) {
    complexNum a, b, sum;
    a.real = -0.3;
    a.img = 8;
    b.real = 0;
    b.img = 3.9;
    sum = a + b;

    EXPECT_DOUBLE_EQ(sum.real, -0.3);
    EXPECT_DOUBLE_EQ(sum.img, 11.9);

    a.real = 53.09;
    a.img = -32.1;
    sum += a;

    EXPECT_DOUBLE_EQ(sum.real, 52.79);
    EXPECT_DOUBLE_EQ(sum.img, -20.2);
}

TEST(operatorMinus, expTrueDifference) {
    complexNum a, b, sub;
    a.real = 92.87;
    a.img = 11;
    b.real = -0.31;
    b.img = 1.11;
    sub = a - b;

    EXPECT_DOUBLE_EQ(sub.real, 93.18);
    EXPECT_DOUBLE_EQ(sub.img, 9.89);

    a.real = 780;
    a.img = -0.981;
    sub -= a;

    EXPECT_DOUBLE_EQ(sub.real, -686.82);
    EXPECT_DOUBLE_EQ(sub.img, 10.871);
}

TEST(operatorMultiplication, expTrueProduct) {
    complexNum a, b, product;
    a.real = 0;
    a.img = 43.09;
    b.real = -7.83;
    b.img = 0;
    product = a * b;

    EXPECT_DOUBLE_EQ(product.real, 0);
    EXPECT_DOUBLE_EQ(product.img, -337.3947);

    a.real = 91;
    a.img = -0.5;
    product *= a;

    EXPECT_DOUBLE_EQ(product.real, -168.69735);
    EXPECT_DOUBLE_EQ(product.img, -30702.9177);
}

TEST(operatorDivision, expTrueQuotient) {
    complexNum a, b, quotient;
    a.real = -2;
    a.img = 1;
    b.real = 1;
    b.img = -1;
    quotient = a / b;

    EXPECT_DOUBLE_EQ(quotient.real, -1.5);
    EXPECT_DOUBLE_EQ(quotient.img, -0.5);

    a.real = 4;
    a.img = 3;
    quotient /= a;

    EXPECT_DOUBLE_EQ(quotient.real, -0.3);
    EXPECT_DOUBLE_EQ(quotient.img, 0.1);
}

TEST(operatorDivision, expTrueDivisionByZero) {
    complexNum a, b;
    a.real = -10;
    a.img = 20;
    b.real = 0;
    b.img = 0;

    EXPECT_THROW(a / b, std::invalid_argument);
}

TEST(operatorOut, expTrueOutput) {
    complexNum a;

    a.real = 0.32;
    a.img = 98;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "0.32+98i");

    a.real = -0.32;
    a.img = -98;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-0.32-98i");

    a.real = 0;
    a.img = 16.3;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "16.3i");

    a.real = 0;
    a.img = -16.3;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-16.3i");

    a.real = 52.9;
    a.img = 0;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "52.9");

    a.real = -52.9;
    a.img = 0;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-52.9");

    a.real = 0;
    a.img = 0;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "0");

    a.real = 1;
    a.img = 1;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1+i");

    a.real = -1;
    a.img = -1;
    testing::internal::CaptureStdout();
    std::cout << a;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1-i");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
