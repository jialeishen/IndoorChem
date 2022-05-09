// OzoneChemistry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//#include "IndoorChem.h"
#include "Room.h"


using namespace std;

namespace constant
{
    const int monthDays[12]
        = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

namespace process
{
    //int find_room(Room* rooms[100], string id)//(vector<Room*> rooms, string id)
    //{
    //    for (int i = 0; i < sizeof(rooms); i++)
    //    {
    //        cout << "inside find_room: " << endl;
    //        cout << rooms[i]->id << endl;
    //        cout << &rooms[i] << endl;
    //        if (rooms[i]->id == id)
    //        {
    //            return i;
    //        }
    //        else
    //        {
    //            cout << "Cannot find the room with the specific ID from the current room list." << endl;
    //            return -1;
    //        }
    //    }
    //}

    int get_days(int m1, int d1, int m2, int d2)
    {
        int n1 = 0;
        int n2 = 0;
        if (m1 > 1)
        {
            for (int i = 0; i < m1 - 1; i++)
            {
                n1 += constant::monthDays[i];
            }
        }
        n1 += d1;

        if (m2 > 1)
        {
            for (int i = 0; i < m2 - 1; i++)
            {
                n2 += constant::monthDays[i];
            }
        }
        n2 += d2;

        int days = n2 - n1 + 1;
        return days;
    }

    inline string& ltrim(string& str, string const& whitespace = " \r\n\t\v\f")
    {
        str.erase(0, str.find_first_not_of(whitespace));
        return str;
    }

    inline string& rtrim(string& str, string const& whitespace = " \r\n\t\v\f")
    {
        str.erase(str.find_last_not_of(whitespace) + 1);
        return str;
    }

    inline string& trim(string& str, string const& whitespace = " \r\n\t\v\f")
    {
        return ltrim(rtrim(str, whitespace), whitespace);
    }

    inline bool ends_with(string const& value, string const& ending)
    {
        if (ending.size() > value.size()) return false;
        return equal(ending.rbegin(), ending.rend(), value.rbegin());
    }

    inline string& lower_case(string& str)
    {
        transform(str.begin(), str.end(), str.begin(), tolower);
        return str;
    }

    vector<string>& lower_case_for_vector(vector<string>& vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i] = lower_case(vec[i]);
        }
        return vec;
    }

    string& remove_delimiter(string& str)
    {
        if (ends_with(str, ",") or ends_with(str, ";"))
        {
            str.pop_back();
        }
        return str;
    }

    /*vector<string&> remove_delimiters(vector<string&> str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (ends_with(str[i], ",") or ends_with(str[i], ";"))
            {
                str.pop_back();
            }
        }
        
        return str;
    }*/

    vector<int> get_indices(vector<string> vec, string element)
    {
        vector<int> indices;
        auto it = vec.begin();
        while ((it = find_if(it, vec.end(), [&](string const& e) { return e == element; }))
            != vec.end())
        {
            indices.push_back(distance(vec.begin(), it));
            it++;
        }
        return indices;
    }

    int get_index(vector<string> vec, string element)
    {
        string e = element;
        vector<string> vec_lower = process::lower_case_for_vector(vec);
        auto it = find(vec_lower.begin(), vec_lower.end(), process::lower_case(element));

        // If element was found
        if (it != vec_lower.end())
        {
            // calculating the index of element
            int index = it - vec_lower.begin();
            return index;
        }
        else
        {
            // If the element is not
            // present in the vector
            cout << "Cannot find \"" << e << "\" in the input file." << endl;
            return -1;
        }
    }
}



Room::Room()
{

}

Room::Room(vector<string> vec)
{
    name = vec[0];
    id = vec[1];
    type = vec[2];
    volume = stod(vec[3]);
    pollutant_num = stoi(vec[9]);
}

//Room(const Room& r)
//{

//}

Room::~Room()
{

}

//void Room::setSurface(Surface* s)
//{
//    surfaces[num_surface] = s;
//    num_surface += 1;
//    //surfaces.push_back(s);
//}

//void Room::setSurface(vector<Surface> &sur)
//{
//    for (int i = 0; i < sur.size(); i++)
//    {
//        if (sur[i].room_id == id)
//        {
//            *surfaces.push_back(sur[i]);
//            sur[i].setRoom(*this);
//        }
//    }
//}

//
//Room::Room()
//{
//
//}
//
//Room::Room(vector<string> vec)
//{
//    name = vec[0];
//    id = vec[1];
//    type = vec[2];
//    volume = stod(vec[3]);
//}
//
//Room::~Room()
//{
//
//}

class Material
{
public:
    Material();
    ~Material();
    string name = "gypsum";
};

Material::Material()
{

}

Material::~Material()
{

}


Surface::Surface()
{

}

Surface::Surface(vector<string> vec)
{
    name = vec[0];
    id = vec[1];
    room_id = vec[2];
    angle = stod(vec[3]);
    area = stod(vec[4]);
    material_name = vec[5];
    temperature = stod(vec[6]);
    airflow = stod(vec[7]);

}

/*Surface(const Surface& s)
{

}*/

Surface::~Surface()
{

}

//void Surface::setRoom(Room r)
//{
//    room = &r;
//    //room->surfaces->push_back(&this);
//}
//
//void Surface::setRoom(Room* rs[100]) //(vector<Room*> rs)
//{
//    cout << "room id: " << room_id << endl;
//    cout << "input room id: " << rs[0]->id << endl;
//
//    int index;
//    index = process::find_room(rs, room_id);
//
//    room = rs[index];
//    cout << "index: " << index << endl;
//    cout << rs[index]->name << endl;
//    cout << room->name << endl;
//    cout << &room << endl;
//    cout << room->id << endl;
//
//    room->setSurface(this);
//
//    //rs[index].surfaces.push_back(this);
//    //room->surfaces.push_back(this);
//
//    cout << "Room surface size: " << sizeof(room->surfaces) << endl;
//}
//
//Surface::Surface()
//{
//    
//}
//
//Surface::Surface(vector<string> vec)
//{
//    name = vec[0];
//    id = vec[1];
//    room_id = vec[2];
//    angle = stod(vec[3]);
//    area = stod(vec[4]);
//    material_name = vec[5];
//    temperature = stod(vec[6]);
//    airflow = stod(vec[7]);
//
//}
//
//Surface::~Surface()
//{
//
//}



Occupant::Occupant()
{

}

Occupant::Occupant(vector<string> vec)
{
    name = vec[0];
    id = vec[1];
    room_id = vec[2];
    group = vec[3];
    clothing = vec[4];
    activity = vec[5];
    material_name = vec[6];
    airflow = stod(vec[7]);
}

Occupant::~Occupant()
{

}

class Infiltration
{

};



Furniture::Furniture()
{

}

Furniture::Furniture(vector<string> vec)
{

    name = vec[0];
    id = vec[1];
    room_id = vec[2];
    angle = stod(vec[3]);
    area = stod(vec[4]);
    material_name = vec[5];
    temperature = stod(vec[6]);
    airflow = stod(vec[7]);

}

Furniture::~Furniture()
{

}

AHU::AHU()
{

}

AHU::AHU(vector<string> vec)
{
    int num_pol = (vec.size() - 5) / 3;
    name = vec[0];
    id = vec[1];
    room_id = vec[2];
    airflow = stod(vec[3]);
    schedule_name = vec[vec.size() - 1];
    cout << "before loop of AHU" << endl;
    for (int i = 0; i < num_pol; i++)
    {
        if (vec[4 + i] == "" or vec[4 + i].size() == 0)
        {
            SPREs.push_back(0);
        }
        else
        {
            SPREs.push_back(stod(vec[4 + i]));
        }

        if (vec[4 + i + num_pol] == "" or vec[4 + i + num_pol].size() == 0)
        {
            CADRs.push_back(0);
        }
        else
        {
            CADRs.push_back(stod(vec[4 + i + num_pol]));
        }

        if (vec[4 + i + num_pol * 2] == "" or vec[4 + i + num_pol * 2].size() == 0)
        {
            emissions.push_back(0);
        }
        else
        {
            emissions.push_back(stod(vec[4 + i + num_pol * 2]));
        }        
    }
}

AHU::~AHU()
{

}

AirCleaner::AirCleaner()
{

}

AirCleaner::AirCleaner(vector<string> vec)
{
    int num_pol = (vec.size() - 5) / 3;
    name = vec[0];
    id = vec[1];
    room_id = vec[2];
    airflow = stod(vec[3]);
    schedule_name = vec[vec.size() - 1];
    for (int i = 0; i < num_pol; i++)
    {
        if (vec[4 + i] == "" or vec[4 + i].size() == 0)
        {
            SPREs.push_back(0);
        }
        else
        {
            SPREs.push_back(stod(vec[4 + i]));
        }

        if (vec[4 + i + num_pol] == "" or vec[4 + i + num_pol].size() == 0)
        {
            CADRs.push_back(0);
        }
        else
        {
            CADRs.push_back(stod(vec[4 + i + num_pol]));
        }

        if (vec[4 + i + num_pol * 2] == "" or vec[4 + i + num_pol * 2].size() == 0)
        {
            emissions.push_back(0);
        }
        else
        {
            emissions.push_back(stod(vec[4 + i + num_pol * 2]));
        }
    }
}

AirCleaner::~AirCleaner()
{

}

Pollutant::Pollutant()
{

}

Pollutant::Pollutant(string p)
{
    name = p;
}

Pollutant::Pollutant(vector<string> vec)
{

}

Pollutant::~Pollutant()
{

}

/*class Reaction
{

};

class SurfaceReaction : public Reaction
{

};

class GaseousReaction : public Reaction
{

};

class Schedule
{

};

class Facility
{

}*/;



IndoorChemModel::IndoorChemModel(string filename)
{
    //name = filename;
    string line;
    ifstream file;
    vector<string> inputLines;
    inputLines.clear();
    inputs_original.clear();
    //filename = "C:/Users/Jialei Shen/Desktop/test.icp";
    file.open(filename.c_str());
    if (file.is_open())
    {
        cout << "IndoorChem Project (.icp) is open" << endl;
        while (getline(file, line))
        {
            string lineNoComment = line.substr(0, line.find("!", 0));
            string lineClean = process::trim(lineNoComment);
            if (lineClean == "" or lineClean.length() == 0)
            {
                continue;
            }
            else
            {
                inputs_original.push_back(lineClean);
                inputLines.push_back(process::remove_delimiter(lineClean));
            }

            //cout << line << endl;
        }
        parseInput(inputLines);
        //cout << name << endl;
    }
    else
    {
        cout << "Error: the file is not open";
    }

    file.close();
}

IndoorChemModel::~IndoorChemModel()
{

}

void IndoorChemModel::parseInput(vector<string> inputs)
{
    // import project
    indexProject = process::get_index(inputs, "Project");
    solver = inputs[indexProject + 1];
    version = inputs[indexProject + 2];
    name = inputs[indexProject + 3];
    type = inputs[indexProject + 4];
    time = inputs[indexProject + 5];
    // import runperiod
    indexRunPeriod = process::get_index(inputs, "RunPeriod");
    runPeriod[0] = stoi(inputs[indexRunPeriod + 1]); // start month
    runPeriod[1] = stoi(inputs[indexRunPeriod + 2]); // start day
    runPeriod[2] = stoi(inputs[indexRunPeriod + 3]); // end month
    runPeriod[3] = stoi(inputs[indexRunPeriod + 4]); // end day
    runPeriod[4] = stoi(inputs[indexRunPeriod + 5]); // hours 
    runPeriod[5] = stoi(inputs[indexRunPeriod + 6]); // runsteps per hour
    runDays = process::get_days(runPeriod[0], runPeriod[1], runPeriod[2], runPeriod[3]);
    runSteps = runDays * runPeriod[4] * runPeriod[5];
    secondsPerStep = 3600 / runPeriod[5];
    // import room
    indicesRoom = process::get_indices(inputs, "Room");
    cout << indicesRoom[0] << endl;
    if (indicesRoom.empty() or indicesRoom.size() < 1)
    {
        cout << "Cannot find \"Room\" in the file.";
    }
    else
    {
        for (int i = 0; i < indicesRoom.size(); i++)
        {
            vector<string> vec;
            vec.clear();
            for (int j = 1; j < 11; j++)
            {
                vec.push_back(inputs[indicesRoom[i] + j]);
            }
            Room room(vec);
            cout << vec.size() << endl;
            cout << "Original room address: " << &room << endl;
            numPollutant = stoi(vec[9]);
            //rooms[i] = &room;
            rooms.push_back(room);
            cout << "Vector room address: " << &rooms[i] << endl;
            cout << "Room id: " << rooms[i].id << endl;
        }
    }

    cout << "Room size: " << rooms.size() << endl;
    cout << "Room [0] id: " << rooms[0].id << endl;
    cout << &rooms[0] << endl;


    // import surface
    indicesSurface = process::get_indices(inputs, "Surface");
    for (int i = 0; i < indicesSurface.size(); i++)
    {
        vector<string> vec;
        for (int j = 1; j < 9; j++)
        {
            vec.push_back(inputs[indicesSurface[i] + j]);
        }
        Surface surface(vec);
        cout << "Original surface address: " << &surface << endl;
        //surface.setRoom(rooms);
        //surfaces[i] = &surface;
        surfaces.push_back(surface);
        cout << "Vector surface address: " << &surfaces[i] << endl;
        cout << "Vector [0] surface address: " << &surfaces[0] << endl;
    }

    /*for (int i = 0; i < rooms.size(); i++)
    {
        rooms[i].setSurface(surfaces);
    }*/

    // import occupant
    indicesOccupant = process::get_indices(inputs, "Occupant");
    for (int i = 0; i < indicesOccupant.size(); i++)
    {
        vector<string> vec;
        for (int j = 1; j < 9; j++)
        {
            vec.push_back(inputs[indicesOccupant[i] + j]);
        }
        Occupant occupant(vec);
        occupants.push_back(occupant);
    }
    cout << "Occupant done" << endl;

    // import furniture
    indicesFurniture = process::get_indices(inputs, "Furniture");
    for (int i = 0; i < indicesFurniture.size(); i++)
    {
        vector<string> vec;
        for (int j = 1; j < 9; j++)
        {
            vec.push_back(inputs[indicesFurniture[i] + j]);
        }
        Furniture furniture(vec);
        furnitures.push_back(furniture);
    }
    cout << "Furniture done" << endl;


    // import POC
    indicesPollutant = process::get_indices(inputs, "POC");
    for (int i = 0; i < indicesPollutant.size(); i++)
    {
        vector<string> vec;
        bool finished = false;
        int j = 1;
        while (!finished)
        {
            string p = inputs[indicesPollutant[i] + j];
            //vec.push_back(inputs[indicesPollutant[i] + j]);
            Pollutant pollutant(p);
            pollutants.push_back(pollutant);
            if (process::ends_with(inputs_original[indicesPollutant[i] + j], ";"))
            {
                finished = true;
            }
            j += 1;
        }
        /*Pollutant pollutant(vec);
        pollutants.push_back(pollutant);*/
        pollutant_num = pollutants.size();
    }
    cout << "POC done" << endl;

    
    cout << pollutant_num << endl;

    // import AHU
    indicesAHU = process::get_indices(inputs, "AHU");
    for (int i = 0; i < indicesAHU.size(); i++)
    {
        vector<string> vec;
        for (int j = 1; j < 6 + 3 * pollutant_num; j++)
        {
            vec.push_back(inputs[indicesAHU[i] + j]);
        }
        cout << "AHU vec created" << endl;
        cout << vec.size() << endl;
        AHU ahu(vec);
        ahus.push_back(ahu);
    }
    cout << "AHU done" << endl;

    // import AirCleaner
    indicesAirCleaner = process::get_indices(inputs, "AirCleaner");
    for (int i = 0; i < indicesAirCleaner.size(); i++)
    {
        vector<string> vec;
        for (int j = 1; j < 6 + 3 * pollutant_num; j++)
        {
            vec.push_back(inputs[indicesAirCleaner[i] + j]);
        }
        AirCleaner aircleaner(vec);
        aircleaners.push_back(aircleaner);
    }
    cout << "AirCleaner done" << endl;

    cout << "Parsing done!" << endl;
}


void IndoorChemModel::run()
{
    cout << "Model successfully run.\nName: " << name << endl;
    cout << "Solver: " << solver << endl;
    cout << "Time: " << time << endl;
    cout << "Days: " << runDays << endl;
    cout << "Seconds per step: " << secondsPerStep << endl;
    cout << rooms[0].id << endl;
    cout << surfaces[3].id << endl;
    cout << &rooms[0] << endl;
    cout << "Surface address: " << endl;
    cout << &surfaces[0] << endl;
    cout << &surfaces[1] << endl;
    cout << &surfaces[2] << endl;
    cout << &surfaces[3] << endl;
    cout << occupants[0].activity << endl;
    /*cout << surfaces[3]->room->name << endl;
    cout << rooms[0]->surfaces << endl;
    cout << rooms[0]->surfaces[3]->name << endl;*/
}




int main(int argc, char* argv[])
{

    vector<string> args(argv, argv + argc);
    bool validCommand = false;
    for (size_t i = 1; i < args.size(); ++i)
    {
        if (args[i] == "-r" or args[i] == "-R")
        {
            validCommand = true;
            string filename;
            if (i + 1 < args.size())
            {
                filename = args[i + 1];
            }
            else
            {
                cout << "Please input a IndoorChem Project (.icp) file: ";
                cin >> filename;
            }

            if (process::ends_with(filename, ".icp"))
            {
                IndoorChemModel model = IndoorChemModel(filename);
                model.run();
            }
            else
            {
                cout << "TypeError: Cannot open \"" << filename << "\". It is NOT a valid IndoorChem Project (.icp) file." << endl;
            }
        }
        else if (args[i] == "-h" or args[i] == "-H")
        {
            cout << "Please visit http://www.jialeishen.com/indoorchem/ for more information." << endl;
            validCommand = true;
        }
        else if (args[i] == "-v" or args[i] == "-V")
        {
            cout << "Version 1.0" << endl;
            validCommand = true;
        }
    }

    if (!validCommand)
    {
        cout << "Please input valid commands.\nReference:" << endl << "    -r:\tRun a.icp model\n    -R:\tRun a.icp model\n    -h:\tHelp\n    -H:\tHelp\n    -v:\tVersion\n    -V:\tVersion" << endl;
        return -1;
    }
    return 0;
}
