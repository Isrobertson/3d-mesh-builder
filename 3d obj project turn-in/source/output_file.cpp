#include "header/classes/3d_object.h"
#include <fstream>

void outputTriangleQuadData(std::ofstream& fileOut, Vertexlist vCopy)
{
	Triangle copyTriangle;
	fileOut << std::endl;
	for (Quads q : vCopy.getQuadList())
	{
		fileOut << "\nf ";
		copyTriangle = q.getTriOne();
		for (int i = 0; i < 3; i++)
		{
			
			fileOut << copyTriangle.getTriIds(i) << " ";
		}

		fileOut << "\nf ";
		copyTriangle = q.getTriTwo();
		for (int i = 0; i < 3; i++)
		{
			fileOut << copyTriangle.getTriIds(i) << " ";
		}
		
	}
}

void outputVerticeData(std::ofstream& fileOut, Vertexlist vCopy)
{
	for (Vertex v : vCopy.getVertexList())
	{
		fileOut << "\nv " << v.getX() << " " << v.getY() << " " << v.getZ();
	}
}

void outputFile(std::vector<Object*>& objectList)
{
	
	for (Object* o : objectList)
	{
		std::ofstream fileOut;

		fileOut.open("./output/" + o->getObjName() + ".obj");

		fileOut << "o " << o->getObjName() << std::endl;

		outputVerticeData(fileOut, o->getVertexData());
		outputTriangleQuadData(fileOut, o->getVertexData());

		fileOut.close();
		delete o;
	}
	
}