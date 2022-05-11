#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

class species{
public:
    string name;
    int mole_weight;
    species() {name = "NA"; mole_weight = 0;}
};

class species_list{
public:
    int num_species;
    vector<species> comps;
    void print();
};

void species_list::print(){
    for (int i =0; i < comps.size(); i++){
        cout << comps[i].name << " ";
    }

    cout << endl;
}

void read_species_MCM_file(string filename){
    cout << "reading MCM file" << endl;
    string mytext;
    species c; 
    species_list c_list;
	ifstream infile(filename);
    string start = "VARIABLE";
    string end = "****************************************************** ;";
    int flag = 0;

    while(getline(infile, mytext))
    {
        if (mytext == start) flag = 1;
        else if (mytext == end) flag = 0;
        if (flag == 1 && mytext != start ) {
            istringstream inss(mytext);
            string sub;
            while(inss >> sub){
                c.name = sub;
                if (sub != ";") c_list.comps.push_back(c);
            }
       }

    }
    
	infile.close();
    c_list.print();

}

int main()
{
    cout << "start program" << endl;
    read_species_MCM_file("single_zone.fac");  
    cout << "finish reading" << endl;
    return 0;
}