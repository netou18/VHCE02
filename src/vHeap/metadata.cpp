#include "metadata.h"
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
Metadata::Metadata(int id, void* pos, string t, int tam) {
	ID = (int*) malloc(sizeof(int));
	tipo = (string*) malloc(20);
	tamano = (int*) malloc(sizeof(int));
	bandera = (bool*)malloc(sizeof(bool));
	contador = (int*)malloc(sizeof(int));

	*ID = id;
	posicion = pos;
	*tipo = t;
	*tamano = tam;
	*bandera = false;
	*contador = 1;
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
	return *ID;
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
string Metadata::getTipo() {
	return *tipo;
}

/**
 * 	@brief Obtener tamano
 */
int Metadata::getTamano() {
	return *tamano;
}

/**
 * 	@brief Actualizar posicion
 * 	@param pos Puntero de posicion
 */
void Metadata::updatePos(void* pos) {
	posicion = pos;
}
