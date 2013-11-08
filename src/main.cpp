/*
 * main.cpp
 *
 *  Created on: Nov 05, 2013
 *      Author: Bjorn Blissing
 */

#include "trakstar.h"
#include <iostream>

int main()
{
	double x = 10.0;
	double y = 10.0;
	double z = 10.0;

	for (int i=0; i < 10000; ++i) {
		TrakStar::instance().getPosition(0, x, y, z);
		std::cout << "Current position: Sensor: " << 0 << "\tx: " << x << "\ty: " << y << "\tz: " << z << std::endl;
	}

	return 0;
}