#include <iostream>
#include "header/3d_terrain_builder.h"
#include "header/classes/3d_object.h"
#include "header/tri_to_quad_sort.h"

void triangulateField(Vertexlist& vList, int width, int length)
{
    std::vector<Vertex> cList = vList.getVertexList();
    int idOne, idTwo, idThree;

    // work in quads!
    for (int l = 0; l < length; l++)
    {
        if (l + 1 < length)
        {
            for (int w = 0; w < width; w++)
            {
                if (w + 1 < width)
                {
                    idOne = vList.findVertexIdByCoords(w, l);
                    // makes sure it hasn't reached the border
                    idTwo = vList.findVertexIdByCoords(w + 1, l);
                    idThree = vList.findVertexIdByCoords(w, l + 1);
                    vList.setTriGroup(idTwo, idOne, idThree);

                    // sets second triangle in quad form
                    idOne = vList.findVertexIdByCoords(w + 1, l);
                    idTwo = vList.findVertexIdByCoords(w + 1, l + 1);
                    idThree = vList.findVertexIdByCoords(w, l + 1);
                    vList.setTriGroup(idTwo, idOne, idThree);
                }
            }
        }
    }

    sortTrisToQuad(vList);
}

Vertexlist createField(int pLength, int pWidth)
{
    // creates a plane for now
    // z for depth of plane
    Vertexlist aList;

    // sets the vertexes for the plane
    for(int z = 0; z < pLength; z++)
    {
        for(int x = 0; x < pWidth; x++)
        {
            Vertex aVertex(x, 0, z);
            aList.addVertexToList(aVertex);
        }
    }

    int i = 0;
    for(Vertex v : aList.getVertexList())
    {
        ++i;
        while(i >= 5)
        {
            i = 0;
            std::cout << std::endl;
        }
    }

    triangulateField(aList, pWidth, pLength);

    return aList;
}