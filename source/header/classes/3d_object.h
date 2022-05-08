#pragma once
#include <iostream>
#include "3d_object_parts.h"

class Object
{
private:
    std::string objName;
public:
    Object(std::string name)
    {
        objName = name;
    }

    virtual Vertexlist getVertexData() = 0;

    virtual void setVertexData(const Vertexlist& recievedList) = 0;

    std::string getObjName() { return objName; }

};

class Mesh : public Object
{
private:
    Vertexlist vList;
public:
    Mesh(std::string name) : Object(name) { }

    Vertexlist getVertexData()
    {
        return vList;
    }

    void setVertexData(const Vertexlist& recievedList)
    {
        this->vList = recievedList;
    }
};
