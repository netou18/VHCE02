#ifndef SRC_VHEAP_METADATA_H_
#define SRC_VHEAP_METADATA_H_

using namespace std;

/**
 * 	@class Metadata
 * 	@brief Contiene todos los datos necesarios para ubicar en vHeap los elementos
 */
class Metadata {
private:
	int ID;				//Identificador
	void* posicion;			//Posicion del dato
	char tipo;			//Tipo de dato
	int tamano;			//Tamano del dato
	bool bandera;			//Bandera de uso
	int contador;			//Contador de referencia
public:
	Metadata(int id, void* pos, char t, int tam);		//Constructor
	~Metadata();										//Destructor
	int getID();										//Obtener identificador
	void* getPos();										//Obtener posicion
	char getTipo();									//Obtener tipo
	int getTamano();									//Obtener tamano
	void updatePos(void* pos);				//Actualiza la posicion en memoria
	void updateID(int id);					//Actualiza identificador
	void setUso(bool b);					//Actualiza bandera de uso
	bool getUso();							//Obtiene bandera de uso
	int getContador();						//Contador de referencias
	void aumentaContador();					//Aumenta contador de referencias
	void disminuyeContador();				//Disminuye contador de referencias
};

#endif /* SRC_VHEAP_METADATA_H_ */
