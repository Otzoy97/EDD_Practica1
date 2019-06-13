/* 
 * File:   main.cpp
 * Author: sorem
 *
 * Created on 8 de junio de 2019, 11:09 PM
 */

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>
#include "ListaCircularDoble.h"
#include "ListaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include <string.h>
#include <stdio.h>
#include "Carreta.h"
#include "Caja.h"
#include <stdlib.h>
#include "Nodo.h"

using namespace std;

//Contador de clientes
int no_clientes = 1;
//Contador de turnos
int no_turno = 0;
//Flag para la continua ejecución del MENU
bool flag = true;
Pila<Carreta> *carretas1 = new Pila<Carreta>();
Pila<Carreta> *carretas2 = new Pila<Carreta>();
ListaDoble<Caja> *cajas = new ListaDoble<Caja>();
ListaCircularDoble<Cliente> *compras = new ListaCircularDoble<Cliente>();
Cola<Cliente> *clPagar = new Cola<Cliente>();
Cola<Cliente> *clCarreta = new Cola<Cliente>();

int menu();
int recorrer();
int reportar();

/*
 * 
 */
int main(int argc, char** argv) {
    //El tiempo de servicio es el número de turnos que tarda una caja en atender un cliente
    //Número aleatorio para decidir el tiempo de servicio (1 - 10) (Al crear una caja -no varía)                
    int int_carretas = 0, int_cajas = 0, int_compras = 0, int_clpagar = 0, int_clcarreta = 0;
    //Muestra mensajes de inicialización
    cout << "Inicializando..." << endl;
    //Solicita cantidad de carretas
    cout << ">> Cantidad carretas" << endl;
    scanf("%d",&int_carretas);
    //Solicita cantidad de cajas
    cout << ">> Cantidad cajas" << endl;
    scanf("%d",&int_cajas);
    //Solicita cantidad inicial de clientes de espera de carretas (cola)
    cout << ">> Cantidad inicial de clientes esperando carretas" << endl;
    scanf("%d",&int_clcarreta);
    do{
        //Solicita cantidad inicial de clientes comprando (lista doble enlazada)
        cout << ">> Cantidad inicial de clientes comprando" << endl;
        scanf("%d",&int_compras);
        //Solicita cantidad inicial de clientes es espera de pago (cola)
        cout << ">> Cantidad inicial de clientes esperando pagar" << endl;
        scanf("%d",&int_clpagar);
        //Verifica que la suma de clientes esperando pagar  
        //y clientes comprando sea menor o igual a la cantidad de carretas
        if((int_compras + int_clpagar) > int_carretas)
            cout << endl << "La suma de clientes comprando y esperando pagar excede la cantidad de carretas disponibles" << endl << "Especifique de nuevo estos datos" << endl << endl;
    } while ((int_compras + int_clpagar) > int_carretas);
    //Crea las cajas
    for(int i = 0; i < int_cajas ; i++ ){
        Caja iCaja(i+1);
        cajas->addLast(iCaja);
    }
    //Crea las carretas
    for(int i = 0; i < int_carretas; i++){
        Carreta carr(i+1);
        if(rand()%2){
            carretas1->push(carr);
        } else {
            carretas2->push(carr);
        }
    }
    //Clientes esperando pagar
    while(int_clpagar){
        Cliente iCliente(no_clientes++);
        //Les asigna carretas
        if(rand()%2){
            iCliente.setCarreta(!carretas1->isEmpty() ? carretas1->pop() : carretas2->pop());
        } else {
            iCliente.setCarreta(!carretas2->isEmpty() ? carretas2->pop() : carretas1->pop());
        }
        //Encola al cliente
        clPagar->encolar(iCliente);
        int_clpagar--;
    }
    //Clientes comprando-
    while(int_compras){
        Cliente iCliente(no_clientes++);
        if(rand()%2){
            iCliente.setCarreta(!carretas1->isEmpty() ? carretas1->pop() : carretas2->pop());
        } else {
            iCliente.setCarreta(!carretas2->isEmpty() ? carretas2->pop() : carretas1->pop());
        }
        //Encola al clientes
        compras->addLast(iCliente);
        int_compras--;
    }
    //Clientes esperando carretas
    while(int_clcarreta){
        Cliente iCliente(no_clientes++);
        clCarreta->encolar(iCliente);
        int_clcarreta--;
    }
    //Comienzando simulación
    cout << endl << "Comenzando..." << endl;
    while (flag){
        menu();
    }
}
/**
 * Muestra una lista de opciones al usuario y ejecuta su elección
 * @return 
 */
int menu(){
    int opcion;
    cout << "================== TURNO "<< ++no_turno << " ==================" << endl << endl;
    cout << "------------ MENU -------------" << endl;
    cout << "| 1. Insertar nuevos clientes |" << endl;
    cout << "| 2. Mostrar reportes         |" << endl;
    cout << "-------------------------------" << endl;
    //Recupera la decisión del usuario
    do{
        scanf("%d",&opcion);
        if( opcion!=1 && opcion!=2 )
            cout << "Especifica una opción válida" << endl;
    } while ( opcion!=1 && opcion!=2 );
    
    if(opcion == 1){
        //Nuevos clientes
        recorrer();
    } else if (opcion == 2){
        //Mostrar reportes
        reportar();
    }
    return 0;
}
/**
 * Recorre todas las estructuras realizando las operaciones pertinentes
 * @return 
 */
int recorrer(){
    int nuevos;
    cout << "¿Cuántos nuevos clientes entrarán?" << endl;
    //Especifica la cantidad de nuevos clientes
    do{
        scanf("%d", &nuevos);
        if (nuevos < 0)
            cout << "Solo números positivos" << endl;
    } while (nuevos < 0);
    cout << endl;
    //Recorre la lista de cajas buscando clientes en los que 
    //ya haya finalizado su tiempo de espera
    Cliente tempCliente;
    Caja tempCaja;
    int random = rand()%100 + 1;
    int temp = 0;
    int auxLargo = cajas->getLargo();
    for(int i =0 ; i < auxLargo ; i++){
        tempCaja = cajas->removeAt(0);
        if(tempCaja.isBusy()){
            if(tempCaja.getCliente().getTiempo() == 0){
                //Decide a dónde mandar la carreta que se liberará
                if(rand()%2){
                    carretas1->push(tempCaja.getCliente().devolverCarreta());
                    cout << "Cliente " << tempCaja.getCliente().indice << " salió del supermercado. " << carretas1->peek() << " y caja " << tempCaja.indice << " libres" << endl << endl;
                } else {
                    carretas2->push(tempCaja.getCliente().devolverCarreta());
                    cout << "Cliente " << tempCaja.getCliente().indice << " salió del supermercado. " << carretas2->peek() << " y caja " << tempCaja.indice << " libres" << endl << endl;
                }
                //Decide de dónde sacar clientes para meter a la caja recién liberada
                if(!clPagar->isEmpty()){
                    cout << "Cliente " << clPagar->peek().indice << " salió de cola de pagos y empezó a ser atendido por Caja " << tempCaja.indice << ". Quedan " << ( tempCaja.tiempo_servicio - 1)  << " turnos" <<endl << endl;
                    tempCaja.setCliente(clPagar->desencolar());
                    tempCaja.estado = true;
                } else {
                    if(random <= compras->getLargo()){
                        tempCaja.setCliente(compras->removeAt(random-1));
                        tempCaja.estado = true;
                        cout << "Cliente " << tempCaja.getCliente().indice << " salió de lista de compras y empezó a ser atendido por Caja " << tempCaja.indice << ". Quedan " << ( tempCaja.tiempo_servicio - 1) << " turnos" <<endl << endl;
                    } else {
                        //No se pasó ningún clinete, la caja se libera totalmente
                        tempCaja.delCliente();
                    }
                    random = rand()%100+1;
                } 
            } else {
                //Se actualiza el conteo
                tempCaja.actualizarContador();
                cout << "Cliente " << tempCaja.getCliente().indice << " está siendo atendido por Caja " << tempCaja.indice << ". Quedan "  << tempCaja.getCliente().getTiempo() << " turnos" << endl << endl;
                
            }
        } else {
            //Decide de dónde sacar clientes para meter a la caja libre
            if(!clPagar->isEmpty()){
                cout << "Cliente " << clPagar->peek().indice << " salió de cola de pagos y empezó a ser atendido por Caja " << tempCaja.indice << ". Quedan " << ( tempCaja.tiempo_servicio - 1)  << " turnos" <<endl << endl;
                tempCaja.setCliente(clPagar->desencolar());
                tempCaja.setEstado(true);
            } else {
                if(random <= compras->getLargo()){
                    tempCaja.estado = true;
                    tempCaja.setCliente(compras->removeAt(random-1));
                    cout << "Cliente " << tempCaja.getCliente().indice << " salió de lista de compras y empezó a ser atendido por Caja " << tempCaja.indice << ". Quedan " << ( tempCaja.tiempo_servicio - 1) << " turnos" <<endl << endl;
                }
                random = rand()%100+1;
            } 
        }
        cajas->addLast(tempCaja);
    }
    //Sacar de la lista y meter a la cola de pagos
    if(random <= compras->getLargo()){
        //Es un índice adecuado
        clPagar->encolar(compras->removeAt(random-1));
        cout << "Cliente " << clPagar->peek().indice << " ha entrado ha la cola de pagos" << endl << endl;
    } 
    //Determina si hay clientes esperando carretas
    //Determina si hay carretas disponibles
    while(!clCarreta->isEmpty() && (!carretas1->isEmpty() || !carretas2->isEmpty())){
        tempCliente = clCarreta->desencolar();
        //Le asigna carretas
        if(rand()%2){
            tempCliente.setCarreta(!carretas1->isEmpty() ? carretas1->pop() : carretas2->pop());
        } else {
            tempCliente.setCarreta(!carretas2->isEmpty() ? carretas2->pop() : carretas1->pop());
        }
        //Agrega el cliente a la cola de compras
        compras->addLast(tempCliente);
        cout << "Cliente " << tempCliente.indice << " con " << tempCliente.usando << " entro a la lista de compras" << endl << endl;
    }
    //Ya no hay más clientes en la cola, pero aún hay carretas disponibles 
    //nuevo no es cero
    while( (!carretas1->isEmpty() || !carretas2->isEmpty()) && nuevos){
        Cliente iCliente(no_clientes++);
        if(rand()%2){
            iCliente.setCarreta(!carretas1->isEmpty() ? carretas1->pop() : carretas2->pop());
        } else {
            iCliente.setCarreta(!carretas2->isEmpty() ? carretas2->pop() : carretas1->pop());
        }
        compras->addLast(iCliente);
        cout << "Cliente " << iCliente.indice << " ha entrado a comprar con " << iCliente.usando << endl << endl;
        nuevos--;
    } 
    //Ya no hay carretas disponibles, pero aún hay clientes 
    while(nuevos){
        Cliente iCliente(no_clientes++);
        clCarreta->encolar(iCliente);
        cout << "Cliente " << iCliente.indice << " espera por una carreta" << endl << endl ;
        nuevos--;
    }
    cout << endl;
}
/**
 * Recupera el texto dot de las estructuras, genera el grafo, el archivo, la imagen y por último la muestra
 * @return 
 */
int reportar(){
    stringstream str;
    int contador =0;
    str << "digraph G{" << endl;
    str << "rankdir = LR;" << endl << "node [shape=record, fontsize=10]" << endl;
    str << cajas->dot("Cajas", contador++) << endl;
    if (!clPagar->isEmpty())
        str << clPagar->dot("Cola de pago", contador++) << endl;
    if (!compras->isEmpty())
        str <<  compras->dot("Compras", contador++) << endl;
    if(!clCarreta->isEmpty())
        str << clCarreta->dot("Cola de_carretas",contador++) << endl;
    str << carretas1->dot("Pila 1", contador++) << endl;
    str << carretas2->dot("Pila 2", contador++) << endl;
    
    str << "p" << carretas1 << "-> p" << carretas2 << endl;
    str << "}";
    stringstream aux;
    aux << "turno" << no_turno;
    char cmd[50] = "dot -Tpng ";
    strcat(cmd, aux.str().c_str());
    strcat(cmd, " -o ");
    strcat(cmd, aux.str().c_str());
    strcat(cmd, ".png");
    //Crea el archivo dot
    ofstream fp;
    fp.open(aux.str());
    fp << str.str();
    fp.close();
    system(cmd);
    remove(aux.str().c_str());
    //Muestra la imagen
    char abrir[20] = "eog ";
    strcat(abrir, aux.str().c_str());
    strcat(abrir,".png");
    system(abrir);
}