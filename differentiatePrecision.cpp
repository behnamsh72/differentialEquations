#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

float decayFunction(float x, float constFactorR);

float decayDifferentiate(float x, float constFactorR);

void testRoundOfError();

//int main() {
//    testRoundOfError();
//    return 0;
//}

float decayFunction(float x, float constFactorR) {
    float y = exp(-constFactorR * x);
    return y;
}

float decayDifferentiate(float x, float constFactorR) {
    float yPrime = -constFactorR * exp(-constFactorR * x);
    return yPrime;
}

void testRoundOfError() {
    float x0 = 0;
    float y0 = 1;
    float xEnd = 1;

    float h = 0.1;
    float r = 1;
    float delta;
    while (h > 1E-8) {
        float y = y0;
        float x = x0;
        while (x <= xEnd) {
            y += decayDifferentiate(x, r) * h;
            x = x + h;
        }
        delta = abs(decayFunction(x, r) - y);
        printf("For h=%0.8f  Real Error is :%.8f\n", h, delta);
        h *= 0.1;

    }
}