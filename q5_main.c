#include "q5_fractions.h"

int main() {
    for (int numerator = 10; numerator < 100; numerator++) {
        for (int denominator = numerator + 1; denominator < 100; denominator++) {
            if (isSleepyFraction(numerator, denominator)) {
                printf("%d/%d\n", numerator, denominator);
            }
        }
    }

    return 0;
}