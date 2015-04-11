#ifndef SRC_VHEAP_VHEAP_H_
#define SRC_VHEAP_VHEAP_H_

#include "vRef.h"
#include "metadata.h"
#include "../estructuras/lista.h"
#include <string>
using namespace std;

class vHeap {
private:
	vHeap(int size, float overweight);			//Constructor principal
	static vHeap* instancia;					//Instancia unica del vHeap
	int* contador;								//Contador de identificadores
	void* memoria;								//Puntero a vHeap
	void* desplazamiento;						//Posicion del puntero
	Lista<Metadata>* metadata;					//Metadata

public:
	~vHeap();									//Destructor
	vRef vMalloc(int size, char type);			//Malloc virtualizado
	void vFree(vRef ref);						//Liberador de memoria virtualizado
	Metadata* busquedaDato(int id);					//Busca el valor de *vRef
	void aumentarContador(int id);				//Aumenta contador de referencia
	void disminuirContador(int id);			//Disminuye contador de referencia
	static vHeap* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new vHeap(10, 0.5);		//
		return instancia;						//
	}
};

#endif /* SRC_VHEAP_VHEAP_H_ */
