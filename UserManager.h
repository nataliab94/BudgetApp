#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
# include <vector>
# include <conio.h>

#include "User.h"
#include "Utils.h"
#include "UserFile.h"



using namespace std;

class UserManager
{

    int loggedUserId = 0;
    vector <User> users;

    UserFile userFile;

    bool checkIfLoginExist(const string &login);
    User enterUserData();
    void findUserByLogin(const string &login, vector <User>::iterator &itr);
    void findUserById(vector <User>::iterator& itr);



public:

   UserManager(string nameOfFile) : userFile(nameOfFile) {}

    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logOutUser();
    bool isUserLoggedIn();
    int getLoggedUserId();
    void loadUsers();

};
#endif
