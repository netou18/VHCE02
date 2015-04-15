#ifndef SRC_XML_READER_H_
#define SRC_XML_READER_H_
#include <string>
using namespace std;

class Reader {
private:
	Reader();
	static Reader* instancia;
	bool activo;
	string path;
	int size;
	float overweight;

public:
	~Reader();
	bool vdebug();
	int getSize();
	float getOW();
	string getPath();
	static Reader* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new Reader();			//
		return instancia;						//
	}
};

#endif /* SRC_XML_READER_H_ */
