#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int idOfLoggedinUser;
    vector <User> users;
    UsersFile usersFile;
    AuxiliaryMethods auxiliaryMethods;
    bool doesLoginExist(string login);
    User enterNewUserData();
    int getIdOfNewUser();
public:
    UserManager(string filenameWithUsers) : usersFile(filenameWithUsers){};
    void userRegistration();
    int userLogging();
    void changePasswordOfLoggedInUser();
    int getIdOfLoggedInUser();
    int setIdOfLoggedInUser();
    bool isUserLoggedIn();
};


#endif
