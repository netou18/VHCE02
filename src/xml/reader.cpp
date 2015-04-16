#include "reader.h"
#include <stdlib.h>
#include <iostream>
#include "../libs/pugixml.hpp"
using namespace std;
using namespace pugi;

Reader* Reader::instancia = 0;

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

bool Reader::vdebug() {
	return activo;
}

int Reader::getSize() {
	return size;
}

float Reader::getOW() {
	return overweight;
}

string Reader::getPath() {
	return path;
}

Reader::~Reader() {
}

