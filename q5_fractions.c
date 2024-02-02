#include "q5_fractions.h"

bool isSleepyFraction(int numerator, int denominator) {
    int num1 = numerator / 10, num2 = numerator % 10; // e.g. 12 -> 1, 2
    int den1 = denominator / 10, den2 = denominator % 10;
    /*  need to convert to float to avoid integer division,
    e.g, for float 1/2 = 0.5, but for int 1/2 = 0 */
    if ((num1 == den1 && den2 != 0 && (float)num2 / den2 == (float)numerator / denominator) || // 1st digit of numerator == 1st digit of denominator
        (num1 == den2 && den1 != 0 && (float)num2 / den1 == (float)numerator / denominator) || // 1st digit of numerator == 2nd digit of denominator
        (num2 == den1 && den2 != 0 && (float)num1 / den2 == (float)numerator / denominator) || // 2nd digit of numerator == 1st digit of denominator
        (num2 == den2 && den1 != 0 && (float)num1 / den1 == (float)numerator / denominator)) { // 2nd digit of numerator == 2nd digit of denominator
        return true;
    }

    return false;
}