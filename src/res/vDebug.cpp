#include "vDebug.h"
#include "../xml/reader.h"
using namespace std;

Reader* xml = Reader::getInstance();
vDebug* vDebug::instancia = 0;
ofstream fs(xml->getPath().c_str());

vDebug::vDebug() {
	activo = xml->vdebug();
}

vDebug::~vDebug() {
}

void vDebug::print(bool enter, string msg) {
	if (activo) {
		if (!enter)
			fs << msg << endl;
		else
			fs << "\n" + msg << endl;
	}
}

void vDebug::print(bool enter, string msg, int num) {
	if (activo) {
		if (!enter)
			fs << msg << endl;
		else
			fs << "\n" + msg << num << endl;
	}
}
