//
// Created by abraham on 24/10/21.
//
#ifndef AAED_DATOS_GRAFICA_H
#define AAED_DATOS_GRAFICA_H

#include <iostream>
#include <fstream>
#include "map"
using namespace std;

class datos_grafica {

private:
    map<int, vector<double>> datos;

public:
    datos_grafica(){}

    void guardar(ofstream *file){

        map<int, vector<double>>::iterator datosIterator;

        for (datosIterator = datos.begin(); datosIterator != datos.end(); ++datosIterator) {

            int key = datosIterator->first;
            vector<double> tiemposDeLaIteracion = datosIterator->second;

            // Escribimos el valor de la iteración (x)
            *file << key;

            for (int j = 0; j < tiemposDeLaIteracion.size(); ++j) {

                // Escribimos la separación entre los valores y
                if (j != 0){
                    *file << ",";
                } else  {
                    *file << " ";
                }

                *file << tiemposDeLaIteracion.at(j);
            }

            // Salto de línea
            *file << endl;
        }

        file->close();
    }

    void unir(datos_grafica* d){

        map<int, vector<double>>::iterator datosIterator;

        for (datosIterator = d->datos.begin(); datosIterator != d->datos.end(); ++datosIterator) {

            int key = datosIterator->first;
            vector<double> tiemposDeLaIteracion = datosIterator->second;

            // Buscamos si ya existe una iteración con el mismo valor
            map<int, vector<double>>::iterator existe = this->datos.find(key);

            // Se ha encontrado el dato, unimos los tiempos
            if (existe != this->datos.end()){

                // Añadimos los tiempos a la iteración #key
                copy(tiemposDeLaIteracion.begin(), tiemposDeLaIteracion.end(), back_inserter(existe->second));
            }

            // No existe el dato, lo añadimos
            else {
                datos.insert({ key, tiemposDeLaIteracion });
            }
        }
    }

    void setDatos(vector<int> its, vector<double> datos){

        for (int i = 0; i < its.size(); ++i) {

            int key = its.at(i);
            vector<double> temp;
            temp.push_back(datos.at(i));

            // Guardamos los datos
            this->datos.insert({key, temp});
        }

    }

    void setDatos(map<int, vector<double>> datos){
        this->datos = datos;
    }
};


#endif //AAED_DATOS_GRAFICA_H
