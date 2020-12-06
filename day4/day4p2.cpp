
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;

bool validateValue(string key, string value)
{
    bool validated = false;
    if (key == "byr")
    {
        try
        {
            int nr = std::stoi(value);
            if (nr >= 1920 && nr <= 2002)
            {
                validated = true;
            }
        }
        catch (...)
        {
            validated = false;
        }
    }
    else if (key == "iyr")
    {
        try
        {
            int nr = std::stoi(value);
            if (nr >= 2010 && nr <= 2020)
            {
                validated = true;
            }
        }
        catch (...)
        {
            validated = false;
        }
    }
    else if (key == "eyr")
    {
        try
        {
            int nr = std::stoi(value);
            if (nr >= 2020 && nr <= 2030)
            {
                validated = true;
            }
        }
        catch (...)
        {
            validated = false;
        }
    }
    else if (key == "hgt")
    {
        try
        {
            int nr = std::stoi(value);
            if (value.find("cm") != std::string::npos)
            {
                if (nr >= 150 && nr <= 193)
                {
                    validated = true;
                }
            }
            else
            {
                if (nr >= 59 && nr <= 76)
                {
                    validated = true;
                }
            }
        }
        catch (...)
        {
            validated = false;
        }
        
    }
    else if (key == "hcl")
    {
        std::size_t pos;
        pos = value.find("#");
        if (pos == 0)
        {
            for (int i='g'; i<='z'; i++)
            {
                if (value.find((char)i) == std::string::npos)
                {
                    validated = true;
                }
                else
                {
                    validated = false;
                }
            }
        }
    }
    else if (key == "ecl")
    {
        string values[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
        for (int i=0; i<7; i++)
        {
            if (value.find(values[i]) != std::string::npos)
            {
                validated = true;
                break;
            }
        }
    }
    else if (key == "pid")
    {
        try
        {
            int nr = std::stoi(value);
            int digits = 0;
            while (nr != 0)
            {
                nr /= 10;
                digits++;
            }
            if (digits == 9)
            {
                validated = true;
            }
        }
        catch (...)
        {
            validated = false;
        }
        
    }
    return validated;
}

string getValue(string concatStr, string key)
{
    std::size_t pos;
    std::string keyValue = "";
    pos = concatStr.find(key);
    if (key == "byr")
    {
        keyValue = concatStr.substr(pos+key.length()+1,4);
    }
    else if (key == "iyr")
    {
        keyValue = concatStr.substr(pos+key.length()+1,4);
    }
    else if (key == "eyr")
    {
        keyValue = concatStr.substr(pos+key.length()+1,4);
    }
    else if (key == "hgt")
    {
        keyValue = concatStr.substr(pos+key.length()+1,5);
    }
    else if (key == "hcl")
    {
        keyValue = concatStr.substr(pos+key.length()+1,7);
    }
    else if (key == "ecl")
    {
        keyValue = concatStr.substr(pos+key.length()+1,3);
    }
    else if (key == "pid")
    {
        keyValue = concatStr.substr(pos+key.length()+1,10);
    }
    //std::cout<<keyValue<<endl;
    return keyValue;
}

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
    ifstream input("in.txt");
    bool flag = false;
    std::string concatString = "";
    bool validateVal = false;
    std::string value ="";
    for (std::string line; getline(input, line);)
    {
        if (line.length() != 0)
        {
            concatString = concatString + line;
        }
        else if (line.length() == 0)
        {
            for (int i=0; i<7; i++)
            {
                if (concatString.find(passports[i]) != std::string::npos)
                {
                    value = getValue(concatString, passports[i]);
                    //cout << value << endl;
                    if (validateValue(passports[i], value) == true)
                    {
                        flag = true;
                    }
                }
            }
            if (flag == false)
            {
                count++;
                std::cout << count << endl;
            }
                flag = false;
                concatString = "";
        }
    }
    return 0;
}