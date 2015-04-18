#include "vRef.h"
#include "vHeap.h"
#include "../vobjects/vObject.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;

/**
 * 	@brief Constructor
 */
vRef::vRef() {
	ID = -1;
	heap = vHeap::getInstance();
}

/**
 * 	@brief Constructor sobrecargado
 */
vRef::vRef(int id) {
	ID = id;
	heap = vHeap::getInstance();
}

/**
 * 	@brief Destructor
 */
vRef::~vRef() {
}

/**
 * 	@brief Obtener identificador
 * 	@return Identificador
 */
int vRef::getID() {
	return ID;
}

/**
 * 	@brief De-referenciar dato de memoria
 * 	@return vObject almacenado en memoria
 */
vObject* vRef::operator *() {
	Metadata* datos = heap->getMetadata(*this);
	return ((vObject*) datos->getPos());
}

/**
 * 	@brief Iguala 2 vRef y copia identificadores
 */
void vRef::operator =(vRef ref) {
	ID = ref.getID();
}

/**
 * 	@brief Iguala vRef con vObject. Almacena el vObject igualado en espacio vRef reservado
 */
void vRef::operator =(vObject objeto) {
	Metadata* thisDatos = heap->getMetadata(*this);
	Metadata* objDatos = heap->getMetadata(&objeto);
	if (thisDatos->getTamano() >= objDatos->getTamano()) {
		memcpy(thisDatos->getPos(), objDatos->getPos(), objDatos->getTamano());
		thisDatos->setUso(true);
		thisDatos->aumentaContador();
	}
}

/**
 * 	@brief Compara si 2 vRef son iguales
 * 	@return true o false
 */
bool vRef::operator ==(vRef ref) {
	if (ID == ref.getID())
		return true;
	else
		return false;
}

/**
 * @brief Operador suma, suma 1 al identificador
 */
void vRef::operator ++() {
	ID = ID + 1;
}

/**
 * @brief Operador resta, resta 1 al identificador
 */
void vRef::operator --() {
	ID = ID - 1;
}

