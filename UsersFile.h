#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include "User.h"
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class UsersFile {
    const string FILENAME_WITH_USERS;
    User getUserData();
public:
    UsersFile(){};
    void addUserToFile();
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile();
};


#endif
