#include <iostream>
#include <vector>
#include <string>
#include "header/3d_terrain_builder.h"
#include "header/classes/3d_object.h"
#include "header/output_file.h"

/*
    title: 3d obj builder
    name:  Ian Robertson
*/
bool getChoice();
int getNumInput(int, int);
std::string getNameInput();
Mesh* createMesh(std::string);
void pushBackObject(std::vector<Object*>& objList, std::string name);

int main()
{
    bool isLoop = true;
    int length = -1, width = -1;
    std::vector<Object*> objList;
    Vertexlist vList;
    std::string name = "";

    std::cout << "Welcome to the 3d Object terrain builder" << std::endl;
    std::cout << "Would you like to make a 3d terrain? y or n ";

    // i used for Object naming increment
    int i = 0; 

    while (isLoop == true)
    {
        if (getChoice() == true)
        {
            i++;
            std::cout << "\nWould you like to give the terrain object a name? y or n? ";
            std::cin.ignore(10000, '\n');
            if (getChoice() == true)
            {
                std::cin.ignore(10000, '\n');
                pushBackObject(objList, getNameInput());
                std::cout << "\nEnter Dimentions between 1 x 1 or 1000 x 1000 " << std::endl;

                std::cout << "\nEnter for Length: ";
                length = getNumInput(1, 1000);
                std::cout << "\nEnter for Width: ";
                width = getNumInput(1, 1000);
                objList[i - 1]->setVertexData(createField(length + 1, width + 1));
            }
            else
            {
                std::cin.ignore(10000, '\n');
                name = "Terrain " + std::to_string(i);
                pushBackObject(objList, name);
                std::cout << "\nEnter Dimentions between 1 x 1 or 1000 x 1000 " << std::endl;

                std::cout << "\nEnter for Length: ";
                length = getNumInput(1, 1000);
                std::cout << "\nEnter for Width: ";
                width = getNumInput(1, 1000);
                objList[i - 1]->setVertexData(createField(length + 1, width + 1));
            }
            std::cout << "\nObject name: " << objList[i-1]->getObjName();
        }
        else
        {
            isLoop = false;
        }
        std::cin.ignore(10000, '\n');
        std::cout << "\nWould you like to create another terrain obj file? y or n? ";
    }

    if (objList.empty() == false)
    {
        outputFile(objList);
    }

    return 0;
}

bool getChoice()
{
    char choice;
    bool flag = false;
    bool loop = true;
    choice = std::cin.get();

    while (loop == true)
    {
        if (choice == 'y' || choice == 'Y')
        {
            flag = true;
            loop = false;
        }
        else if (choice == 'n' || choice == 'N')
        {
            loop = false;
        }
        else
        {
            std::cout << "\nWrong choice! please try again. y or no ";
            std::cin.ignore(10000, '\n');
            choice = std::cin.get();
        }
    }

    return flag;
}

int getNumInput(int min, int max)
{
    int num;
    std::cin >> num;
    while (std::cin.fail() || num < min || num > max)
    {
        std::cout << "\nInvalid input! please try again";
        std::cin.ignore(10000, '\n');
        std::cin >> num;
    }

    return num;
}

std::string getNameInput()
{
    std::string name;
    std::cout << "\nEnter the name for your file: ";
    std::getline(std::cin, name);
    return name;
}

Mesh* createMesh(std::string name)
{
    Mesh* aMesh = new Mesh(name);
    return aMesh;
}

void pushBackObject(std::vector<Object*>& objList, std::string name)
{
    objList.push_back(createMesh(name));
}
