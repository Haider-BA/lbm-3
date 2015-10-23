#ifndef FLUID
#define FLUID

#include"medium.h"

class fluid
{
public:
	fluid(const medium&, int, int);
	~fluid();



	void set_initial_conditions();

	float& set_value(int y, int x, float* mas){
		if (x >= 0 && x < nx && y >=0 && y < ny)
			*(mas + nx * y + x) = 

	void const display();

private:
	int nx;
	int ny;

	float* rho;
	float* vx;
	float* vy;
};

#endif	// FLUID