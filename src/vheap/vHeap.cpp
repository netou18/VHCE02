#include "../vheap/vHeap.h"
#include "../xml/reader.h"
#include "../res/vDebug.h"
#include "../res/lista.h"
#include <stdlib.h>
#include <cstring>
#include <pthread.h>
#include <time.h>
#include <chrono>
#include <sstream>
#include "../vheap/metadata.h"
using namespace std;

/**
 * 	@brief Instancia unica del vHeap
 */
vHeap* vHeap::instancia = 0;

/**
 * 	@brief Variable global para el mutex
 */
pthread_mutex_t mutex;

/**
 * 	@brief Constructor
 * 	@param size Tamano del vHeap
 * 	@param overweight Sobrecarga del tamano del vHeap
 */
vHeap::vHeap() {
	read = Reader::getInstance();
	deb = vDebug::getInstance();
	deb->print(true, "*Creacion de vHeap...");
	int size = read->getSize(); //float over = read->getOW();
	contador = (int*) malloc(sizeof(int));
	*contador = 0;
	//memoria = malloc(size * 1000000);
	memoria = malloc(40);
	desplazamiento = memoria;
	//posFinal = memoria + (size * 1000000);
	posFinal = memoria + (39);
	metadata = (Lista<Metadata>*) malloc(sizeof(Lista<Metadata> ));
	new (metadata) Lista<Metadata>();
	pthread_t collector, defragger, mem;
	pthread_create(&collector, 0, recolector, 0);
	pthread_create(&defragger, 0, desfragmentar, 0);
	pthread_create(&mem, 0, printMemoria, 0);
	deb->print(false, "vHeap creado.*");
}

/**
 * 	@brief Busca un elemento en el metadata
 * 	@return Indice posicion del dato en la lista metadata
 */
int vHeap::busquedaDato(int id) {
	//pthread_mutex_lock(&mutex);
	deb->print(true, "Buscando dato en metadata...");
	Nodo<Metadata>* actual = metadata->getPrimer();
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (((int) aux->getID()) == id) {
			deb->print(false, "Dato encontrado.");
			//pthread_mutex_unlock(&mutex);
			return actual->getIndice();

		} else
			actual = actual->getSiguiente();
	}
	deb->print(false, "Dato NO encontrado.");
	//pthread_mutex_unlock(&mutex);
	//pthread_exit(0);
	return -1;
}

/**
 * 	@brief Obtener datos de un metadata especifico
 * 	@return Objeto tipo Metadata con todos los datos
 */
Metadata* vHeap::getMetadata(vRef ref) {
	pthread_mutex_lock(&mutex);
	int indice = busquedaDato(ref.getID());
	if (indice != -1) {
		pthread_mutex_unlock(&mutex);
		//pthread_exit(0);
		return metadata->getElemento(indice)->getDato();
	} else {
		pthread_mutex_unlock(&mutex);
		//pthread_exit(0);
		return 0;
	}
}

/**
 * 	@brief Virtualizacion del malloc
 * 	@param size Tamano a reservar
 * 	@param tipo Tipo de dato a almacenar
 * 	@return vRef para localizarlo en memoria
 */
vRef vHeap::vMalloc(int size, char tipo) {
	pthread_mutex_lock(&mutex);
	deb->print(true, "vMalloc...");
	*contador = *contador + 1;
	Metadata* meta = new Metadata(*contador, desplazamiento, tipo, size);

	metadata->insertarFinal(*meta);
	memset(desplazamiento, '0', size);

	desplazamiento = desplazamiento + size;
	deb->print(false, "Espacio creado satisfactoriamente. ID(vRef): ", *contador);
	pthread_mutex_unlock(&mutex);
	//pthread_exit(0);
	return vRef(*contador);
}

/**
 * 	@brief Liberador de memoria virtualizado
 */
void vHeap::vFree(vRef ref) {
	pthread_mutex_lock(&mutex);

	int indice = busquedaDato(ref.getID());
	metadata->borrarElemento(indice);
	deb->print(true, "Espacio de memoria liberado");
	pthread_mutex_unlock(&mutex);
}

/**
 * 	@brief Liberador de memoria virtualizado sobrecargado
 */
void vHeap::vFree(int ind) {
	pthread_mutex_lock(&mutex);

	metadata->borrarElemento(ind);
	deb->print(true, "Espacio de memoria liberado");
	pthread_mutex_unlock(&mutex);
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

/**
 * 	@brief Inicia hilo para el vGarbageCollector
 */
void* vHeap::recolector(void* var) {
	vDebug* deb = vDebug::getInstance();
	while (true) {
		struct timespec timer, timer2;
		timer.tv_sec = 20;
		timer.tv_nsec = 0;

		nanosleep(&timer, &timer2);

		auto t1 = chrono::high_resolution_clock::now();
		runGarbage();
		auto t2 = chrono::high_resolution_clock::now();
		auto tFinal = t2 - t1;
		stringstream strnum;
		string num;
		strnum << tFinal.count();
		strnum >> num;
		deb->print(true, "El tiempo que tarda en limpiar memoria es: " + num);

	}
	return 0;
}

/**
 * 	@brief Funcion que recolecta y elimina datos innecesarios de la memoria
 */
void vHeap::runGarbage() {
	pthread_mutex_lock(&mutex);
	vHeap* heap = vHeap::getInstance();
	Nodo<Metadata>* actual = heap->metadata->getPrimer();
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (aux->getUso() || (aux->getContador() > 0)) {
			actual = actual->getSiguiente();
		} else {
			heap->vFree(actual->getIndice());
		}
	}
	cout << "Recolector finalizado." << endl;
	pthread_mutex_unlock(&mutex);
}

/**
 * 	@brief Inicia el hilo para el desfragmentador de memoria vHeap
 */
void* vHeap::desfragmentar(void* var) {
	vDebug* deb = vDebug::getInstance();
	while (true) {
		struct timespec timer, timer2;
		timer.tv_sec = 10;
		timer.tv_nsec = 0;

		nanosleep(&timer, &timer2);
		auto t1 = chrono::high_resolution_clock::now();
		runDefrag();
		auto t2 = chrono::high_resolution_clock::now();
		auto tFinal = t2 - t1;
		stringstream strnum;
		string num;
		strnum << tFinal.count();
		strnum >> num;
		deb->print(true, "El tiempo que tarda desfragmentar es: " + num);
	}
	return 0;
}

/**
 * 	@brief Compara posicion en memoria y examina si existe referencia en el metadata
 * 	@return true o false
 */
bool buscar(void* posicion, Nodo<Metadata>* actual) {
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (posicion >= aux->getPos() && posicion <= (aux->getPos() + (aux->getTamano() - 1)))
			return true;
		else
			actual = actual->getSiguiente();
	}
	return false;
}

/**
 * 	@brief Mueve archivos en memoria de ser necesario para eliminar los "huecos" vacios
 */
void mover(void* posicion, int size, Nodo<Metadata>* actual) {
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (aux->getPos() > posicion) {
			if (posicion + size == aux->getPos()) {
				memmove(posicion, aux->getPos(), aux->getTamano());
				aux->updatePos(posicion);
			}
			else if (aux->getTamano() < size) {
				memmove(posicion, aux->getPos(), size);
				aux->updatePos(posicion);
			}
			else
				actual = actual->getSiguiente();
		}
		else {
			actual = actual->getSiguiente();
		}
	}
}

/**
 * 	@brief Desfragmentador de memoria
 */
void vHeap::runDefrag() {
	pthread_mutex_lock(&mutex);
	vHeap* heap = vHeap::getInstance();
	void* posicion = heap->memoria;
	void* temporal = 0;
	void* posFinal = heap->posFinal;
	int tamanoHueco = 0;
	Nodo<Metadata>* actual = heap->metadata->getPrimer();
	while (posicion <= posFinal) {
		if (buscar(posicion, actual)) {
			if (tamanoHueco > 0) {
				mover(temporal, tamanoHueco, actual);
				temporal = 0;
				tamanoHueco = 0;
			}
			posicion += 1;
		}
		else {
			temporal = posicion - tamanoHueco;
			tamanoHueco += 1;
			posicion += 1;
		}
	}

	cout << "Memoria desfragmentada" << endl;
	pthread_mutex_unlock(&mutex);
}

/**
 * 	@brief Inicia el hilo para imprimir uso de memoria en consola
 */
void* vHeap::printMemoria(void* var) {
	while (true) {
		struct timespec timer, timer2;
		timer.tv_sec = 5;
		timer.tv_nsec = 0;

		nanosleep(&timer, &timer2);

		printMem();
	}
	return 0;
}

/**
 * 	@brief Imprime uso de memoria en consola
 */
void vHeap::printMem() {
	pthread_mutex_lock(&mutex);
	vHeap* heap = vHeap::getInstance();
	void* posicion = heap->memoria;
	void* posFinal = heap->posFinal;
	string mem;
	Nodo<Metadata>* actual = heap->metadata->getPrimer();
	while (posicion <= posFinal) {
		if (buscar(posicion, actual)) {
			mem = mem + "/";
			posicion += 1;
		}
		else {
			mem = mem + "*";
			posicion += 1;
		}
	}
	cout << mem << endl;
	pthread_mutex_unlock(&mutex);
}

