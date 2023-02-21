// Unate Recursive Complement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include "CubeList.h"
#include "Cube.h"

using namespace std;

CubeList complementOneCubed(CubeList F) {
	CubeList nF(F.number_of_variables);
	for (int i = 0; i < F.number_of_variables; i++) {
		Cube c(F.number_of_variables);
		switch (F.cubes.front().getValue(i + 1)) {
		case 1:
			c.setValue(i + 1, 0);
			nF.addCube(c);
			break;
		case 2:
			c.setValue(i+1, 1);
			nF.addCube(c);
			break;
		}
	}
	return nF;
}

CubeList Complement(CubeList F) {
	// Empty cube list
	if (F.number_of_cubes == 0) {
		Cube c(F.number_of_variables);
		F.addCube(c);
		return F;
	}
	// Cube list contains just one cube
	else if(F.number_of_cubes == 1){
		return complementOneCubed(F);
	}
	// Cube list contains All Don�t Cares Cube
	else if (F.isAllDontCaresCube()) {
		CubeList q(F.number_of_variables);
		return q;
	}
	else {

		int x;
	
		if (F.isBinate()) {
			x = F.MostBinate();
		}
		else {
			x = F.Mostunate();
		}

		CubeList P = Complement(F.positiveCofactor(x));
		CubeList N = Complement(F.negativeCofactor(x));

		P.AND(x, 1);
		N.AND(x, 0);
		
		for (Cube c : N.cubes) {
			P.addCube(c);
		}

		return P;
	}
}

int main()
{
	freopen("part5.pcn", "r", stdin);
	freopen("outputpart5.pcn", "w", stdout);

	int number_of_variables;
	int number_of_cubes;
	int variables, value, i , j;

	cin >> number_of_variables >> number_of_cubes;

	CubeList F(number_of_variables);
	
	for (i = 0; i < number_of_cubes; i++) {
		cin >> variables;
		Cube c(number_of_variables);
		for (j = 0; j < variables; j++) {
			cin >> value;
			c.setValue_at(value);
		}
		F.addCube(c);
	}

	

	CubeList Fp = Complement(F);

	cout << number_of_variables << endl;
	cout << Fp.number_of_cubes << endl;
	for (Cube c: Fp.cubes) {
		int x = 0;
		for (j = 0; j < number_of_variables; j++)
			if (c.getValue(j + 1) < 3) x++;
		cout << x << ' ';
		for (j = 0; j < number_of_variables; j++) {
			if (c.getValue(j + 1) == 3) continue;
			if (c.getValue(j + 1) == 1)
				cout << j + 1;
			else if(c.getValue(j + 1) == 2)
				cout << -1 * j - 1;
			if (j != number_of_variables - 1)
				cout << ' ';
		}
		if(i!= Fp.number_of_cubes-1)
			cout << endl;
	}

}

