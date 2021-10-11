//
// Created by abrah on 11/10/2021.
//

#include "ej3.h"
#include "math.h"
#include "iostream"

using namespace std;

double calcular_media(int N){

    double sum = 0;
    for (int i = 0; i < N; ++i) {

        double x = frand(0, 1);
        //cout << (x) << endl;
        sum += 4 * sqrt(1 - pow(x, 2));
    }

    return sum / N;
}

void ejecutar_ej4(){

    int N = pow(10, 7);

    cout << "La media calculada (N=" << N << ") es " << calcular_media(N) << endl;
}