#ifndef SRC_VHEAP_VHEAP_H_
#define SRC_VHEAP_VHEAP_H_

#include <string>
#include "../xml/reader.h"
#include "../res/lista.h"
#include "../vheap/metadata.h"
#include "../vheap/vRef.h"
#include "../xml/reader.h"
#include "../res/vDebug.h"
using namespace std;

class vHeap {
private:
	vHeap();									//Constructor principal
	static vHeap* instancia;					//Instancia unica del vHeap
	int* contador;								//Contador de identificadores
	void* memoria;								//Puntero a vHeap
	void* desplazamiento;						//Posicion del puntero
	Lista<Metadata>* metadata;					//Metadata
	Reader* read;
	vDebug* deb;
public:
	~vHeap();									//Destructor
	vRef vMalloc(int size, char type);			//Malloc virtualizado
	void vFree(vRef ref);					//Liberador de memoria virtualizado
	int busquedaDato(int id);					//Busca el indice del Metadata
	Metadata* getMetadata(vRef ref);			//Obtener el Metadata
	void aumentarContador(int id);				//Aumenta contador de referencia
	void disminuirContador(int id);			//Disminuye contador de referencia
	static vHeap* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new vHeap();			//
		return instancia;						//
	}
};

#endif /* SRC_VHEAP_VHEAP_H_ */
