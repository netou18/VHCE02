#ifndef SRC_RES_VDEBUG_H_
#define SRC_RES_VDEBUG_H_
#include <string>
#include <fstream>
using namespace std;

class vDebug {
private:
	vDebug();
	static vDebug* instancia;
	bool activo;
public:
	~vDebug();
	void print(bool enter, string msg);
	void print(bool enter, string msg, int num);
	static vDebug* getInstance() {				//
		if (instancia == 0)						//Patron singleton
			instancia = new vDebug();			//
		return instancia;						//
	}
};

#endif /* SRC_RES_VDEBUG_H_ */
