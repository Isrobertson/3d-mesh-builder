#include "header/classes/3d_object_parts.h"
#include "header/tri_to_quad_sort.h"

// this is used for easy tri sorting instead of manually sorting to quads

void sortTrisToQuad(Vertexlist& vList)
{
    std::vector<Triangle> triList = vList.getTriList();
    if (triList.empty() == false && triList.capacity() > 1)
    {
        int i = 0;
        do
        {
            vList.setQuadGroups(triList[i], triList[i + 1]);
            i += 2;
        } while (i < triList.capacity());
    }
}