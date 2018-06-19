#include "QString"
#include <iostream>
#include <string>

using std::string;
#define null 0;

/**
  *@file nodosimple.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Nodo Simple
  * @brief Estructura del nodo de la lista simple
  */
/**
 * @brief The NodoSimple class Estructura del nodo de la lista simple
 */
class NodoSimple{
private:
    QString dato;
    int posicion;
public:
    NodoSimple *siguiente;
    /**
 * @brief NodoSimple incia el nodo
 * @param dat
 */
    NodoSimple (QString dat){
        this->dato = dat;
        siguiente = null;
    }
    /**
     * @brief getDato da el dato del nodo
     * @return QString del nodo
     */
    QString getDato(){
        return dato;
    }

public:
    /**
         * @brief setPos establece la posicion del nodo
         * @param pos posicion del nodo
         */
    void setPos(int pos){
        this->posicion = pos;
    }
public:
    /**
      * @brief getPos da la posicion del nodo
      * @return entero con la posicion del nodo
      */
    int getPos(){
        return this->posicion;
    }
public:
    /**
    * @brief setDato establece el dato del nodo
    * @param dat dato del nodo
    */
    void setDato(QString dat){
        this->dato = dat;
    }
};