#ifndef SRC_VOBJECTS_VCHAR_H_
#define SRC_VOBJECTS_VCHAR_H_
#include "../vheap/vHeap.h"
#include "../vheap/vRef.h"

class vObject {
protected:
	int tamano;
	vRef ref;
};

class vChar: public vObject {
private:
	char* pos;
	vHeap* heap;
public:
	vChar();
	vChar(char c);
	~vChar();
	int getTamano();
	void operator=(char c);
	vRef operator&();
	char getData();
	void updatevRef(vRef r);
};

#endif /* SRC_VOBJECTS_VCHAR_H_ */
