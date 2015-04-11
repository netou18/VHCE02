#ifndef LISTA_H_
#define LISTA_H_

#include <stdlib.h>
#include <iostream>
#include "nodo.h"
using namespace std;

/**
 * 		Lista doblemente enlazada
 */
template<class T> class Lista {
public:
	Lista();						//Constructor
	~Lista();						//Destructor
	void insertarFinal(T dato);		//Inserta un elemento al final
	void insertarInicio(T dato);	//Inserta un elemento al inicio
	void print();					//Imprime la lista en consola
	Nodo<T>* getPrimer();			//Obtener el primer elemento
	Nodo<T>* getUltimo();			//Obtener el ultimo elemento
private:
	Nodo<T>* primer;				//Primer nodo de la lista
	Nodo<T>* ultimo;				//Ultimo nodo de la lista
	bool vacia();					//Verifica si esta vacia la lista
};

/**
 * 	@brief Constructor de la lista
 */
template<class T> Lista<T>::Lista() {
	primer = ultimo = 0;
}

/**
 * 	@brief Destructor de la lista
 */
template<class T> Lista<T>::~Lista() {
	free(primer);
	free(ultimo);
}

/**
 * 	@brief Inserta un elemento al final
 * 	@param Dato a insetar
 */
template<class T> void Lista<T>::insertarFinal(T dato) {
	cout << "Agregando a lista..." << endl;
	Nodo<T>* nodo = (Nodo<T>*) malloc(sizeof(Nodo<T>));
	new (nodo) Nodo<T>(dato);
	cout << "Nodo creado." << endl;
	if (vacia()) {
		primer = ultimo = nodo;
	} else {
		nodo->setAnterior(ultimo);
		ultimo->setSiguiente(nodo);
		ultimo = nodo;
	}
}

/**
 * 	@brief Inserta un elemento al inicio
 * 	@param Dato a insetar
 */
template<class T> void Lista<T>::insertarInicio(T dato) {
	Nodo<T>* nodo = (Nodo<T>*) malloc(sizeof(Nodo<T> ));
	new (nodo) Nodo<T>(dato);
	if (vacia()) {
		primer = ultimo = nodo;
	} else {
		nodo->setSiguiente(primer);
		primer->setAnterior(nodo);
		primer = nodo;
	}
}

/**
 * 	@brief Obtiene primer elemento
 */
template<class T> Nodo<T>* Lista<T>::getPrimer() {
	return primer;
}

/**
 * 	@brief Obtiene ultimo elemento
 */
template<class T> Nodo<T>* Lista<T>::getUltimo() {
	return ultimo;
}

/**
 * 	@brief Imprime la lista en consola
 */
template<class T> void Lista<T>::print() {
	if (!vacia()) {
		Nodo<T>* actual = primer;
		while (*(actual->getDato()) != 0) {
			cout << "| " << *(actual->getDato()) << endl;
			actual = actual->getSiguiente();
		}
	} else
		cout << "Lista vacia" << endl;
}

/**
 * 	@brief Verficia si esta vacia la lista
 */
template<class T> bool Lista<T>::vacia() {
	if (primer == 0 and ultimo == 0) {
		return true;
	} else
		return false;
}

#endif /* LISTA_H_ */
