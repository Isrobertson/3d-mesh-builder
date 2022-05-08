#pragma once
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
    triangle class holds the value of three vertex id's per
    per class
*/
class Triangle
{
private:
    int id[3];
public:
    /*
    Triangle(int idOne, int idTwo, int idThree)
    {
        int idCreate[3] = { idOne, idTwo, idThree };
        for (int i = 0; i < 3; i++)
        {
            id[i] = idCreate[i];
        }
    }
    */

    int getTriId(int i) { return id[i]; }
    void setTriIds(int i, int id) { this->id[i] = id; }
};

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

};

class Vertexlist
{
private:
    std::vector<Vertex*> vList;
    std::vector<Triangle> triList;
    std::vector<Quads> quadList;
    Vertex* vHolder;

public:
    ~Vertexlist()
    {
        #include <iostream> // temporary!

        // memory cleanup
        int i = 0;
        
        for (Vertex *vDelete : vList)
        {
            delete vDelete;
            std::cout << "\nDeleted: " << ++i;
        }
        Vertex::resetGlobalID();
    }

    void addVertexToList(Vertex* aVertice) { vList.push_back(aVertice); }
    std::vector<Vertex*> getVertexList()   { return vList; }


    bool checkIDRange(int id)
    {
        if (id > vList.capacity())
            return false;
        else
            return true;
    }
};
