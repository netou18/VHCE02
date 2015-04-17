#ifndef SRC_VHEAP_METADATA_H_
#define SRC_VHEAP_METADATA_H_

using namespace std;

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
	int getID();										//Obtener identificador
	void* getPos();										//Obtener posicion
	char getTipo();									//Obtener tipo
	int getTamano();									//Obtener tamano
	void updatePos(void* pos);				//Actualiza la posicion en memoria
	void updateID(int id);
	void setUso(bool b);
	bool getUso();
	int getContador();
	void aumentaContador();
	void disminuyeContador();
};

#endif /* SRC_VHEAP_METADATA_H_ */
