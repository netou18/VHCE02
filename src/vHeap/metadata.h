#ifndef SRC_VHEAP_METADATA_H_
#define SRC_VHEAP_METADATA_H_

#include <string>
using namespace std;

class Metadata {
private:
	int* ID;				//Identificador
	void* posicion;			//Posicion del dato
	string* tipo;			//Tipo de dato
	int* tamano;			//Tamano del dato
	bool* bandera;			//Bandera de uso
	int* contador;			//Contador de referencia
public:
	Metadata(int id, void* pos, string t, int tam);		//Constructor
	int getID();										//Obtener identificador
	void* getPos();										//Obtener posicion
	string getTipo();									//Obtener tipo
	int getTamano();									//Obtener tamano
	void updatePos(void* pos);				//Actualiza la posicion en memoria
};

#endif /* SRC_VHEAP_METADATA_H_ */
