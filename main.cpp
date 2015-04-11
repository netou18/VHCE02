#include <iostream>
#include <string>
#include "src/vHeap/vHeap.h"
#include "src/vHeap/vRef.h"
using namespace std;

struct datosvMalloc {
	int ID;				//Identificador
	void* posicion;			//Posicion del dato
	string tipo;			//Tipo de dato
	int tamano;			//Tamano del dato
	bool bandera;			//Bandera de uso
	int contador;			//Contador de referencia
};

int main() {
	string tipo = "int";

//	datosvMalloc datos;
//	datos.ID = 1;
//	datos.tipo = tipo;
//	datos.tamano = 10;
//	datos.posicion = 0;
//	datos.contador = 1;
//	datos.bandera = false;
//
//	datosvMalloc sec = datos;
//	cout << datos.ID << endl;
//	cout << sec.ID << endl;

	vHeap* heap = vHeap::getInstance();


	vRef ref1 = heap->vMalloc(10, tipo);

	heap->~vHeap();
	free(heap);
	return 0;
}
