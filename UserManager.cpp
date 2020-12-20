#include "UserManager.h"

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login already exists!" << endl;
            return true;
        }
    }
    return false;
}

User UserManager::enterNewUserData()
{
    User user;

    user.setId(getIdOfNewUser());

    string name,surname,login;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        user.setName(name);
        cout << "Enter surname: ";
        cin >> surname;
        user.setSurname(surname);
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::userRegistration()
{
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Account has been estabilished successfuly." << endl << endl;
    system("pause");
}

int UserManager::userLogging()
{

}

void UserManager::changePasswordOfLoggedInUser()
{

}

int UserManager::getIdOfLoggedInUser()
{

}

int UserManager::setIdOfLoggedInUser()
{

}

bool UserManager::isUserLoggedIn()
{

}
