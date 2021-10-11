//
// Created by abrah on 11/10/2021.
//

#include "cstdlib"

double frand(double fMin, double fMax)
{
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}