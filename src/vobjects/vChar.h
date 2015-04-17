#ifndef SRC_VOBJECTS_VCHAR_H_
#define SRC_VOBJECTS_VCHAR_H_
#include "vObject.h"
#include "../vheap/vHeap.h"

class vChar: public vObject {
private:
	char* pos;
	vRef ref;
	vHeap* heap;
public:
	vChar();
	vChar(char c);
	~vChar();
	int getTamano();
	void operator=(char c);
	vRef operator&();
	char getData();
};

#endif /* SRC_VOBJECTS_VCHAR_H_ */
