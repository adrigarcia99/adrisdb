#include <iostream>
#include <fstream>
#include "database/util/file.h"

void File::read()
{
    std::cout << "Trying to read from file: " << File::m_path << '\n';
    
    std::string line {};
    std::ifstream my_file;
    my_file.open(this->m_path);
    if (my_file.is_open())
    {
        while (std::getline(my_file, line))
        {
            std::cout << line << '\n';
        }
        my_file.close();
    }
}

void File::write(std::string content)
{
    std::cout << "Trying to write: " << content << '\n';
    std::ofstream my_file;
    my_file.open(this->m_path);
    my_file << content + '\n';
    my_file.close();
}

void File::loadFile()
{
    std::cout << "Enter your file path" << '\n';
    std::string filepath {};
    std:: cin >> filepath;
}
