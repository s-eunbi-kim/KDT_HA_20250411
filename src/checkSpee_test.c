#include <gtest/gtest.h>

extern "C"
{
#include "hiker.h"
}

using namespace ::testing;

// checkHigh 함수 테스트
TEST(CheckHighTest, InRange) {
    ASSERT_TRUE(checkHigh(80));  // 하한 경계값
    ASSERT_TRUE(checkHigh(110)); // 상한 경계값
    ASSERT_TRUE(checkHigh(90));  // 범위 내의 값
}

// checkHigh 함수 테스트
TEST(CheckHighTest, OutOfRange) {
    ASSERT_FALSE(checkHigh(79));  // 하한 미만
    ASSERT_FALSE(checkHigh(111)); // 상한 초과
}

// displayStatus 함수 테스트
TEST(DisplayStatusTest, SpeedAboveHigh) {
    ASSERT_STREQ(displayStatus(100, 60, 120), "red"); // speed > high
}

TEST(DisplayStatusTest, SpeedInYellowRange) {
    ASSERT_STREQ(displayStatus(100, 60, 95), "yellow"); // high * 0.9 <= speed <= high
}

TEST(DisplayStatusTest, SpeedInYellowRange_boundary) {
    ASSERT_STREQ(displayStatus(100, 60, 90), "yellow"); // high * 0.9 <= speed <= high --> 결함
}

TEST(DisplayStatusTest, SpeedInGreenRange) {
    ASSERT_STREQ(displayStatus(100, 60, 70), "green"); // low <= speed <= high * 0.9
}

TEST(DisplayStatusTest, SpeedBelowLow) {
    ASSERT_STREQ(displayStatus(100, 60, 50), "gray"); // speed < low
}

TEST(DisplayStatusTest, InvalidState_0) {
    ASSERT_STREQ(displayStatus(0, 0, 0), "err_msg"); // 잘못된 high, low 값
}

TEST(DisplayStatusTest, InvalidState_negative) {
    ASSERT_STREQ(displayStatus(-1, -1, 100), "err_msg"); // 잘못된 high, low 값
}

TEST(DisplayStatusTest, LowGreaterThanHigh) {
    ASSERT_STREQ(displayStatus(50, 100, 75), "err_msg"); // low > high
}

TEST(DisplayStatusTest, InvalidState_negative2) {
    ASSERT_STREQ(displayStatus(-1, -2, -3), "err_msg"); // 모든 조건을 만족하지 않아 "err_msg" 반환
}

TEST(DisplayStatusTest, ErrMsgCase) {
    ASSERT_STREQ(displayStatus(0, 100, 101), "err_msg"); // 비정상적인 high, low 값
}
