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
//Metadata::~Metadata() {
//	free(ID);
//	//free(tipo);
//	free(posicion);
//	free(tamano);
//}
/**
 * 	@brief Obtener identificador
 */
int Metadata::getID() {
	return ID;
}

/**
 * 	@brief Obtener posicion
 */
void* Metadata::getPos() {
	return posicion;
}

/**
 * 	@brief Obtener tipo
 */
char Metadata::getTipo() {
	return tipo;
}

/**
 * 	@brief Obtener tamano
 */
int Metadata::getTamano() {
	return tamano;
}

void Metadata::setUso(bool b) {
	bandera = b;
}

bool Metadata::getUso(){
	return bandera;
}

int Metadata::getContador(){
	return contador;
}

void Metadata::aumentaContador(){
	contador+=1;
}

void Metadata::disminuyeContador(){
	contador-=1;
}

/**
 * 	@brief Actualizar posicion
 * 	@param pos Puntero de posicion
 */
void Metadata::updatePos(void* pos) {
	posicion = pos;
}

void Metadata::updateID(int id) {
	ID = id;
}
