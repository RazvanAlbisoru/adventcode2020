#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

int count_letters(std::string line, char letter, std::size_t pos)
{
    std::size_t countedLetters = 0;
    for (int i=pos; i<line.length();i++)
    {
        if (line[i] == letter)
        {
            countedLetters++;
        }
    }
    return countedLetters;
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
    int goodpassCount = 0;
    char letter;
    std::size_t pos=0;
    std::size_t countLetters=0;
    int min = 0;
    int max = 0;
    for(std::string line; std::getline(input, line);)
    {
        letter = getRange_letter(line, &min, &max);
        pos = line.find(":");
        countLetters = count_letters(line, letter, pos);
        std::cout<<"Min: " << min << std::endl;
        std::cout<<countLetters << std::endl;
        std::cout<<"Max: " << max << std::endl;
        if (countLetters >= min && countLetters <= max)
        {
            goodpassCount++;
        }
    }
    std::cout << goodpassCount << std::endl;
}