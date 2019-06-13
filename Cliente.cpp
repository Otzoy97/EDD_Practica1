/* 
 * File:   Cliente.cpp
 * Author: sorem
 * 
 * Created on 12 de junio de 2019, 01:09 PM
 */

#include "Cliente.h"

ostream & operator << (ostream &out, const Cliente &a){
    out << "Cliente " << a.indice;
    if(a.tieneCarreta)
        out << "\\n" << a.usando;
    return out;
}

Cliente::Cliente(){
    indice = 0;
    tiempo_espera = 0;
    usando = 0;
    tieneCarreta = false;
}

Cliente::Cliente(int indice_){
    indice = indice_;
    tiempo_espera = 0;
    usando = 0;
    tieneCarreta = false;
}

void Cliente::setCarreta(Carreta carreta){
    usando = carreta;
    tieneCarreta = true;
}

Carreta Cliente::devolverCarreta(){
    tieneCarreta = false;
    return usando;
}

void Cliente::disminuirTiempo(){
    --tiempo_espera;
}
void Cliente::setTiempo(const int& tiempo_){
    tiempo_espera = tiempo_;
}
int Cliente::getTiempo(){
    return tiempo_espera;
}