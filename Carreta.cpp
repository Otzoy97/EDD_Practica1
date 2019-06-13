/* 
 * File:   Carretas.cpp
 * Author: sorem
 * 
 * Created on 12 de junio de 2019, 01:09 PM
 */

#include "Carreta.h"

ostream & operator <<(ostream &out, const Carreta &a){
    out << "Carreta " << a.indice;
    return out;
}

Carreta::Carreta(int indice_){
    indice = indice_;
}

Carreta::Carreta(){
    indice = 0;
}


