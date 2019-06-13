/* 
 * File:   Caja.h
 * Author: sorem
 *
 * Created on 12 de junio de 2019, 01:10 PM
 */

#ifndef CAJA_H
#define	CAJA_H

#include <iostream>
#include "Cliente.h"
using namespace std;

class Caja {
public:
    Caja(){estado = 0; indice = 0; tiempo_servicio = 0; atendiendo = 0;}
    Caja(int indice_);
    void setCliente(Cliente cliente);
    void delCliente();
    Cliente getCliente();
    bool isBusy();
    friend ostream & operator << (ostream &out, const Caja &a);
    int indice;
    int tiempo_servicio;
    bool estado;
private:
    
    Cliente atendiendo;
};



#endif	/* CAJA_H */

