#ifndef MEDIOUM_H
#define MEDIOUM_H

enum cellType
{
	boundary = false,
	fluid = true
	
};

class medium
{
public:
	medium(unsigned int, unsigned int);
	~medium();

	void set_state(unsigned int y, unsigned int x, cellType state){
		if (y >= 0 && y < ny && x >= 0 && x < nx)
			*(body + y * nx + x) = state;
	}

	void const display();

private:
	unsigned int nx;
	unsigned int ny;
	bool* body;
};

#endif	// MEDIOUM_H