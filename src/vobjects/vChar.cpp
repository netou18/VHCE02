#include "vChar.h"
#include "../vheap/vHeap.h"

vChar::vChar() {
	heap = vHeap::getInstance();
	tamano = 1;
	ref = heap->vMalloc(1, 'a');
	pos = (char*) (heap->getMetadata(ref))->getPos();
}
vChar::vChar(char c) {
	heap = vHeap::getInstance();
	tamano = 1;
	ref = heap->vMalloc(1, 'a');
	pos = (char*) (heap->getMetadata(ref))->getPos();
	*pos = c;
}

vChar::~vChar() {
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

