#include "UserFile.h"

void UserFile::addUserToFile(const User &user)
{
    CMarkup userFile;

    if (!userFile.Load(getFileName()))
    {
        userFile.AddElem("Users");
        userFile.IntoElem();
        userFile.AddElem("User");
        userFile.IntoElem();
        userFile.AddElem("id",to_string(user.id));
        userFile.AddElem("firstName",user.firstName);
        userFile.AddElem("lastName",user.lastName);
        userFile.AddElem("login",user.login);
        userFile.AddElem("password",user.password);
        userFile.OutOfElem();
        userFile.OutOfElem();
        userFile.Save(getFileName());
    }

    else
    {
        userFile.FindElem("Users");
        userFile.IntoElem();
        while(userFile.FindElem("User"))
        {

        }
        userFile.AddElem("User");
        userFile.IntoElem();
        userFile.AddElem("id",to_string(user.id));
        userFile.AddElem("firstName",user.firstName);
        userFile.AddElem("lastName",user.lastName);
        userFile.AddElem("login",user.login);
        userFile.AddElem("password",user.password);
        userFile.OutOfElem();
        userFile.OutOfElem();
        userFile.Save(getFileName());
    }

    lastUserId++;
}
vector <User> UserFile::loadUsersFromFile()
{
    CMarkup userFile;
    MCD_STR strXML;

    User user;
    vector <User> users;

    userFile.Load(getFileName());

    userFile.FindElem("Users");
    userFile.IntoElem();

    while(userFile.FindElem("User"))
    {
        userFile.IntoElem();

        userFile.FindElem("id");
        strXML = userFile.GetData();
        user.id = stoi(strXML);
        lastUserId = stoi(strXML);

        userFile.FindElem("firstName");
        strXML = userFile.GetData();
        user.firstName = strXML;

        userFile.FindElem("lastName");
        strXML = userFile.GetData();
        user.lastName = strXML;

        userFile.FindElem("login");
        strXML = userFile.GetData();
        user.login = strXML;

        userFile.FindElem("password");
        strXML = userFile.GetData();
        user.password = strXML;

        userFile.OutOfElem();

        users.push_back(user);
    }

    return users;
}


int UserFile::getLastUserId()
{
    return lastUserId;
}

 void UserFile::changePasswordInFile(User userToUpdate)

{
    CMarkup userFile;
    MCD_STR strXML;

    userFile.Load(getFileName());

    userFile.FindElem("Users");
    userFile.IntoElem();

    while(userFile.FindElem("User"))
    {
        userFile.IntoElem();
        userFile.FindElem("id");
        strXML = userFile.GetData();

        if (to_string(userToUpdate.id) == strXML)
        {
            userFile.FindElem("firstName");
            userFile.SetData(userToUpdate.firstName);
            userFile.FindElem("lastName");
            userFile.SetData(userToUpdate.lastName);
            userFile.FindElem("login");
            userFile.SetData(userToUpdate.login);
            userFile.FindElem("password");
            userFile.SetData(userToUpdate.password);

            userFile.Save(getFileName());

            break;
        }

        userFile.OutOfElem();
    }
}


