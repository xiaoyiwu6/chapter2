#include <fstream>
#include <string>
// #include "Sales_data.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "IOO.h"

using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;
using std::getline;
using std::cin;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(int argc, char const *argv[])
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(cin, line))
    {
        PersonInfo info;
        record.str(line);
        record>>info.name;
        while(record>>word){
            info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }
    
    return 0;
}