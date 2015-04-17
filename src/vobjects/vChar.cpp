#include "vChar.h"
#include "../vheap/vHeap.h"

vChar::vChar() {
	heap = vHeap::getInstance();
	tamano = 8;
	ref = heap->vMalloc(8, 'a');
	pos = (char*) (heap->getMetadata(ref))->getPos();
}
vChar::vChar(char c) {
	heap = vHeap::getInstance();
	tamano = 8;
	ref = heap->vMalloc(8, 'a');
	pos = (char*) (heap->getMetadata(ref))->getPos();
	*pos = c;
}

vChar::~vChar() {
}

int vChar::getTamano(){
	return tamano;
}

void vChar::operator =(char c) {
	*pos = c;
}

vRef vChar::operator &() {
	return ref;
}

char vChar::getData(){
	return *pos;
}

void vChar::updatevRef(vRef r){
	ref = r;
}

