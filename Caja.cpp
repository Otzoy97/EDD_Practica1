/* 
 * File:   Caja.cpp
 * Author: sorem
 * 
 * Created on 12 de junio de 2019, 01:10 PM
 */

#include "Caja.h"
#include <stdlib.h>

Caja::Caja(int indice_) {
    indice = indice_;
    tiempo_servicio = rand() % 5 + 1;
    estado = false;
    atendiendo = 0;
}
/**
 * Elimina al cliente de la caja
 * @return 
 */
void Caja::delCliente(){
    estado = false;
    atendiendo = 0;
}
/**
 * Especifica el cliente de la caja
 * @param cliente
 * @return 
 */
void Caja::setCliente(Cliente cliente){
    cliente.setTiempo(tiempo_servicio-1);
    estado = true;
    atendiendo = cliente;
}
/**
 * Recupera el cliente que se está atendiendo
 * @return 
 */
Cliente Caja::getCliente(){
    return atendiendo;
}

bool Caja::isBusy(){
    return estado;
}

ostream & operator << (ostream &out, const Caja &a)
{
    out << "Caja " << a.indice << endl << a.tiempo_servicio << " turnos" << endl;
    if(a.estado){
        out << "Ocupada" << endl << a.atendiendo;
    } else {
        out << "Libre" << endl;
    }
    return out;
}
