#include "vGarbageCollector.h"
#include "vHeap.h"
#include "../res/lista.h"
#include "../res/nodo.h"
#include <pthread.h>
#include <time.h>
using namespace std;

vGarbageCollector::vGarbageCollector() {
	pthread_t garbage;
	pthread_create(&garbage, 0, run, this);
}

vGarbageCollector::~vGarbageCollector() {
}

void* vGarbageCollector::run(void* var) {
	vHeap* heap = vHeap::getInstance();
	while (true) {
		try {
			wait();
			Lista<Metadata>* metadata = heap->getDatos();
			Nodo<Metadata>* actual = metadata->getPrimer();
			while (actual != 0) {
				Metadata* aux = actual->getDato();
				if (aux->getUso() || (aux->getContador() > 0)) {
					actual = actual->getSiguiente();
				} else {
					heap->vFree(actual->getIndice());
				}
			}
		} catch (int e) {
		}
	}
	return 0;
}

void vGarbageCollector::wait() {
	struct timespec timer, timer2;
	timer.tv_sec = 60*1;
	timer.tv_nsec = 0;

	nanosleep(&timer, &timer2);
}
