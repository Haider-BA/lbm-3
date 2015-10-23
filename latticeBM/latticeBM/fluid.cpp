#include<iostream>
#include"fluid.h"

fluid::fluid(const medium& _medium, int _ny, int _nx): ny(_ny), nx(_nx){
	rho = new float[nx * ny];
	vx = new float[nx * ny];
	vy = new float[nx * ny];

	for (int id = 0; id < nx * ny; ++id)
		rho[id] = vx[id] = vy[id] = 0.0f;
	display();
}

fluid::~fluid(){
	delete[] rho;
	delete[] vx;
	delete[] vy;
}

void fluid::set_initial_conditions(){
	for (unsigned int y = 0; y < ny; ++y)
}

void const fluid::display(){
	for (int y = 0; y < ny; ++y){
		for (int x = 0; x < nx; ++x)
			std::cout << *(rho + y * nx + x) << ' ';
		std::cout << std::endl;
	}
}