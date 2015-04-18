#include "vDebug.h"
#include "../xml/reader.h"
using namespace std;

/**
 * 	Instancias necesarias
 */
Reader* xml = Reader::getInstance();	//Intancia unica del lector de XML
vDebug* vDebug::instancia = 0;			//Instancia unica singleton
ofstream fs(xml->getPath().c_str());	//Variable global para escribir en archivo

/**
 * 	@brief Constructor
 */
vDebug::vDebug() {
	activo = xml->vdebug();
}

/**
 * @brief Destructor
 */
vDebug::~vDebug() {
}

/**
 * 	@brief Imprime en archivo una linea de texto
 */
void vDebug::print(bool enter, string msg) {
	if (activo) {
		if (!enter)
			fs << msg << endl;
		else
			fs << "\n" + msg << endl;
	}
}

/**
 * 	@brief Imprime en archivo una linea de texto
 */
void vDebug::print(bool enter, string msg, int num) {
	if (activo) {
		if (!enter)
			fs << msg << num << endl;
		else
			fs << "\n" + msg << num << endl;
	}
}
