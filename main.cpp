#include <iostream>
#include <string>
#include "src/vHeap/vHeap.h"
#include "src/vHeap/vRef.h"
#include "src/vHeap/metadata.h"
using namespace std;

int main() {

	vHeap* heap = vHeap::getInstance();

	char tipo = 'a';

	vRef ref1 = heap->vMalloc(10, tipo);
	vRef ref2 = heap->vMalloc(100, tipo);
	vRef ref3 = heap->vMalloc(500, tipo);

	Metadata* meta = heap->busquedaDato(1);
	Metadata* meta1 = heap->busquedaDato(2);
	Metadata* meta2 = heap->busquedaDato(3);

	cout << "*****************************" << endl;
	cout << "ID: " << meta->getID() << endl;
	cout << "Posicion: " << meta->getPos() << endl;
	cout << "Tamano: " << meta->getTamano() << endl;
	cout << "TIpo: " << meta->getTipo() << endl;
	cout << "*****************************" << endl;
	cout << "ID: " << meta1->getID() << endl;
	cout << "Posicion: " << meta1->getPos() << endl;
	cout << "Tamano: " << meta1->getTamano() << endl;
	cout << "TIpo: " << meta1->getTipo() << endl;
	cout << "*****************************" << endl;
	cout << "ID: " << meta2->getID() << endl;
	cout << "Posicion: " << meta2->getPos() << endl;
	cout << "Tamano: " << meta2->getTamano() << endl;
	cout << "TIpo: " << meta2->getTipo() << endl;

	heap->~vHeap();
	return 0;
}
