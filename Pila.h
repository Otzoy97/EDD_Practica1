/* 
 * File:   Pila.h
 * Author: sorem
 *
 * Created on 10 de junio de 2019, 01:46 PM
 */

#ifndef PILA_H
#define	PILA_H
#include "Nodo.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Pila{
    public:
        bool isEmpty();
        int getLargo();
        void push(T dato);
        //bool find(T dato);
        T peek();
        T pop();
        //T removeAt(int index);
        void print();
        string dot(const string& nombre, int contador);
    private:
        string recorrer(Nodo<T> *nodito);
        Nodo<T> *inicio;
        //Nodo<T> *final;
        int largo = 0;
};

template <class T> bool Pila<T>::isEmpty(){
    return inicio == NULL;
}

template <class T> int Pila<T>::getLargo(){
    return largo;
}

template <class T> void Pila<T>::push(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if(!isEmpty()){
        nuevo->siguiente = inicio;
        inicio = nuevo;
        largo++;
    } else {
        inicio = nuevo;
        largo++;
    }
}

template <class T> T Pila<T>::peek(){
    return inicio->getDato();
}

template <class T> T Pila<T>::pop(){
    T dato = inicio->getDato();
    Nodo<T> *temp = inicio;
    inicio = temp->siguiente;
    delete temp;
    largo--;
    return dato;
}

template <class T> void Pila<T>::print(){
    Nodo<T> *temp = inicio;
    while (temp!=NULL){
        std::cout<<temp->getDato()<<std::endl;
        temp = temp->siguiente;
    }
    delete temp;
}

template <class T> string Pila<T>::dot(const string& nombre, int contador){
    stringstream retorno;
    //Nodo<T> *temp = inicio;
    retorno << "subgraph cluster" << contador << " {" << endl;
    retorno << "label = \"" << nombre << "\"" << endl;
    retorno << "p" << this << "[";
    string cadena = recorrer(inicio);
    retorno << "label = \"" << cadena.substr(0,cadena.length()-1) << "\""<<" color = black]" << endl;
    retorno << "color = white"<<endl<<"style = filled"<<endl;
    retorno << "}" << endl;
    return retorno.str();
}

template <class T> string Pila<T>::recorrer(Nodo<T> *nodito){
    stringstream retorno;
    if(nodito!=NULL)
        retorno << nodito->getDato() << "|" << recorrer(nodito->siguiente);
    return retorno.str();
}
#endif	/* PILA_H */

