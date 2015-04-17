#include "../vobjects/vObject.h"
#include "../vheap/vRef.h"
vObject::vObject() {
	tamano = 100;
	ref = 100;
}

vObject::~vObject() {
}

int vObject::getTamano(){
	return tamano;
}

vRef vObject::operator &(){
	return ref;
}

void vObject::updatevRef(vRef r){
	ref = r;
}
