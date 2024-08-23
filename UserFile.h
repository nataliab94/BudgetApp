#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
# include <vector>

#include "File.h"
#include "User.h"



using namespace std;

class UserFile : public File
{
     int lastUserId = 0;

public:

    UserFile (string nameOfFile): File (nameOfFile){}

    vector <User> loadUsersFromFile ();
    void addUserToFile (const User &user);
    void changePasswordInFile(User userToUpdate);
    int getLastUserId();



};
#endif
