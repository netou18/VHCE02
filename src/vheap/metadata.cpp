#include "../vheap/metadata.h"

#include <string>
#include <stdlib.h>

using namespace std;

/**
 * 	@brief Constructor del Metadata
 * 	@param id Identificador del dato
 * 	@param pos Posicion en memoria
 * 	@param t Tipo del dato
 * 	@param tam Tamano del dato
 */
Metadata::Metadata(int id, void* pos, char t, int tam) {
	ID = id;
	posicion = pos;
	tipo = t;
	tamano = tam;
	bandera = false;
	contador = 1;
}

/**
 * 	@brief Destructor
 */
Metadata::~Metadata() {
}

/**
 * 	@brief Obtener identificador
 * 	@return Identificador
 */
int Metadata::getID() {
	return ID;
}

/**
 * 	@brief Obtener posicion
 * 	@return Posicion en memoria
 */
void* Metadata::getPos() {
	return posicion;
}

/**
 * 	@brief Obtener tipo
 * 	@return Tipo de dato
 */
char Metadata::getTipo() {
	return tipo;
}

/**
 * 	@brief Obtener tamano
 * 	@return Tamano
 */
int Metadata::getTamano() {
	return tamano;
}

/**
 * 	@brief Asignar bandera de uso
 */
void Metadata::setUso(bool b) {
	bandera = b;
}

/**
 * 	@brief Obtener bandera de uso
 * 	@return Bandera
 */
bool Metadata::getUso() {
	return bandera;
}

/**
 * 	@brief Obtener contador de referencias
 * 	@return Contador de referencias
 */
int Metadata::getContador() {
	return contador;
}

/**
 * 	@brief Aumenta el contador de referencias
 */
void Metadata::aumentaContador() {
	contador += 1;
}

/**
 * 	@brief Dismiuye el contador de referencias
 */

void Metadata::disminuyeContador() {
	contador -= 1;
}

/**
 * 	@brief Actualizar posicion
 * 	@param pos Puntero de posicion
 */
void Metadata::updatePos(void* pos) {
	posicion = pos;
}

/**
 * 	@brief Actualizar identificador
 */
void Metadata::updateID(int id) {
	ID = id;
}
