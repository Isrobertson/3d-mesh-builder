#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "header/classes/3d_object.h"
#include "header/3d_height_perlin_noise.h"

/*
	 this file determines the height of each vertice along the terrain to create formations

	 -- source file not working correctly but will keep for refactoring later --
*/

void determineVertexHeight(Vertexlist& vList)
{
	int id = 0;
	double offsetUp = 0.05;
	double offsetDown = -0.05;
	double calibratedPoint = 0;
	int randNum = 0;

	for (Vertex v : vList.getVertexList())
	{
		srand(time(0));
		randNum = (rand() % 2) + 1;
		std::cout << "\nRandom number: " << randNum;
		if (randNum == 1)
		{
			v.setY(calibratedPoint + offsetUp);
		}
		else if (randNum == 2)
		{
			v.setY(calibratedPoint + offsetDown);
		}

		calibratedPoint = v.getY();
		vList.setIndividualVertex(v, id++);
	}

	// debug
	for (Vertex v : vList.getVertexList())
	{
		std::cout << "\nY: " << v.getY();
	}
}
