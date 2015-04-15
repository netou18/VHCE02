#ifndef NODO_H_
#define NODO_H_

#include <stdlib.h>
using namespace std;

template<class T> class Nodo {
public:
	Nodo(T dato);									//Constructor
//	~Nodo();										//Destructor
	T* getDato();								//Obtener dato dentro del nodo
	Nodo<T>* getSiguiente();						//Obtener nodo siguiente
	Nodo<T>* getAnterior();							//Obtener nodo anterior
	void setSiguiente(Nodo* sig);					//Asigna nodo siguiente
	void setAnterior(Nodo* ant);					//Asigna nodo anterior
	int getIndice();
	void setIndice(int num);
private:
	T* atributo;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;
	int indice;
};

/**
 *	@brief Constructor del nodo
 *	@param dato Dato a almacenar en nodo
 */
template<class T> Nodo<T>::Nodo(T dato) {
	atributo = (T*) malloc(sizeof(dato));
	*atributo = dato;
	anterior = siguiente = 0;
	indice = 0;
}

/**
 * 	@brief Obtener dato dentro de nodo
 */
template<class T> T* Nodo<T>::getDato() {
	return atributo;
}

/**
 * 	@brief Destructor del nodo
 */
//template<class T> Nodo<T>::~Nodo() {
//	delete this;
//}

/**
 * 	@brief Obtiene el nodo siguiente
 */
template<class T> void Nodo<T>::setSiguiente(Nodo<T>* sig) {
	siguiente = sig;
}

/**
 * 	@brief Obtiene el nodo anterior
 */
template<class T> void Nodo<T>::setAnterior(Nodo<T>* ant) {
	anterior = ant;
}

/**
 * 	@brief Asigna el nodo siguiente
 */
template<class T> Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}

/**
 * 	@brief Asigna el nodo anterior
 */
template<class T> Nodo<T>* Nodo<T>::getAnterior() {
	return anterior;
}

template<class T> void Nodo<T>::setIndice(int ind){
	indice = ind;
}

template<class T> int Nodo<T>::getIndice(){
	return indice;
}

#endif /* NODO_H_ */
