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

}

void UsersFile::saveAllUsersToFile() {

}
