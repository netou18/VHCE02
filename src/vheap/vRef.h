#ifndef SRC_VHEAP_VREF_H_
#define SRC_VHEAP_VREF_H_

class vHeap;	//Instancias a utilizar
class vObject;	//**

/**
 * 	@class vRef
 * 	@brief Clase vRef
 */
class vRef {
private:
	int ID;								//Atributo identificador
	vHeap* heap;						//Instancia del vHeap
public:
	vRef();								//Constructor
	vRef(int id);						//Constructor
	~vRef();							//Destructor
	int getID();						//Obtener identifiador
	vObject* operator*();				//De-referenciar de memoria
	void operator=(vRef ref);			//Igualar vRef
	void operator=(vObject objeto);		//Igualar vObject
	bool operator==(vRef ref);			//Compara 2 vRef si con iguales
	void operator++();					//Operador, suma 1 al identificador
	void operator--();					//Operador, resta 1 al identificador
};

#endif /* SRC_VHEAP_VREF_H_ */
