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
    }
    else{
        string singleUserData = "";
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
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

void UsersFile::saveAllUsersToFile() {

}
