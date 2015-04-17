#include "../vheap/vHeap.h"
#include "../xml/reader.h"
#include "../res/vDebug.h"
#include "../res/lista.h"
#include <stdlib.h>
#include <cstring>
#include <pthread.h>
#include "../vheap/metadata.h"
using namespace std;

/**
 * 	@brief Instancia unica del vHeap
 */
vHeap* vHeap::instancia = 0;
pthread_mutex_t mutex;

/**
 * 	@brief Constructor
 * 	@param size Tamano del vHeap
 * 	@param overweight Sobrecarga del tamano del vHeap
 */
vHeap::vHeap() {
	//pthread_mutex_lock(&mutex);
	read = Reader::getInstance();
	deb = vDebug::getInstance();
	deb->print(true, "*Creacion de vHeap...");
	int size = read->getSize(); //float over = read->getOW();
	contador = (int*) malloc(sizeof(int));
	*contador = 0;
	memoria = malloc(size * 1000000);
	desplazamiento = memoria;
	metadata = (Lista<Metadata>*) malloc(sizeof(Lista<Metadata> ));
	new (metadata) Lista<Metadata>();
	deb->print(false, "vHeap creado.*");
	//pthread_mutex_unlock(&mutex);
	//pthread_exit(0);
}

/**
 * 	@brief Busca un elemento en el metadata
 */
int vHeap::busquedaDato(int id) {
	//pthread_mutex_lock(&mutex);
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
	//pthread_mutex_unlock(&mutex);
	//pthread_exit(0);
	return -1;
}

Metadata* vHeap::getMetadata(vRef ref) {
	//pthread_mutex_lock(&mutex);
	int indice = busquedaDato(ref.getID());
	if (indice != -1) {
		//pthread_mutex_unlock(&mutex);
		//pthread_exit(0);
		return metadata->getElemento(indice)->getDato();
	} else {
		//pthread_mutex_unlock(&mutex);
		//pthread_exit(0);
		return 0;
	}
}

/**
 * 	@brief Virtualizacion del malloc
 * 	@param size Tamano a reservar
 * 	@param tipo Tipo de dato a almacenar
 */
vRef vHeap::vMalloc(int size, char tipo) {
	//pthread_mutex_lock(&mutex);
	deb->print(true, "vMalloc...");
	*contador = *contador + 1;
	Metadata* meta = new Metadata(*contador, desplazamiento, tipo, size);

	metadata->insertarFinal(*meta);
	memset(desplazamiento, '0', size);

	desplazamiento = desplazamiento + size;
	deb->print(false, "Espacio creado satisfactoriamente. ID(vRef): ",
			*contador);
	//pthread_mutex_unlock(&mutex);
	//pthread_exit(0);
	return vRef(*contador);
}

void vHeap::vFree(vRef ref) {
	//pthread_mutex_lock(&mutex);

	int indice = busquedaDato(ref.getID());
	cout << "vFree: " << indice << endl;
	metadata->borrarElemento(indice);
	deb->print(true, "Espacio de memoria liberado");
	//pthread_mutex_unlock(&mutex);
}

void vHeap::vFree(int ind) {
	//pthread_mutex_lock(&mutex);

	metadata->borrarElemento(ind);
	deb->print(true, "Espacio de memoria liberado");
	//pthread_mutex_unlock(&mutex);
}

Lista<Metadata>* vHeap::getDatos() {
	return metadata;
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

