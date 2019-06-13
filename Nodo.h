/* 
 * File:   Nodo.h
 * Author: sorem
 *
 * Created on 9 de junio de 2019, 12:00 AM
 */

#ifndef NODO_H
#define	NODO_H

template <class T> 
class Nodo {
public:
    //Atributos
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(T dato);
    Nodo(){dato = 0;}
    T getDato();
private:    
   T dato;
};
/**
 * 
 * @param dat
 */
template <class T> Nodo<T>::Nodo(T dat)
{
    dato = dat;
}
/**
 * 
 * @return 
 */
template <class T> T Nodo<T>::getDato()
{
    return dato;
}
#endif	/* NODO_H */

