#ifndef NODO_H_
#define NODO_H_

#include <stdlib.h>
using namespace std;

template<class T> class Nodo {
public:
	Nodo(T dato);									//Constructor
	Nodo(T* dato, Nodo* siguiente);					//Constructor
	Nodo(T* dato, Nodo* siguiente, Nodo* anterior);	//Constructor
	~Nodo();										//Destructor
	T* getDato();								//Obtener dato dentro del nodo
	Nodo<T>* getSiguiente();						//Obtener nodo siguiente
	Nodo<T>* getAnterior();							//Obtener nodo anterior
	void setSiguiente(Nodo* sig);					//Asigna nodo siguiente
	void setAnterior(Nodo* ant);					//Asigna nodo anterior
private:
	T* atributo;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;
};

/**
 *	@brief Constructor del nodo
 *	@param dato Dato a almacenar en nodo
 */
template<class T> Nodo<T>::Nodo(T dato) {
	atributo = (T*) malloc(sizeof(dato));
	*atributo = dato;
	anterior = siguiente = 0;
	cout << "hgfh" << endl;
}

/**
 *	@brief Constructor del nodo
 *	@param dato Dato a almacenar en nodo
 *	@param sig Nodo siguiente
 */
template<class T> Nodo<T>::Nodo(T* dato, Nodo* sig) {
	atributo = malloc(sizeof(dato));
	*atributo = dato;
	siguiente = sig;
	anterior = 0;
}

/**
 *	@brief Constructor del nodo
 *	@param dato Dato a almacenar en nodo
 *	@param sig Nodo siguiente
 *	@param ant Nodo anterior
 */
template<class T> Nodo<T>::Nodo(T* dato, Nodo* sig, Nodo* ant) {
	atributo = malloc(sizeof(dato));
	*atributo = dato;
	siguiente = sig;
	anterior = ant;
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
template<class T> Nodo<T>::~Nodo() {
	free(atributo);
	free(siguiente);
	free(anterior);
}

/**
 * 	@brief Obtiene el nodo siguiente
 */
template<class T> void Nodo<T>::setSiguiente(Nodo<T>* sig) {
	siguiente = (Nodo<T>*)malloc(sizeof(sig));
	*siguiente = *sig;
}

/**
 * 	@brief Obtiene el nodo anterior
 */
template<class T> void Nodo<T>::setAnterior(Nodo<T>* ant) {
	anterior = (Nodo<T>*)malloc(sizeof(ant));
	*anterior = *ant;
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

#endif /* NODO_H_ */
