#include "vRef.h"
#include "vHeap.h"
#include "../vobjects/vObject.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;

vRef::vRef() {
	ID = -1;
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
	Metadata* thisDatos = heap->getMetadata(*this);
	Metadata* objDatos = heap->getMetadata(&objeto);
	if (thisDatos->getTamano() >= objDatos->getTamano()) {
		memcpy(thisDatos->getPos(), objDatos->getPos(), objDatos->getTamano());
		thisDatos->setUso(true);
		thisDatos->aumentaContador();
	}
}

bool vRef::operator ==(vRef ref) {
	if (ID == ref.getID())
		return true;
	else
		return false;
}

void vRef::operator ++() {
	ID = ID + 1;
}

void vRef::operator --() {
	ID = ID - 1;
}

