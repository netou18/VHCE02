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
	Nodo<T>* getElemento(int ind);	//Obtener elemento del indice
	void borrarElemento(int ind);
private:
	Nodo<T>* primer;				//Primer nodo de la lista
	Nodo<T>* ultimo;				//Ultimo nodo de la lista
	bool vacia();					//Verifica si esta vacia la lista
	int contador;
	void sumInd(Nodo<T>* nodo);
	void resInd(Nodo<T>* nodo);
};

/**
 * 	@brief Constructor de la lista
 */
template<class T> Lista<T>::Lista() {
	primer = ultimo = 0;
	contador = 0;
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
	Nodo<T>* nodo = (Nodo<T>*) malloc(sizeof(Nodo<T> ));
	new (nodo) Nodo<T>(dato);
	if (vacia()) {
		primer = ultimo = nodo;
		nodo->setIndice(0);
		contador++;
	} else {
		nodo->setAnterior(ultimo);
		ultimo->setSiguiente(nodo);
		ultimo = nodo;
		nodo->setIndice(contador);
		contador++;
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
		nodo->setIndice(0);
		contador++;
	} else {
		nodo->setSiguiente(primer);
		primer->setAnterior(nodo);
		sumInd(primer);
		primer = nodo;
		contador++;
	}
}

template<class T> void Lista<T>::borrarElemento(int ind) {
	cout << "borrar: " << ind << endl;
	Nodo<T>* actual = primer;
	while (actual != 0) {
		if (((int) actual->getIndice()) != ind) {
			actual = actual->getSiguiente();
		} else {
			resInd(actual->getSiguiente());
			Nodo<T>* aux = actual->getAnterior();
			if(aux != 0)
				aux->setSiguiente(actual->getSiguiente());
			aux = actual->getSiguiente();
			if(aux != 0)
				aux->setAnterior(actual->getAnterior());
			break;
		}
	}
}

template<class T> void Lista<T>::sumInd(Nodo<T>* nodo) {
	Nodo<T>* actual = nodo;
	while (actual != 0) {
		actual->setIndice(actual->getIndice() + 1);
		actual = actual->getSiguiente();
	}
}

template<class T> void Lista<T>::resInd(Nodo<T>* nodo) {
	Nodo<T>* actual = nodo;
	while (actual != 0) {
		actual->setIndice(actual->getIndice() - 1);
		actual = actual->getSiguiente();
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

template<class T> Nodo<T>* Lista<T>::getElemento(int ind) {
	Nodo<T>* actual = primer;
	while (actual != 0) {
		if (actual->getIndice() != ind)
			actual = actual->getSiguiente();
		else
			return actual;
	}
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
