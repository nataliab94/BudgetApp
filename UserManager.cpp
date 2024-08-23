#include "UserManager.h"
#include "User.h"


using namespace std;

void UserManager::registerUser()
{
    User user = enterUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "The account has been successfully created" << endl << endl;
    system("pause");
}

User UserManager::enterUserData()
{
    User user;

    cout << "Registering new user" << endl << "--- --- --- ---" << endl;
    user.id = (userFile.getLastUserId() + 1);
    cout << "Enter your first name: ";
    user.firstName = Utils::readLine();
    cout << "Enter your last name: ";
    user.lastName = Utils::readLine();
    do
    {
        cout << "Enter your login: ";
        user.login = Utils::readLine();
    }
    while(checkIfLoginExist(user.login)==true);
    cout << "Enter your password: ";
    user.password = Utils:: readLine();

    return user;
}

bool UserManager::checkIfLoginExist(const string &login)
{

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].login == login)
        {
            cout << endl << "Privided login exist." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser()
{
    string loginToCheck = "", passwordToCheck = "";

     cout << "Logging in" << endl << "--- --- --- ---" << endl;

    cout << endl << "Enter your login: ";
    loginToCheck = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr ->login == loginToCheck)
        {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--)
            {
                cout << "Enter password. Number of trials : " << numberOfTrials << ": ";
                passwordToCheck = Utils::readLine();

                if (itr -> password == passwordToCheck)
                {
                    loggedUserId = itr -> id;
                    cout << endl << "You are logged." << endl << endl;
                    cout << "Press any button to continue." << endl;
                    getch();
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times." << endl;
            cout << "Press any button to continue." << endl;
            getch();
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    cout << "Press any button to continue." << endl;
    getch();
    return;
}

void UserManager::changeUserPassword()
{
    User userToUpdate;
    cout << "Enter new password: ";

    string newPassword;

    newPassword = Utils::readLine();

    for (size_t i = 0; i < users.size(); i++)
    {
        if (loggedUserId == users[i].id)
        {
            users[i].password = newPassword;

            userToUpdate.id = users[i].id;
            userToUpdate.firstName = users[i].firstName;
            userToUpdate.lastName = users[i].lastName;
            userToUpdate.login = users[i].login;
            userToUpdate.password = users[i].password;

            userFile.changePasswordInFile(userToUpdate);

            cout << "Your password has been changed" << endl;

            break;
        }
    }

    return;
}
void UserManager::logOutUser()
{
    cout << "Logging out" << endl << "--- --- --- ---" << endl;

    loggedUserId = 0;

}


bool UserManager::isUserLoggedIn()
{
   if (loggedUserId > 0)
        return true;
    else
        return false;

}
int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::loadUsers()
{
    users = userFile.loadUsersFromFile();
}

