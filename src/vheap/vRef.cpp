/*
 * vRef.cpp
 *
 *  Created on: 10/4/2015
 *      Author: ernesto
 */

#include "../vheap/vRef.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

vRef::vRef(int id) {
	ID = id;
}

vRef::~vRef() {
}

int vRef::getID(){
	return ID;
}

