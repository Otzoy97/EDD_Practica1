/* 
 * File:   main.cpp
 * Author: sorem
 *
 * Created on 8 de junio de 2019, 11:09 PM
 */

#include <cstdlib>
#include <iostream>
#include "ListaCircularDoble.h"
#include "ListaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //El tiempo de servicio es el número de turnos que tarda una caja en atender un cliente
    //Número aleatorio para decidir el tiempo de servicio (1 - 10) (Al crear una caja -no varía)
    
    ListaDoble<int> *list = new ListaDoble<int>();
    
    for(int i=0 ; i<10 ; i++)
    {
        list->addLast(i);
    }
    
    for(int i = 0; i<10 ; i=i+2){
        list->remove(i);
    }
    cout<<list->removeAt(0)<<endl;
    cout<<list->removeAt(2)<<endl;
    
    cout<<endl;
    
    cout<<list->find(3)<<endl;
    cout<<list->find(0)<<endl;
    list->print();
    
    delete list;
}


