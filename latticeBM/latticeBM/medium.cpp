#include<iostream>
#include"medium.h"

medium::medium(int _ny, int _nx): nx(_nx), ny(_ny){
	body = new bool[nx * ny];
	for (int y = 1; y < ny - 1; ++y)
		for (int x = 1; x < nx - 1; ++x)
			set_state(y, x, cellType::fluidCell);

	for (int y = 0; y < ny; ++y){
		set_state(y, 0, cellType::boundaryCell);
		set_state(y, nx - 1, cellType::boundaryCell);
	}
		
	for (int x = 0; x < nx; ++x){
		set_state(0, x, cellType::boundaryCell);
		set_state(ny - 1, x, cellType::boundaryCell);
	}

	display();
}

medium::~medium(){
	delete[] body;
}


void const medium::display(){
	for (int y = 0; y < ny; ++y){
		for (int x = 0; x < nx; ++x){
			if (*(body + y * nx + x) == cellType::boundaryCell)
				std::cout << " bound ";
			else
				std::cout << " fluid ";
		}
		std::cout << std::endl;
	}
}
