#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;

int main(int argc, const char* argv[])
{
    int count=0;
    /* Populate a map object and then parse it */
    /*map<string,string> passport =
    {
        {"byr", ""},
        {"iyr", ""},
        {"eyr", ""},
        {"hgt", ""},
        {"hcl", ""},
        {"ecl", ""},
        {"pid", ""},
        {"cid", ""}
    };
    passport["byr"] = "ccc";
    for (auto it = passport.begin(); it != passport.end(); ++it)
    {
        cout << it->first << it->second << endl;
    } */
    std::string passports[7] = {"byr", "iyr", "eyr","hgt","hcl","ecl","pid"};
    ifstream input("input.txt");
    bool flag = false;
    std::string concatString = "";
    for (std::string line; getline(input, line);)
    {
        if (line.length() != 1)
        {
            concatString = concatString + line;
        }
        else if (line.length() == 1)
        {
            for (int i=0; i<7; i++)
            {
                if (concatString.find(passports[i]) == std::string::npos)
                {
                    flag = true;
                }
            }
            if (flag == false)
            {
                count++;
            }
                flag = false;
                concatString = "";
                cout << count << endl;
        }
    }
    return 0;
}