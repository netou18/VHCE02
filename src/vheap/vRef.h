#ifndef SRC_VHEAP_VREF_H_
#define SRC_VHEAP_VREF_H_
#include "../vobjects/vObject.h"

class vHeap;

class vRef {
private:
	int ID;
	vHeap* heap;
public:
	vRef();
	vRef(int id);
	~vRef();
	int getID();
	vObject* operator*();
	void operator=(vRef ref);
	void operator=(vObject objeto);
	bool operator==(vRef ref);
	void operator++();
	void operator--();
};

#endif /* SRC_VHEAP_VREF_H_ */
