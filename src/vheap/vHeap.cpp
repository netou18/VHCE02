#include "../vheap/vHeap.h"

#include "../res/vDebug.h"
#include "../res/lista.h"
#include <stdlib.h>
#include <cstring>

#include "../vheap/metadata.h"
using namespace std;

/**
 * 	@brief Instancia unica del vHeap
 */
vHeap* vHeap::instancia = 0;
vDebug* deb = vDebug::getInstance();

/**
 * 	@brief Constructor
 * 	@param size Tamano del vHeap
 * 	@param overweight Sobrecarga del tamano del vHeap
 */
vHeap::vHeap(int size, float overweight) {
	deb->print(true, "*Creacion de vHeap...");
	contador = (int*) malloc(sizeof(int));
	*contador = 0;
	memoria = malloc(size * 1000000);
	desplazamiento = memoria;
	metadata = (Lista<Metadata>*) malloc(sizeof(Lista<Metadata> ));
	new (metadata) Lista<Metadata>();
	deb->print(false, "vHeap creado.*");
}

/**
 * 	@brief Busca un elemento en el metadata
 */
int vHeap::busquedaDato(int id) {
	deb->print(true, "Buscando dato en metadata...");
	Nodo<Metadata>* actual = metadata->getPrimer();
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (((int) aux->getID()) == id) {
			deb->print(false, "Dato encontrado.");
			return actual->getIndice();

		} else
			actual = actual->getSiguiente();
	}
	deb->print(false, "Dato NO encontrado.");
	return -1;
}

Metadata* vHeap::getMetadata(vRef ref) {
	int indice = busquedaDato(ref.getID());
	if (indice != -1)
		return metadata->getElemento(indice)->getDato();
	else
		return 0;
}

/**
 * 	@brief Virtualizacion del malloc
 * 	@param size Tamano a reservar
 * 	@param tipo Tipo de dato a almacenar
 */
vRef vHeap::vMalloc(int size, char tipo) {
	deb->print(true, "vMalloc...");
	*contador = *contador + 1;
	Metadata* meta = new Metadata(*contador, desplazamiento, tipo, size);

	metadata->insertarFinal(*meta);
	memset(desplazamiento, 0, size);

	desplazamiento = desplazamiento + size;
	deb->print(false, "Espacio creado satisfactoriamente.");
	return vRef(*contador);
}

void vHeap::vFree(vRef ref) {
	int indice = busquedaDato(ref.getID());
	metadata->borrarElemento(indice);
	deb->print(true, "Espacio de memoria liberado");
}

/**
 * 	@brief Destructor
 */
vHeap::~vHeap() {
	free(contador);
	free(memoria);
	free(desplazamiento);
	free(metadata);
}

