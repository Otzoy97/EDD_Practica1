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
    void setTiempo(int tiempo_);
    int getTiempo();
    friend ostream & operator << (ostream &out, const Cliente &a);
    int indice;
    
    Carreta usando;
private:
    
    int tiempo_espera;
    
    bool tieneCarreta;
};



#endif	/* CLIENTE_H */

