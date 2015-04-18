#ifndef SRC_RES_VDEBUG_H_
#define SRC_RES_VDEBUG_H_
#include <string>
#include <fstream>
using namespace std;

/**
 * 	@class vDebug
 * 	@brief Encargado de impresion de lineas de texto en archivo
 */
class vDebug {
private:
	vDebug();									//Constructor
	static vDebug* instancia;					//Instancia unica
	bool activo;								//Bandera de actividad
public:
	~vDebug();									//Destructor
	void print(bool enter, string msg);			//Imprime en archivo
	void print(bool enter, string msg, int num);			//Imprime en archivo
	static vDebug* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new vDebug();			//
		return instancia;						//
	}
};

#endif /* SRC_RES_VDEBUG_H_ */
