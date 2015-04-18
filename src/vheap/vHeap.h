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

/**
 * 	@class vHeap
 * 	@brief Crea un heap virtual donde los punteros de manejan de manera distinta
 */
class vHeap {
protected:
	int* contador;								//Contador de identificadores
	void* memoria;								//Puntero a vHeap
	void* desplazamiento;						//Posicion inicial del vHeap
	void* posFinal;								//Posicion final del vHeap
	Lista<Metadata>* metadata;					//Metadata
private:
	vHeap();									//Constructor principal
	static vHeap* instancia;					//Instancia unica del vHeap
	Reader* read;								//Encargada de aportar datos del XML
	vDebug* deb;								//Encargada de imprimir datos en archivo
	static void* recolector(void* var);			//Inicia el hilo del vGarbageCollector
	static void runGarbage();					//
	static void* desfragmentar(void* var);		//Inicia el hilo del desfragmentador de memoria
	static void runDefrag();					//
	static void* printMemoria(void* var);		//Inicia el hilo para imprimir la memoria en consola
	static void printMem();						//
public:
	~vHeap();									//Destructor
	vRef vMalloc(int size, char type);			//Malloc virtualizado
	void vFree(vRef ref);					//Liberador de memoria virtualizado
	void vFree(int ind);						//Liberador de memoria virtualizado
	int busquedaDato(int id);					//Busca el indice del Metadata
	Metadata* getMetadata(vRef ref);			//Obtener el Metadata
	Lista<Metadata>* getDatos();
	static vHeap* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new vHeap();			//
		return instancia;						//
	}
};

#endif /* SRC_VHEAP_VHEAP_H_ */
