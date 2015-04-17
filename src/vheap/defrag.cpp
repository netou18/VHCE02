#include "defrag.h"
#include "vHeap.h"
#include "../res/nodo.h"
#include "../res/lista.h"
#include <pthread.h>
#include <cstring>
#include <time.h>

Defrag::Defrag() {
	pthread_t defrag;
	pthread_create(&defrag, 0, run, 0);
}

Defrag::~Defrag() {
}

bool buscar(void* posicion, Nodo<Metadata>* actual) {
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (posicion >= aux->getPos() || posicion <= (aux->getPos() + aux->getTamano()))
			return true;
		else
			actual = actual->getSiguiente();
	}
	return false;
}

void mover(void* posicion, int size, Nodo<Metadata>* actual) {
	while (actual != 0) {
		Metadata* aux = actual->getDato();
		if (aux->getTamano() < size) {
			memmove(posicion, aux->getPos(), size);
		}
		else
			actual = actual->getSiguiente();
	}
}

void* Defrag::run(void* var) {
	vHeap* heap = vHeap::getInstance();
	while (true) {
		wait();
		void* posicion = heap->memoria;
		void* temporal = 0;
		void* posFinal = heap->posFinal;
		int tamanoHueco = 0;
		Lista<Metadata>* metadata = heap->getDatos();
		Nodo<Metadata>* actual = metadata->getPrimer();
		while (posicion <= posFinal) {
			if (buscar(posicion, actual)) {
				if (tamanoHueco > 0) {
					mover(temporal, tamanoHueco, actual);
					temporal = 0; tamanoHueco=0;
				}
				posicion += 1;
			}
			else {
				temporal = posicion;
				tamanoHueco += 1;
				posicion += 1;
			}
		}
	}
	return 0;
}

void Defrag::wait() {
	struct timespec timer, timer2;
	timer.tv_sec = 60*5;
	timer.tv_nsec = 0;

	nanosleep(&timer, &timer2);
}

