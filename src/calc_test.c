#include <gtest/gtest.h>
#include <gmock/gmock.h>  
#include <string>

extern "C"
{
#include "hiker.h"
}

using namespace ::testing;

// 에러 메시지를 정확히 비교하지 않고, "ERROR"가 포함됐는지만 확인
TEST(greetTest, ErrorMessageCheckUsingSubstring) {
    ASSERT_THAT(std::string(greet(NULL)), ::testing::HasSubstr("ERROR"));
    ASSERT_THAT(std::string(greet("")), ::testing::HasSubstr("ERROR"));
}

TEST(greetTest, validName)
{
    // assert(strcmp(greet("Alice"), "Hello, Alice!") == 0);
    ASSERT_STREQ(greet("Alice"), "Hello, Alice!");
}

// 동일한 에러 메시지가 출력되는지 확인
TEST(greetTest, nullOrEmpty)
{
    // assert(strcmp(greet(""), "[ERROR] name is null or empty") == 0);
    EXPECT_STREQ(greet(NULL), "[ERROR] name is null or empty");
    EXPECT_STREQ(greet(""), "[ERROR] name is null or empty");
}


TEST(addTest, validInput)
{
    ASSERT_EQ(add(4,5), 9);
    ASSERT_NE(add(4,5), 9); 
}

TEST(addTest, InvalidInputs) {
    ASSERT_EQ(add(-1, 5), -1);      // 음수 입력
    ASSERT_EQ(add(10, -5), -1);     // 음수 입력
}

// subtract 함수 테스트
TEST(SubtractTest, ValidInputs) {
    ASSERT_EQ(subtract(5, 3), 2);   // 정상 입력
    ASSERT_EQ(subtract(0, 0), 0);   // 0 입력
}
