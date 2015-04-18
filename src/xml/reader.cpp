#include "reader.h"
#include <stdlib.h>
#include <iostream>
#include "../libs/pugixml.hpp"
using namespace std;
using namespace pugi;
/**
 * @brief Instancia singleton
 */
Reader* Reader::instancia = 0;

/**
 * 	@brief Constructor.
 * 	Carga y parsea el XML. Obtiene datos y almacena en atributos.
 */
Reader::Reader() {
	xml_document doc;
	xml_parse_result result = doc.load_file("vHeap.xml");
	cout << "Result: " << result.description() << endl;

	xml_node raiz = doc.child("VHCE02");

	activo = raiz.child("vdebug").attribute("activo").as_bool();
	size = raiz.child("vHeap").attribute("size").as_int();
	overweight = raiz.child("vHeap").attribute("overweight").as_float();

	//path = (string*)malloc(sizeof(raiz.child("vdebug").attribute("vdebug-file-path").value()));
	path = raiz.child("vdebug").attribute("vdebug-file-path").value();

}

/**
 * 	@brief Obtener atributo activo
 * 	@return activo
 */
bool Reader::vdebug() {
	return activo;
}

/**
 * 	@brief Obtener atributo size
 * 	@return size
 */
int Reader::getSize() {
	return size;
}

/**
 * 	@brief Obtener atributo overweight
 * 	@return overweight
 */
float Reader::getOW() {
	return overweight;
}

/**
 * 	@brief Obtener atributo path
 * 	@return path
 */
string Reader::getPath() {
	return path;
}

/**
 * @brief Destructor
 */
Reader::~Reader() {
}

