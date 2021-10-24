//
// Created by abraham on 18/10/21.
//

#include <iostream>
#include "numeric"
#include <vector>
#include "algorithm"
#include "ordenacion.h"
#include "analisis_empirico.h"
#include "cronometro.h"
#include "datos_grafica.h"

using namespace std;

datos_grafica analizar_ordenacion_intercambio(int n, int MAX_N, int INCREMENTO_N){

    datos_grafica d;
    vector<int> iteraciones = vector<int>(MAX_N / INCREMENTO_N);
    cronometro c;
    vector<double> tiempos_orde_intercambio(MAX_N / INCREMENTO_N);

    // Inicializamos el vector con n elementos, en orden creciente
    vector<int> vec(n);
    iota(begin(vec), end(vec), 0);

    // Realizamos el experimento
    int j = 0;
    for (int i = n; i <= MAX_N; i += INCREMENTO_N) {

        // Activamos el cronometro
        c.activar();

        // Realizamos la ordenación del vector
        ordenacion_intercambio(&vec.at(0), &vec.back());

        // Guardamos el tiempo que ha tardado
        c.parar();
        double tiempo = c.tiempo();
        tiempos_orde_intercambio.at(j) = tiempo;

        // Guardamos el valor de la iteración actual
        iteraciones.at(j) = i;

        // Creamos un nuevo vector con un mayor tamaño
        vec = vector<int>(INCREMENTO_N + vec.size());
        iota(begin(vec), end(vec), 0);          // Llenamos con los primeros n naturales
        random_shuffle(begin(vec), end(vec));        // Lo desordenamos

        j++;
    }

    // Paramos el vector
    c.parar();

    // Mostramos los tiempos que ha tardado el algoritmo
    cout << "----- Algoritmo de intercambio -----" << endl;
    for (int i = 0; i < tiempos_orde_intercambio.size(); ++i) {
        cout << "(n=" << n*(i+1) << ") -> " << tiempos_orde_intercambio.at(i) << endl;
    }
    cout << "------------------------------" << endl << endl;

    // Guardamos los tiempos de cada iteración
    d.setDatos(iteraciones, tiempos_orde_intercambio);

    return d;
}

datos_grafica analizar_ordenacion_seleccion(int n, int MAX_N, int INCREMENTO_N){

    datos_grafica d;
    vector<int> iteraciones = vector<int>(MAX_N / n);
    cronometro c;
    vector<double> tiempos_orde_seleccion(MAX_N / n);

    // Inicializamos el vector con n elementos, en orden creciente
    vector<int> vec(n);
    iota(begin(vec), end(vec), 0);



    // Realizamos el experimento
    int j = 0;
    for (int i = n; i <= MAX_N; i += INCREMENTO_N) {

        // Activamos el cronometro
        c.activar();

        // Realizamos la ordenación del vector
        ordenacion_seleccion(&vec.at(0), &vec.back());

        // Guardamos el tiempo que ha tardado
        c.parar();
        double tiempo = c.tiempo();
        tiempos_orde_seleccion.at(j) = tiempo;

        // Guardamos la iteración actual
        iteraciones.at(j) = i;

        // Creamos un nuevo vector con un mayor tamaño
        vec = vector<int>(INCREMENTO_N + vec.size());
        iota(begin(vec), end(vec), 0);          // Llenamos con los primeros n naturales
        random_shuffle(begin(vec), end(vec));        // Lo desordenamos

        j++;
    }

    // Paramos el vector
    c.parar();

    // Mostramos los tiempos que ha tardado el algoritmo
    cout << "----- Algoritmo de selección -----" << endl;
    for (int i = 0; i < tiempos_orde_seleccion.size(); ++i) {
        cout << "(n=" << n*(i+1) << ") -> " << tiempos_orde_seleccion.at(i) << endl;
    }
    cout << "------------------------------" << endl << endl;

    d.setDatos(iteraciones, tiempos_orde_seleccion);

    return d;
}

datos_grafica analizar_ordenacion_inserccion(int n, int MAX_N, int INCREMENTO_N){

    datos_grafica d;
    vector<int> iteraciones = vector<int>(MAX_N / n);
    cronometro c;
    vector<double> tiempos_orde_inserccion(MAX_N / n);

    // Inicializamos el vector con n elementos, en orden creciente
    vector<int> vec(n);
    iota(begin(vec), end(vec), 0);

    // Realizamos el experimento
    int j = 0;
    for (int i = n; i <= MAX_N; i += INCREMENTO_N) {

        // Activamos el cronometro
        c.activar();

        // Realizamos la ordenación del vector
        ordenacion_insercion(&vec.at(0), &vec.back());

        // Guardamos el tiempo que ha tardado
        c.parar();
        double tiempo = c.tiempo();
        tiempos_orde_inserccion.at(j) = tiempo;

        // Guardamos la iteración actual
        iteraciones.at(j) = i;

        // Creamos un nuevo vector con un mayor tamaño
        vec = vector<int>(INCREMENTO_N + vec.size());
        iota(begin(vec), end(vec), 0);          // Llenamos con los primeros n naturales
        random_shuffle(begin(vec), end(vec));        // Lo desordenamos

        j++;
    }

    // Paramos el vector
    c.parar();

    // Mostramos los tiempos que ha tardado el algoritmo
    cout << "----- Algoritmo de insercción -----" << endl;
    for (int i = 0; i < tiempos_orde_inserccion.size(); ++i) {
        cout << "(n=" << n*(i+1) << ") -> " << tiempos_orde_inserccion.at(i) << endl;
    }
    cout << "------------------------------" << endl << endl;

    d.setDatos(iteraciones, tiempos_orde_inserccion);

    return d;
}

void analisis_empirico_prac2_ej3() {

    int n = 1000;
    int MAX_N = 20000;
    int INCREMENTO_N = 1000;

    // Realizamos el primer experimento
    datos_grafica datosIntercambio = analizar_ordenacion_intercambio(n, MAX_N, INCREMENTO_N);
    datos_grafica datosSeleccion = analizar_ordenacion_seleccion(n, MAX_N, INCREMENTO_N);
    datos_grafica datosInserccion = analizar_ordenacion_inserccion(n, MAX_N, INCREMENTO_N);

    // Guardamos los resultados
    ofstream resultados1;
    resultados1.open("prueba-1.tmp");
    datosIntercambio.guardar(&resultados1);

    ofstream resultados2;
    resultados2.open("prueba-2.tmp");
    datosSeleccion.guardar(&resultados2);

    ofstream resultados3;
    resultados3.open("prueba-3.tmp");
    datosInserccion.guardar(&resultados3);


    // Unimos todos los datos
    /*datos_grafica tiempos;
    tiempos.unir(&datosIntercambio);
    tiempos.unir(&datosSeleccion);
    tiempos.unir(&datosInserccion);*/
}