
#include "retile_las.h"
#include <iostream>
#include <string>

void usage(char *argv)
{
    std::cout << "Usage:" << std::endl;
    std::cout << argv << " [InputDirectory] [OutputDirectory] [size_X] [size_Y] " << std::endl; 
}





int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        usage(argv[0]);
        return 1;
    }

    std::string inLasDir = argv[1];
    std::string outLasDir = argv[2];
    const int numX = std::stoi(argv[3]);
    const int numY = std::stoi(argv[4]);

    mm::Retile *retile = new mm::Retile;
    retile->setInputDir(inLasDir);
    retile->setOutputDir(outLasDir);
    retile->setRetileCount(numX, numY);
    retile->retileByCount();

    if (retile)
    {
        delete retile;
        retile = nullptr;
    }
    return 0;
}


