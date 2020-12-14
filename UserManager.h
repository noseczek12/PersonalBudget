#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class UserManager {
    int idOfLoggedinUser;
    vector <User> users;
    //UsersFile usersFile
    //AuxiliaryMethods auxiliaryMethods;
    bool doesLoginExist();
    User enterNewUserData();
    int getIdOfNewUser();
public:
    UserManager(){};
    void userRegistration();
    int userLogging();
    void changePasswordOfLoggedInUser();
    int getIdOfLoggedInUser();
    int setIdOfLoggedInUser();
    bool isUserLoggedIn();
};


#endif
