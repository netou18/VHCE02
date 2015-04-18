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

class Defrag;
class vGarbageCollector;

class vHeap {
protected:
	int* contador;								//Contador de identificadores
	void* memoria;								//Puntero a vHeap
	void* desplazamiento;						//Posicion del puntero
	void* posFinal;
	Lista<Metadata>* metadata;					//Metadata
private:
	vHeap();									//Constructor principal
	static vHeap* instancia;					//Instancia unica del vHeap
	Reader* read;
	vDebug* deb;
	static void* recolector(void* var);
	static void runGarbage();
	static void* desfragmentar(void* var);
	static void runDefrag();
	public:
	~vHeap();									//Destructor
	vRef vMalloc(int size, char type);			//Malloc virtualizado
	void vFree(vRef ref);					//Liberador de memoria virtualizado
	void vFree(int ind);
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
