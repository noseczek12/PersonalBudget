#include "UsersFile.h"

User UsersFile::getUserData() {

}

void UsersFile::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Users" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "UserId", AuxiliaryMethods::convertIntToString(user.getId()));
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );
    xml.Save(getFileName());
}

vector <User> UsersFile::loadUsersFromFile() {
    User user;
    vector<User> users;
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        cout << "Can't open file. File doesn't exist." << endl;
        system("pause");
    } else {
        string singleUserData = "";
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            singleUserData = xml.GetData();
            user.setId(atoi(singleUserData.c_str()));
            xml.FindElem("Name");
            singleUserData = xml.GetData();
            user.setName(singleUserData);
            xml.FindElem("Surname");
            singleUserData = xml.GetData();
            user.setSurname(singleUserData);
            xml.FindElem("Login");
            singleUserData = xml.GetData();
            user.setLogin(singleUserData);
            xml.FindElem("Password");
            singleUserData = xml.GetData();
            user.setPassword(singleUserData);
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}

void UsersFile::saveAllUsersToFile(vector <User> users) {
    CMarkup xmlFile;
    remove("Users.xml");
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xmlFile.Load(getFileName());
        if(!xmlFile.FindElem("Users")) {
            xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xmlFile.AddElem("Users");
        }
        xmlFile.IntoElem();
        xmlFile.AddElem("User");
        xmlFile.IntoElem();
        xmlFile.AddElem("UserId", to_string(itr -> getId()));
        xmlFile.AddElem("Name", itr -> getName());
        xmlFile.AddElem("Surname", itr -> getSurname());
        xmlFile.AddElem("Login", itr -> getLogin());
        xmlFile.AddElem("Password", itr -> getPassword());
        xmlFile.OutOfElem();
        xmlFile.Save(getFileName());
    }
}
