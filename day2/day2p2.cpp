
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

void retrieve_pos_letters(std::string line, char letter, std::size_t pos, std::vector<int>* positions)
{
    for (int i=pos; i<line.length();i++)
    {
        if (line[i] == letter)
        {
            positions->push_back(i-pos-1);
        }
    }
}

char getRange_letter (std::string line,int* min, int* max)
{
    std::size_t posMin = line.find("-");
    std::size_t posMax = line.find(" ");
    std::string minimum = "";
    std::string maximum = "";
    char letter;
    for (int i=0;i<posMin;i++)
    {
        minimum = minimum + line[i];
    }
    for (int i=posMin+1;i<posMax;i++)
    {
        maximum = maximum + line[i];
    }
    *min = std::stoi(minimum);
    *max = std::stoi(maximum);
    letter = line.at(posMax+1);
    return letter;
}

int main()
{
    std::ifstream input("input.txt");
    bool flag_min = false;
    bool flag_max = false;
    int goodpassCount = 0;
    char letter;
    int min = 0;
    int max = 0;
    std::size_t pos=0;
    std::vector<int> positions;
    for(std::string line; std::getline(input, line);)
    {
        
        letter = getRange_letter(line, &min, &max);
        pos = line.find(":");
        retrieve_pos_letters(line, letter, pos, &positions);
        // std::cout<<"Line: " << line << std::endl;
        // std::cout<<"Min and Max: " << min << " " << max << std::endl;
        for (int i=0;i<positions.size();i++)
        {
            // std::cout<<positions[i]<<std::endl;
            if (positions[i] == min)
            {
                // std::cout<<"min: "<<positions[i]<<std::endl;
                flag_min = true;
            }
            else if (positions[i] == max)
            {
                // std::cout<<"max: "<<positions[i]<<std::endl;
                flag_max = true;
            }
        }
        if (flag_min!=flag_max)
        {
            goodpassCount++;
            // std::cout<<"/INCREASED/: " << goodpassCount << std::endl;
        }
        positions.clear();
        flag_min = false;
        flag_max = false;
    }
    std::cout << goodpassCount << std::endl;
}
