#include <iostream>
#include <pthread.h>
#include "src/res/vDebug.h"
#include "src/xml/reader.h"
#include "src/vheap/metadata.h"
#include "src/vheap/vHeap.h"
#include "src/vheap/vRef.h"
using namespace std;

void* foo(void* var) {
	cout << "Soy el hilo: " << *((int*) var) << endl;
	return 0;
}

int main() {

	cout << "Programa " << endl;

	pthread_t hilo;
	int num = 2;
	cout << "Creando pthread..." << endl;
	pthread_create(&hilo, 0, foo, &num);

	pthread_exit(0);

	cout << "Terminado." << endl;

//	cout << "Inicio programa..." << endl;
//	Reader* read = Reader::getInstance();
//	vDebug* deb = vDebug::getInstance();
//	deb->print(false, "Inicio programa...");
//	deb->print(false, "**************************");
//	vHeap* heap = vHeap::getInstance();
//
//	char tipo = 'a';
//
//	vRef ref1 = heap->vMalloc(10, tipo);
//	vRef ref2 = heap->vMalloc(100, tipo);
//	vRef ref3 = heap->vMalloc(500, tipo);
//
//	Metadata* meta = heap->getMetadata(ref1);
//	Metadata* meta1 = heap->getMetadata(ref2);
//	Metadata* meta2 = heap->getMetadata(ref3);
//
//	heap->vFree(ref2);
//
//	meta = heap->getMetadata(ref1);
//	meta1 = heap->getMetadata(ref2);
//	meta2 = heap->getMetadata(ref3);
//
//	deb->print(false, "**************************");
//	deb->print(false, "Termina.");
//	cout << "Termina." << endl;
	return 0;
}
