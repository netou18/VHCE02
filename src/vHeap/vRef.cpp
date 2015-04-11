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
	cout << "Creando puntero...ID: " << id << endl;
	ID = id;
	cout << "Puntero creado." << endl;
}

vRef::~vRef() {
}

int vRef::getID(){
	return ID;
}

