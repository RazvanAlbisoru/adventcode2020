#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    std::ifstream input ("input.txt");
    std::vector<int> numbers;
    for (std::string line; std::getline(input, line);)
    {
        numbers.push_back(std::stoi(line));
        //std::cout << std::stoi(line) << std::endl;
    }
    for (int i=0;i<numbers.size();i++)
    {
        for (int j=0;j<numbers.size();j++)
        {
            for (int z=0;z<numbers.size();z++)
            {
                if (numbers[i] + numbers[j] + numbers[z] == 2020)
                {
                    std::cout<<numbers[i] * numbers[j] * numbers[z]<<std::endl;
                }
            }
        }
    }
    return 0;
}