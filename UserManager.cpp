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
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = auxiliaryMethods.loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int retryCount = 3; retryCount > 0; retryCount--)
            {
                cout << "Enter password. Attempts remaining: " << retryCount << ": ";
                password = auxiliaryMethods.loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    system("pause");
                    setIdOfLoggedInUser(itr->getId());
                    return idOfLoggedinUser;
                }
            }
            cout << "You have entered 3 times wrong password." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with entered login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changePasswordOfLoggedInUser()
{

}

int UserManager::getIdOfLoggedInUser()
{
    return idOfLoggedinUser;
}

void UserManager::setIdOfLoggedInUser(int newId)
{
    idOfLoggedinUser=newId;
}

bool UserManager::isUserLoggedIn()
{
    if(idOfLoggedinUser > 0)
        return true;
    else
        return false;
}

void UserManager::userLogout()
{
    idOfLoggedinUser = 0;
}

