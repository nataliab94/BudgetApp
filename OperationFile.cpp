#include "OperationFile.h"

using namespace std;

void OperationFile::addOperationToFile (const Operation &operation)
{
    CMarkup workingFile;

    workingFile.ResetPos();

    if (!workingFile.Load(getFileName()))
    {
        workingFile.AddElem("Root");
        workingFile.IntoElem();
        workingFile.AddElem("Operation");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(operation.id));
        workingFile.AddElem("userId",to_string(operation.userId));
        workingFile.AddElem("date",operation.date);
        workingFile.AddElem("item",operation.item);
        workingFile.AddElem("amount",to_string(operation.amount));
        workingFile.ResetPos();
        workingFile.Save(getFileName());
    }

    else
    {
        workingFile.FindElem("Root");
        workingFile.IntoElem();

        while(workingFile.FindElem("Operation"))
        {

        }
        workingFile.AddElem("Operation");
        workingFile.IntoElem();
        workingFile.AddElem("id",to_string(operation.id));
        workingFile.AddElem("userId",to_string(operation.userId));
        workingFile.AddElem("date",operation.date);
        workingFile.AddElem("item",operation.item);
        workingFile.AddElem("amount",to_string(operation.amount));
        workingFile.ResetPos();
        workingFile.Save(File::getFileName());
    }

    lastId++;
}

vector <Operation> OperationFile::loadOperationsFromFile(const int loggedUserId)
{
    vector <Operation> money;
    CMarkup workingFile;
    MCD_STR strXML;

    workingFile.Load(getFileName());

    workingFile.FindElem("Root");

    workingFile.IntoElem();

    while (workingFile.FindElem("Operation"))
    {
        workingFile.IntoElem();

        Operation operation;
        workingFile.FindElem("id");
        strXML = workingFile.GetData();
        operation.id = stoi(strXML);

        lastId = operation.id;

        workingFile.FindElem("userId");
        strXML = workingFile.GetData();
        operation.userId = stoi(strXML);

        if (operation.userId != loggedUserId)
        {
            workingFile.OutOfElem();
            continue;
        }

        workingFile.FindElem("date");
       strXML = workingFile.GetData();
       operation.date = stoi(strXML);


        workingFile.FindElem("item");
        strXML = workingFile.GetData();
        operation.item = strXML;

        workingFile.FindElem("amount");
        strXML = workingFile.GetData();
        operation.amount = stod(strXML);


        money.push_back(operation);
        workingFile.OutOfElem();
    }

    return money;
}

