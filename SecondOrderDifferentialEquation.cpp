//
// Created by behnam on 8/5/21.
//

#include <iostream>
#include <cmath>

using namespace std;

double harmonicOscillatorDifferentialEquation(double x);

double energyCalculator(double x, double v);

double oiler(double x0, double v0, double finalTime);

double oilerCromer(double x0, double v0, double finalTime);

double meanAlgorithm(double x0, double v0, double finalTime);

double midPointAlgorithm(double x0, double v0, double finalTime);

double velocityVerletAlgorithm(double x0, double v0, double finalTime);


double beemanAlgorithm(double x0, double v0, double finalTime);

double secondOrderRungKutta(double x0, double v0, double finalTime);

const double k = 1;
const double m = 1;
const double h = 1E-3;

int main() {
    double x0 = 4;
    double v0 = 0;
    double t = 7;
//    oiler(x0, v0, t);
//    oilerCromer(x0, v0, t);
//    meanAlgorithm(x0, v0, t);
//    midPointAlgorithm(x0, v0, t);
//    velocityVerletAlgorithm(x0, v0, t);
    beemanAlgorithm(x0, v0, t);

    return 0;
}

double harmonicOscillatorDifferentialEquation(double x) {
    return -k * x;
}

double energyCalculator(double x, double v) {
    double energy = ((m * v * v) + (k * x * x)) / 2;
    return energy;
}

double oiler(double x0, double v0, double finalTime) {
    printf("For Oiler \n");
    double x = x0;
    double v = v0;
    double t = 0;
    while (t <= finalTime) {
        x += v * h;
        v += harmonicOscillatorDifferentialEquation(x) * h;
        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(x, v), t);
        t += h;
    }
}

double oilerCromer(double x0, double v0, double finalTime) {
    printf("For Oiler Cromer: \n");

    double x = x0;
    double v = v0;
    double t = 0;
    while (t <= finalTime) {

        v += harmonicOscillatorDifferentialEquation(x) * h;
        x += v * h;
        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(x, v), t);
        t += h;
    }
}

double meanAlgorithm(double x0, double v0, double finalTime) {
    printf("For Mean Algorithm: \n");

    double x = x0;
    double v = v0;
    double t = 0;
    while (t <= finalTime) {
        x += v * (h / 2);
        v += harmonicOscillatorDifferentialEquation(x) * h;
        x += v * (h / 2);
        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(x, v), t);
        t += h;
    }
}

double midPointAlgorithm(double x0, double v0, double finalTime) {
    printf("For Mid Point Algorithm: \n");
    double x = x0;
    double v = v0 + ((h / 2) * harmonicOscillatorDifferentialEquation(x0));//it's v 1/2

    double t = 0;
    while (t <= finalTime) {
        v += harmonicOscillatorDifferentialEquation(x) * h;//it's v n+1/2
        x += v * (h);
        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(x, v), t);
        t += h;
    }
}

double velocityVerletAlgorithm(double x0, double v0, double finalTime) {
    printf("For Velocity Verlet Algorithm: \n");
    double x = x0;
    double v = v0;
    double xnPlus1;
    double t = h;
    while (t <= finalTime) {

        xnPlus1 = x + (v * h) + ((harmonicOscillatorDifferentialEquation(x) / 2) * pow(h, 2));

        v += (harmonicOscillatorDifferentialEquation(x) + harmonicOscillatorDifferentialEquation(xnPlus1)) * (h / 2);

        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(xnPlus1, v), t);
        t += h;
        x = xnPlus1;
    }

}

double beemanAlgorithm(double x0, double v0, double finalTime) {

    printf("For Beeman Algorithm: \n");
    double xnMinus1 = x0;
    double v = v0 + (h * harmonicOscillatorDifferentialEquation(x0));//oiler

    double x = x0 + (h) * v; //oiler crumer

    double xnPlus1;

    double t = h;
    while (t <= finalTime) {


        xnPlus1 = x + v * h +
                  ((4 * harmonicOscillatorDifferentialEquation(x) - harmonicOscillatorDifferentialEquation(xnMinus1)) *
                   (pow(h, 2) / 6));

        v += (2 * harmonicOscillatorDifferentialEquation(xnPlus1) + 5 * harmonicOscillatorDifferentialEquation(x) -
              harmonicOscillatorDifferentialEquation(xnMinus1)) * (h / 6);


        printf(" x is %f  && v is %f  and energy is %f at Time %f\n", x, v, energyCalculator(xnPlus1, v), t);

        t += h;
        xnMinus1 = x;
        x = xnPlus1;

    }
}
