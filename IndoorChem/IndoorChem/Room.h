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
    vector<Surface>* surfaces;

    string name;
    string id;
    string type;
    double volume = 0;


};

#endif