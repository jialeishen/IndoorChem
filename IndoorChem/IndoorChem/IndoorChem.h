// OzoneChemistry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef INDOORCHEM_H // include guard
#define INDOORCHEM_H

// OzoneChemistry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Room;

class Surface
{
public:
    Surface();
    Surface(vector<string> vec);
    //Surface(const Surface& obj);
    ~Surface();
    string name;
    string id;
    Room* room;
    string room_id;
    /*void setRoom(Room r);
    void setRoom(vector<Room> rs);*/
    void setRoom(vector<Room> rs);
};

#endif