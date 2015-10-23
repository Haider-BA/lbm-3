#ifndef MEDIOUM_H
#define MEDIOUM_H

enum cellType
{
	boundaryCell = false,
	fluidCell = true
	
};

class medium
{
public:
	medium(int, int);
	~medium();

	void set_state(int y, int x, cellType state){
		if (y >= 0 && y < ny && x >= 0 && x < nx)
			*(body + y * nx + x) = state;
	}

	bool get_state(int y, int x){
		return(y >= 0 && y < ny && x >= 0 && x < nx) ? *(body + y * nx + x) : false;
	}

	int get_Nx(){ return ny; }
	int get_Ny(){ return ny; }

	void const display();

private:
	int nx;
	int ny;
	bool* body;
};

#endif	// MEDIOUM_H