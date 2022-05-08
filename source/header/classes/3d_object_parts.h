#pragma once
#include <iostream>
#include <vector>

class Vertex
{
private:
    double x, y, z;
    int id;
    static int globalID;
public:
    Vertex(double x = 0, double y = 0, double z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        id = ++globalID;
    }

    // copy constructor
    Vertex(const Vertex& v2) 
    { 
        this->x = v2.x;
        this->y = v2.y;
        this->z = v2.z;
        this->id = v2.id;
    }

    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
    int getID() { return id; }
    static int getGlobalID() { return globalID; }
    static void resetGlobalID() { globalID = 0; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }
};

/*
*
* Triangle Class
* Uses 3 vertex id's
*/
class Triangle
{
private:
    int triGroup[3];
    
    void displayRangeError()
    {
        std::cout << "\nInvalid Range!\n";
    }
public:
    Triangle()
    {
        for (int i = 0; i < 3; i++)
        {
            triGroup[i] = 0;
        }
    }

    Triangle(int idOne, int idTwo, int idThree)
    {
        int idCreate[3] = { idOne, idTwo, idThree };
        for (int i = 0; i < 3; i++)
        {
            triGroup[i] = idCreate[i];
        }
    }

    Triangle(const Triangle& tSecond)
    {
        for (int i = 0; i < 3; i++)
        {
            this->triGroup[i] = tSecond.triGroup[i];
        }
    }

    int getTriIds(int i) 
    { 
        if (i < 3 || i > 0)
        {
            return triGroup[i];
        }
           
        displayRangeError();
        return -1;
    }

    void setTriIds(int i, int id) 
    { 
        if (i > 3 || i < 0)
        {
            displayRangeError();
            triGroup[i] = id;
        }
        else
        {
            displayRangeError();
        }

    }
};

/*
*
* Quad class
* holds two triangle classes
*/
class Quads
{
private:
    Triangle tris[2];
public:
    Quads(Triangle triOne, Triangle triTwo)
    {
        tris[0] = triOne;
        tris[1] = triTwo;
    }

    void setTriOne(Triangle tOne) { tris[0] = tOne; }
    void setTriTwo(Triangle tTwo) { tris[1] = tTwo; }

    Triangle getTriOne() { return tris[0]; }
    Triangle getTriTwo() { return tris[1]; }
};

class Vertexlist
{
private:
    std::vector<Vertex> vList;
    std::vector<Triangle> triList;
    std::vector<Quads> quadList;

    void displayShortRangedTriListMessage()
    {
        std::cout << "\nNot enough Triangles!\n";
    }

public:
    ~Vertexlist()
    {
        Vertex::resetGlobalID();
    }

    // vector section
    void addVertexToList(Vertex& aVertice)                  { vList.push_back(aVertice); }
    void setIndividualVertex(Vertex& avertice, int id)      { vList[id] = avertice;  }
    std::vector<Vertex> getVertexList()                     { return vList; }
    std::vector<Triangle> getTriList()                      { return triList;  }
    std::vector<Quads> getQuadList()                        { return quadList;  }

    int findVertexIdByCoords(int x, int z)
    {
        int id = -1;
        for (Vertex v : vList)
        {
            if (v.getX() == x)
            {
                if (v.getZ() == z)
                {
                    id = v.getID();
                    break;
                }
            }
        }
        return id;
    }

    // tri section

    void setTriGroup(int idOne, int idTwo, int idThree)
    {
        Triangle aTriangle(idOne, idTwo, idThree);
        triList.push_back(aTriangle);
    }

    // quad section

    void setQuadGroups(Triangle& tOne, Triangle& tTwo)
    {
        // Quad class will collect 2 triangle classes in the quad class
        // for the Quad vector list
        Quads aQuad(tOne, tTwo);
        quadList.push_back(aQuad);
    }
};
