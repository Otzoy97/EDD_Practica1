/* 
 * File:   Cliente.h
 * Author: sorem
 *
 * Created on 12 de junio de 2019, 01:09 PM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <iostream>
#include "Carreta.h"

using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(int indice_);
    void setCarreta(Carreta carreta);
    Carreta devolverCarreta();
    friend ostream & operator << (ostream &out, const Cliente &a);
    int indice;
    Carreta usando;
    void disminuirTiempo();
    void setTiempo(const int &tiempo_);
    int getTiempo();
private:  
    bool tieneCarreta;
    int tiempo_espera;
};


#endif	/* CLIENTE_H */

