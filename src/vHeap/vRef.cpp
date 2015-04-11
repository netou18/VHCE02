/*
 * vRef.cpp
 *
 *  Created on: 10/4/2015
 *      Author: ernesto
 */

#include "vRef.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

vRef::vRef(int id) {
	cout << "Creando puntero..." << endl;
	ID = (int*)malloc(sizeof(int));
	*ID = id;
	cout << "Puntero creado." << endl;
}

vRef::~vRef() {
}

