#include "hiker.h"
#include <stdio.h>
#include <stdbool.h>

#define ERROR_VALUE -1

// 양의 정수 여부 확인
bool isPositive(int num) {
    return num >= 0;
}

// 더하기 함수
int add(int a, int b) {
    if (isPositive(a) && isPositive(b)) {
        return a + b;
    } else {
        // 양의 정수가 아닐 경우 에러 값을 반환
        return -1;
    }
}

// 빼기 함수
int subtract(int a, int b) {
    if (isPositive(a) && isPositive(b)) {
        return a - b;
    } else {
        // 양의 정수가 아닐 경우 에러 값을 반환
        return -1;
    }
}

// 나누기 함수
int divide(int a, int b) {
    if (b == 0 || !isPositive(a) || !isPositive(b)) {
        // divide by zero 또는 양의 정수가 아닌 경우 에러 처리
        return -1;
    } else {
        return a / b;
    }
}

// 곱하기 함수
int multiply(int a, int b) {
    if (isPositive(a) && isPositive(b)) {
        return a * b;
    } else {
        // 양의 정수가 아닐 경우 에러 값을 반환
        return -1;
    }
}

// 짝수인지 확인하는 함수
bool isEven(int number) {
    return number % 2 == 0;
}

// 이름을 받아 인사하는 함수 (C 스타일 문자열 사용)
void greet(const char* name, char* output, size_t output_size) {
    snprintf(output, output_size, "Hello, %s!", name); // 출력 버퍼에 문자열 생성
}
