#include "hiker.h"
#include <stdio.h>
#include <stdbool.h>

#define HIGH_MIN 80
#define HIGH_MAX 110
#define LOW_MIN 50
#define LOW_MAX 80

bool isInRange(float value, float min, float max) {
    return value >= min && value <= max;
}

// 상한 조건 확인
bool checkHigh(float high) {
    return isInRange(high, HIGH_MIN, HIGH_MAX);
}

// 하한 조건 확인
bool checkLow(float low) {
    return isInRange(low, LOW_MIN, LOW_MAX);
}
// 현재 속도 조건 확인
bool checkSpeed(float speed) {
    return speed >= 0;
}

// 차량 속도에 따른 상태 표시
const char *displayStatus(float high, float low, float speed) {
    // 상한/하한/현재 속도 값 모두 유효할 때
    if (checkHigh(high) && checkLow(low) && checkSpeed(speed)) {
        if (speed > high) {
            return "red";
        }
        else if (speed > high * 0.9 && speed <= high) {
            return "yellow";
        }
        else if (speed >= low && speed <= high * 0.9) {
            return "green";
        }
        else if (speed < low) {
            return "gray";
        }
        else {
            return "err_msg";
        }
    } else {
        return "err_msg";
    }
}
