#include "vHeap.h"
#include "metadata.h"
#include <iostream>
#include "../estructuras/lista.h"
#include <stdlib.h>
#include <cstring>
using namespace std;

/**
 * 	@brief Instancia unica del vHeap
 */
vHeap* vHeap::instancia = 0;

/**
 * 	@brief Constructor
 * 	@param size Tamano del vHeap
 * 	@param overweight Sobrecarga del tamano del vHeap
 */
vHeap::vHeap(int size, float overweight) {
	cout << "**Creando heap virtual..." << endl;
	contador = (int*) malloc(sizeof(int));
	*contador = 0;
	memoria = malloc(size * 1000000);
	desplazamiento = memoria;
	metadata = (Lista<Metadata>*) malloc(sizeof(Lista<Metadata> ));
	new (metadata) Lista<Metadata>();
	cout << "Heap creado.**" << endl;
}

/**
 * 	@brief Busca un elemento en el metadata
 */
Metadata* vHeap::busquedaDato(int id) {
	cout << "Buscando elemento..." << endl;
	Nodo<Metadata>* actual = metadata->getPrimer();
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (((int) aux->getID()) == id){
			cout << "Elemento encontrado." << endl;
			return aux;
		}
		else
			actual = actual->getSiguiente();
	}
	cout << "Elemento no encontrado" << endl;
	return 0;
}

/**
 * 	@brief Virtualizacion del malloc
 * 	@param size Tamano a reservar
 * 	@param tipo Tipo de dato a almacenar
 */
vRef vHeap::vMalloc(int size, char tipo) {
	cout << "***************************" << endl;
	cout << "vMalloc en vHeap..." << endl;
	*contador = *contador + 1;
	Metadata* meta = new Metadata(*contador, desplazamiento, tipo, size);
	cout << "Datos asignados.." << endl;

	metadata->insertarFinal(*meta);
	memset(desplazamiento, 0, size);

	desplazamiento = desplazamiento + size;
	cout << "Espacio creado, retorna puntero. ID: " << *contador << endl;
	cout << "***************************" << endl;
	return vRef(*contador);
}

void vHeap::vFree(vRef ref) {
	Metadata* meta = busquedaDato(ref.getID());

}

/**
 * 	@brief Destructor
 */
vHeap::~vHeap() {
	free(contador);
	free(memoria);
	free(desplazamiento);
	free(metadata);
	cout << "Memoria liberada." << endl;
}

