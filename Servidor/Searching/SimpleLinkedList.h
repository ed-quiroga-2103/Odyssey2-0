#include "QString"
//
// Created by Isaac  Porras  on 22/2/18.
//
#include "nodosimple.h"
#define null 0;


/**
  *@file simplelinkedlist.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Simple Linked List
  * @brief Estructura de la lista simple
  */
/**
 * @brief The SimpleLinkedList class Estructura de la lista simple
 */
class SimpleLinkedList {
public:
    NodoSimple *primero;
    NodoSimple *ultimo;
    int largo = 0;

    //DEFINICION DE LA CLASE

public:
    /**
     * @brief SimpleLinkedList incializa la lista simple
     */
    SimpleLinkedList(){
        primero = ultimo = null;
        ultimo = primero = null;
    }

    // INSERTAR POR POSICION

public:
    /**
 * @brief insertarPorPosicion inserta un nodo en una posicion en especifico
 * @param pos posicon en la que se va a insertar
 * @param dato dato del nodo
 */
    void insertarPorPosicion(int pos, QString dato){

        NodoSimple *corredor = primero;
        NodoSimple *temporal = new NodoSimple(dato);
        std::cout<<largo<<std::endl;
        if(pos > largo){
            std::cout << "El rango esta fuera del alcance: "<< pos <<", ya que se tiene un lagro = "<< largo << std::endl;
            return;
        }
        if(pos == 1){

            this->ingresarDatoInicio(dato);



            NodoSimple *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
            return;
        }
        else{

            while(corredor-> getPos() != (pos-1)){
                corredor = corredor->siguiente;
            }

            if(corredor->siguiente->getPos() == pos){
                temporal->siguiente = corredor->siguiente;
                corredor->siguiente = temporal;

                NodoSimple *corredor2 = primero;
                int contador = 1;
                while(corredor2 != 0){
                    corredor2->setPos(contador);
                    contador = contador + 1;
                    corredor2 = corredor2->siguiente;
                }
            }
            else{
                std::cout << "No se pudo eliminar el dato" << std::endl;
            }
        }

    }

    //INGRESAR AL FINAL

public:
    /**
     * @brief ingresarDatoFinal inserta un dato al final de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoFinal(QString dato){

        NodoSimple *temporal = new NodoSimple(dato);

        if( primero == 0 ){
            primero = temporal;
            ultimo = temporal;
            largo = largo + 1;
        }
        else {
            ultimo -> siguiente = temporal;
            ultimo = temporal;
            largo = largo + 1;
        }

        NodoSimple *corredor = primero;
        int contador = 1;

        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor -> siguiente;
        }


    }

    //INGRESAR AL INICIO

public:
    /**
     * @brief ingresarDatoInicio inserta un nodo al inicio de la lista
     * @param dato dato del nodo
     */
    void ingresarDatoInicio(QString dato){
        NodoSimple *temporal = new NodoSimple(dato);

        if( primero == 0 ){
            primero = temporal;
            ultimo = temporal;
            largo = largo+1;
        }
        else{
            temporal->siguiente = primero;
            primero = temporal;
            largo = largo+1;
        }

        NodoSimple *corredor = primero;
        int contador = 1;
        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor->siguiente;
        }
    }


    // ELIMINAR POR POSICION

public:
    /**
     * @brief eliminarPosicion elimina un nodo en una posicion en especifico
     * @param pos posicion en la que se va a eliminar
     */
    void eliminarPosicion(int pos){
        NodoSimple *corredor = primero;
        while(corredor-> getPos() != (pos-1)){
            corredor = corredor->siguiente;
        }
        if(corredor->siguiente->getPos() == pos){

            corredor->siguiente = corredor->siguiente->siguiente;
            largo = largo-1;


            NodoSimple *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
        }
        else{
            std::cout << "No se pudo eliminar el dato" << std::endl;
        }

    }
    //ELIMINAR AL INICIO

public:
    /**
     * @brief eliminarInicio elimina el nodo del inicio de la lista
     */
    void eliminarInicio() {
        primero = primero->siguiente;

        largo=largo-1;
        NodoSimple *corredor = primero;
        int contador = 1;
        while(corredor != 0){
            corredor->setPos(contador);
            contador = contador + 1;
            corredor = corredor->siguiente;


            NodoSimple *corredor2 = primero;
            int contador = 1;
            while(corredor2 != 0){
                corredor2->setPos(contador);
                contador = contador + 1;
                corredor2 = corredor2->siguiente;
            }
        }
    }

    //ELIMINAR AL FINAL

public:
    /**
     * @brief eliminarFinal elimina el nodo del final de la lista
     */
    void eliminarFinal() {

        if(primero == 0){
            return;
        }
        else {

            NodoSimple *corredor = primero;
            int contador = 1;

            while(corredor->siguiente != ultimo){

                corredor->setPos(contador);
                contador = contador + 1;
                corredor = corredor->siguiente;
            }
            corredor->siguiente = 0;
            ultimo = corredor;
            delete(corredor->siguiente);
            largo = largo - 1;

        }
    }

    // IMPRIMIR LISTA

public:
    /**
     * @brief imprimirLista imprime la lista
     */
    void imprimirLista(){
        NodoSimple *corredor = primero;
        if (primero == 0){
            std::cout << "No hay elementos en la lista" << std::endl;
        }
        else{
            while(corredor != 0){
//                    std::cout << "El elemento es: "<< corredor->getDato() << " y esta en la posicion :" << corredor->getPos() <<std::endl;

                corredor = corredor->siguiente;
            }
        }
    }

    //EDITAR POR POSICION

public:
    /**
     * @brief editar edita el dato de un nodo en especifico
     * @param pos posicion del nodo que se quiere editar
     * @param dato dato por el que se quiere modificar
     */
    void editar(int pos, QString dato){


        NodoSimple *corredor = primero;

        while(corredor-> getPos() != pos){
            corredor = corredor->siguiente;
        }

        if(corredor->getPos() == pos){
            corredor->setDato(dato);

        }
        else{
            std::cout << "No se pudo editar el dato" << std::endl;
        }

    }

public:
    /**
     * @brief obtenerporPosicion retorna el nodo que se esta buscando
     * @param pos posicion del nodo buscado
     * @return el nodo buscado
     */
    NodoSimple obtenerporPosicion(int pos){
        NodoSimple *corredor = primero;
        if (pos < largo){


            while(corredor-> getPos() != pos){
                corredor = corredor->siguiente;
            }
//                std::cout << corredor->getDato() << std::endl;
            return *corredor;
        }
        else{
//                std::cout << "El largo es menor que la posicion digitada"<< std::endl;
            corredor;

        }

    }



};