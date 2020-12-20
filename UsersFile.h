#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile
{
    const string FILENAME_WITH_USERS;
    User getUserData();
public:
    UsersFile(string filename) : XmlFile(filename){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile();
};


#endif
