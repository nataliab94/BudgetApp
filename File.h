#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>

#include "Markup.h"


using namespace std;

class File
{
    const string FILE_NAME;




public:

    File(string nameOfFile) : FILE_NAME(nameOfFile) {}

    int lastId = 0;
    string getFileName();
    int getLastId();
};

#endif
