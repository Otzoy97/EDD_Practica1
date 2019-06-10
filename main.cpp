/* 
 * File:   main.cpp
 * Author: sorem
 *
 * Created on 8 de junio de 2019, 11:09 PM
 */

#include <cstdlib>
#include <iostream>
#include "ListaCircularDoble.h"
using namespace std;
/**/
//template <class T> void addLast(T dato);
//template <class T> void ListaCircularSimple<T>::print();

/*
 * 
 */
int main(int argc, char** argv) {
    ListaCircularDoble<int> *list = new ListaCircularDoble<int>();
    for(int i=0; i<10;i++){
        list->addLast(i);
    }
    list->print();
    return 0;
}


