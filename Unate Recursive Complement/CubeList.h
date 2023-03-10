#pragma once

#include <vector>
#include <deque>
#include "Cube.h"

using namespace std;

class CubeList {

public:

	int number_of_variables;
	int number_of_cubes;

	deque<Cube> cubes;

	CubeList();

	CubeList(int number_of_variables);

	CubeList(int number_of_variables, int number_of_cubes);

	CubeList(const CubeList &origin);
	CubeList &operator=(const CubeList& origin);

	CubeList positiveCofactor(int x);

	CubeList negativeCofactor(int x);

	bool isBinate();

	int MostBinate();

	int Mostunate();

	bool isAllDontCaresCube();

	void AND(int x, int T);

	void addCube(Cube &c);
	
};

