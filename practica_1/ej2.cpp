//
// Created by abrah on 11/10/2021.
//
#include "ej1.h"
#include "math.h"
#include "iostream"
#include "ej2.h"

using namespace std;

void mostrar_frecuencia(frecuencia *f) {
    cout << "Nº" << f->num << " - Veces " << f->veces << endl;
}

frecuencia* get_frecuencia(int num, frecuencia* f, int N){

    // Buscamos el número del dado correspondiente
    for (int i = 0; i < N; ++i) {

        // Hemos encontrado el número del dado
        if (f[i].num == num) return &f[i];
    }

    cout << "No se encontró frecuencia" << endl;

    // No se encontró el número del dado correspondiente
    return nullptr;
}

int tirada_dado(){
    return rand_minmax(1,6);
}

void ejecutar_ej2(){

    int TIRADAS = (int) pow(10, 7);

    int CARAS = 6;
    frecuencia frecuencias[CARAS];

    // Inicializamos las estructuras
    for(int i=0; i<CARAS; i++){
        frecuencia temp;
        temp.num = i+1;
        temp.veces = 0;
        frecuencias[i] = temp;
    }

    // Generamos las tiradas
    for(int i=0; i < TIRADAS; i++){
        int res_tirada = tirada_dado();
        //cout << "Tirada (" << i << "): " << res_tirada << endl;

        // Para el número del dado, sumamos 1 a la cuenta
        frecuencia *temp = get_frecuencia(res_tirada, frecuencias, CARAS);
        temp->veces++;
    }

    // Calculamos para cada número su frecuencia
    for (int i = 0; i < CARAS; ++i) {
        frecuencia temp = frecuencias[i];
        double frec_rel = ((double) temp.veces) / TIRADAS;
        cout << "Para el nº" << i+1 << " tenemos una frecuencia relativa " << frec_rel << endl;
    }
}