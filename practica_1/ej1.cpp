//
// Created by abrah on 11/10/2021.
//

#include "cstdlib"

int rand_minmax(int min, int max){
    return min + rand() % (max+1 - min);
}