#include <iostream>
#include <pthread.h>
#include <time.h>
#include "src/res/vDebug.h"
#include "src/xml/reader.h"
#include "src/vheap/metadata.h"
#include "src/vheap/vHeap.h"
#include "src/vheap/vRef.h"
#include "src/vobjects/vChar.h"
using namespace std;

int main() {

	cout << "Programa " << endl;

//	char* p = (char*) malloc(sizeof(char));
//	char c = 'a';
//	*p = c;
//	cout << p << ": " << *p << endl;
//
//	pthread_t hilo;
//	int num = 2;
//	cout << "Creando pthread..." << endl;
//	pthread_create(&hilo, 0, foo1, &num);
//	cout << "continue" << endl;
//	num = 3;
//	cout << "Creando pthread..." << endl;
//	pthread_create(&hilo, 0, foo, &num);
//
//	pthread_exit(0);

	cout << "Inicio programa..." << endl;
	Reader* read = Reader::getInstance();
	vDebug* deb = vDebug::getInstance();
	deb->print(false, "Inicio programa...");
	deb->print(false, "**************************");
	vHeap* heap = vHeap::getInstance();

	char tipo = 'a';

	vRef ref1 = heap->vMalloc(10, tipo);
	vRef ref2 = heap->vMalloc(6, tipo);
	vRef ref3 = heap->vMalloc(3, tipo);

	vChar car = 'a';
	cout << "ref1: " << ref1.getID() << endl;
	cout << "ref3: " << ref3.getID() << endl;
	cout << "ref2: " << ref2.getID() << endl;

	heap->vFree(ref2);
	ref1 = car;
	vObject* prueba = *ref1;
	Metadata* meta = heap->getMetadata(ref1);
	cout << "ref1: " << meta->getPos() << endl;
	cout << "prueba: " << prueba << endl;

	//Metadata* meta = heap->getMetadata(&car);
	//cout << endl;
	//cout << "ID: " << meta->getID() << endl;
	//cout << "Tamano: " << meta->getTamano() << endl;
	//cout << "Posicion: " << meta->getPos() << endl;
	//cout << endl;
	//Metadata* meta1 = heap->getMetadata(ref2);
	//Metadata* meta2 = heap->getMetadata(ref3);

	//heap->vFree(ref2);

	//meta = heap->getMetadata(ref1);
	//meta1 = heap->getMetadata(ref2);
	//meta2 = heap->getMetadata(ref3);
	//vChar obj;
	//obj = (char)((vChar*)(*ref1))->getData();
	//cout << "car: " << obj.getTamano() << endl;

	while (true) {
		struct timespec timer, timer2;
		timer.tv_sec = 5;
		timer.tv_nsec = 0;

		nanosleep(&timer, &timer2);

	}

	deb->print(false, "**************************");
	deb->print(false, "Termina.");
	cout << "Termina." << endl;
	return 0;
}
