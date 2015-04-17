#ifndef SRC_VOBJECTS_VOBJECT_H_
#define SRC_VOBJECTS_VOBJECT_H_
#include "../vheap/vRef.h"

class vObject {
protected:
	int tamano;
	vRef ref;
public:
	vObject();
	~vObject();
	int getTamano();
	vRef operator&();
	void updatevRef(vRef r);
};

#endif /* SRC_VOBJECTS_VOBJECT_H_ */
