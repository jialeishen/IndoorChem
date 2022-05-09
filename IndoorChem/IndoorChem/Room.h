#pragma once
#ifndef ROOM_H // include guard
#define ROOM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "IndoorChem.h"

using namespace std;

class Room
{
public:
    Room();
    Room(vector<string> vec);
    //Room(const Room& r);
    ~Room();
    //Surface* surfaces[100];
    ////vector<Surface*> surfaces;
    //void setSurface(Surface *s);
    //int num_surface = 0;
    string name;
    string id;
    string type;
    double volume = 0;
    int pollutant_num = 0;


};

#endif