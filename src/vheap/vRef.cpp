#include "vRef.h"
#include "vHeap.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

vRef::vRef(){
	ID=-1;
	heap = vHeap::getInstance();
}

vRef::vRef(int id) {
	ID = id;
	heap = vHeap::getInstance();
}

vRef::~vRef() {
}

int vRef::getID() {
	return ID;
}

vObject* vRef::operator *() {
	Metadata* datos = heap->getMetadata(*this);
	return ((vObject*) datos->getPos());
}

void vRef::operator =(vRef ref) {
	ID = ref.getID();
}

void vRef::operator =(vObject objeto) {
	Metadata* datos = heap->getMetadata(*this);
	if(datos->getTamano() >= objeto.getTamano()){
		*(vObject*)datos->getPos() = objeto;
	}

}

