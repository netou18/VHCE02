#ifndef SRC_XML_READER_H_
#define SRC_XML_READER_H_
#include <string>
using namespace std;

/**
 * 	@class Reader
 * 	@brief Clase lectora del archivo XML
 * 	Guarda datos en atributos que luego pueden ser llamados.
 */
class Reader {
private:
	Reader();					//Constructor
	static Reader* instancia;	//Instancia singleton
	bool activo;				//Atributo
	string path;				//Atributo
	int size;					//Atributo
	float overweight;			//Atributo

public:
	~Reader();					//Destructor
	bool vdebug();				//Obtener atributo activo
	int getSize();				//Obtener atributo size
	float getOW();				//Obtener atributo overweight
	string getPath();			//Obtener atributo path
	static Reader* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new Reader();			//
		return instancia;						//
	}
};

#endif /* SRC_XML_READER_H_ */
