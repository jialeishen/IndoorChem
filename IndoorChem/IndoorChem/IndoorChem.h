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
    /*Room* room;*/
    string room_id;
    double angle;
    double area; 
    string material_name; 
    double temperature;
    double airflow;
    //void setRoom(Room* rs[100]);//(vector<Room*> rs);
};

class Occupant
{
public:
    Occupant();
    Occupant(vector<string> vec);
    ~Occupant();
    /*Room *room;*/
    string name;
    string id;
    string room_id;
    string group;
    string clothing;
    string activity;
    string material_name;
    double airflow;
    /*void setRoom(Room r);

    void setRoom(Room r)
    {
        room = r;
    }*/

};

class Furniture
{
public:
    Furniture();
    Furniture(vector<string> vec);
    ~Furniture();

    string name;
    string id;
    string room_id;
    double angle;
    double area;
    string material_name;
    double temperature;
    double airflow;

};

class Pollutant
{
public:
    Pollutant();
    Pollutant(string p);
    Pollutant(vector<string> vec);
    ~Pollutant();
    string name;
    vector<string> names;
};

class AHU
{
public:
    AHU();
    AHU(vector<string> vec);
    ~AHU();
    string name;
    string id;
    string room_id;
    double airflow;
    vector<double> SPREs;
    vector<double> CADRs;
    vector<double> emissions;
    string schedule_name;
};

class AirCleaner
{
public:
    AirCleaner();
    AirCleaner(vector<string> vec);
    ~AirCleaner();
    string name;
    string id;
    string room_id;
    double airflow;
    vector<double> SPREs;
    vector<double> CADRs;
    vector<double> emissions;
    string schedule_name;
};

class IndoorChemModel
{
public:
    IndoorChemModel(string filename);
    ~IndoorChemModel();
    string name;
    string solver;
    string version;
    string type;
    string time;
    int pollutant_num;
    vector<string> inputs_original;

    /*Room* rooms[100];
    Surface* surfaces[100];*/
    vector<Room> rooms;
    vector<Surface> surfaces;
    vector<Occupant> occupants;
    vector<Furniture> furnitures;
    //vector<Facility> facilities;
    vector<AHU> ahus;
    vector<AirCleaner> aircleaners;
    vector<Pollutant> pollutants;
    //vector<Reaction> reactions;
    int runPeriod[6] = {};
    int runDays;
    int runSteps;
    int secondsPerStep;
    void run();
private:
    int indexProject;
    int indexRunPeriod;
    vector<int> indicesRoom;
    vector<int> indicesSurface;
    vector<int> indicesOccupant;
    vector<int> indicesFurniture;
    vector<int> indicesFacility;
    vector<int> indicesAHU;
    vector<int> indicesAirCleaner;
    vector<int> indicesPollutant;
    vector<int> indicesReaction;
    int numPollutant;

    void parseInput(vector<string> inputs);
};

#endif