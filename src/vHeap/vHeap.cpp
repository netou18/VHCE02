#include "vHeap.h"
#include "metadata.h"
#include <iostream>
#include "../estructuras/lista.h"
#include <stdlib.h>
#include <string>
using namespace std;

vHeap* vHeap::instancia = 0;

vHeap::vHeap(int size, float overweight) {
	cout << "**Creando heap virtual..." << endl;
	contador = (int*) malloc(sizeof(int));
	*contador = 0;
	memoria = malloc(size * 1000000);
	desplazamiento = memoria;
	metadata = (Lista<Metadata>*) malloc(sizeof(Lista<Metadata>));
	new (metadata) Lista<Metadata>();
	cout << "Heap creado.**" << endl;
}

void* vHeap::busquedaDato(int id) {
//	Nodo<datosvMalloc*>* actual = metadata->getPrimer();
//	datosvMalloc** aux = actual->getDato();
//	while (aux->ID != 0) {
//		if (aux->ID == id) {
//			return aux->posicion;
//		} else
//			actual = actual->getSiguiente();
//	}
	return 0;
}

vRef vHeap::vMalloc(int size, string type) {
	cout << "***************************" << endl;
	cout << "vMalloc en vHeap..." << endl;
	Metadata* meta = new Metadata(*contador, desplazamiento, type, size);
	cout << "Datos asignados.." << endl;

	metadata->insertarFinal(*meta);

	desplazamiento+=size;
	contador++;
	cout << "Espacio creado, retorna puntero" << endl;
	cout << "***************************" << endl;
	return vRef(*contador);
}

vHeap::~vHeap() {
	free(contador);
	free(memoria);
	free(desplazamiento);
	free(metadata);
	cout << "Memoria liberada." << endl;
}

