#include<iostream>
#include"medium.h"

medium::medium(unsigned int _ny, unsigned int _nx): nx(_nx), ny(_ny){
	body = new bool[nx * ny];
	for (unsigned int y = 1; y < ny - 1; ++y)
		for (unsigned int x = 1; x < nx - 1; ++x)
			set_state(y, x, cellType::fluid);

	for (unsigned int y = 0; y < ny; ++y){
		set_state(y, 0, cellType::boundary);
		set_state(y, nx - 1, cellType::boundary);
	}
		
	for (unsigned int x = 0; x < nx; ++x){
		set_state(0, x, cellType::boundary);
		set_state(ny - 1, x, cellType::boundary);
	}

	display();
}

medium::~medium(){
	delete[] body;
}


void const medium::display(){
	for (unsigned int y = 0; y < ny; ++y){
		for (unsigned int x = 0; x < nx; ++x){
			if (*(body + y * nx + x) == cellType::boundary)
				std::cout << " bound ";
			else
				std::cout << " fluid ";
		}
		std::cout << std::endl;
	}
}
