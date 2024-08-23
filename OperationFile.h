#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>
#include "Operation.h"
#include "Markup.h"
#include "File.h"



using namespace std;

class OperationFile : public File
{
     string fileName;

public:

     OperationFile (string fileName) : File(fileName)
    {

    }



    vector<Operation>loadOperationsFromFile (const int loggedUserId);
    void addOperationToFile (const Operation &operation);

    };

#endif

