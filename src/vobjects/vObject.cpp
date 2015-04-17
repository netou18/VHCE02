#include "../vobjects/vObject.h"

vObject::vObject() {
	tamano = 0;
}

vObject::~vObject() {
}

int vObject::getTamano(){
	return tamano;
}
