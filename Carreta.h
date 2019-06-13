/* 
 * File:   Carretas.h
 * Author: sorem
 *
 * Created on 12 de junio de 2019, 01:09 PM
 */

#ifndef CARRETA_H
#define	CARRETA_H

#include <iostream>

using namespace std;

class Carreta {
public:
    Carreta();
    Carreta(int indice);
    friend ostream & operator << (ostream &out, const Carreta &a);
private:
    int indice;
};


#endif	/* CARRETA_H */

