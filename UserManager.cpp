#include "UserManager.h"

void UserManager::registerUser() {
    User user = enterNewUserDetails();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "The account has been created." << endl << endl;
    system("pause");
}

User UserManager::enterNewUserDetails() {
    User user;
    string login = "", password = "", name = "", surname = "";

    user.setUserId(getNewUserId());

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (ifLoginExist(user.getLogin()));

    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    cout << "Enter name: ";
    cin >> name;
    user.setName(name);

    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::ifLoginExist(string login) {
    for(auto user : users) {
        if(user.getLogin() == login) {
            cout << endl << "This login is taken." << endl;
            return true;
        }
    }
    return false;
}

void  UserManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    cin >> login;

    for(auto user : users) {
        if(user.getLogin() == login) {
            for (int numberOfAttemps = 3; numberOfAttemps > 0; numberOfAttemps--) {
                cout << "Enter password: ";
                cin >> password;
                if(user.getPassword() == password) {
                    loggedInUserId = user.getUserId();
                    cout << "You have successfully logged in.";
                    Sleep(1500);
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times." << endl;
            Sleep(1700);
            return;
        }
    }
    cout << "User with that login doesn't exist." << endl;
    Sleep(1700);
    return;
}

void UserManager::changePasswordOfLoggedInUser() {
    string newPassword = "";
    User userWithNewPassword;

    cout << "Enter new password: ";
    cin >> newPassword;

    for(size_t i = 0; i < users.size(); i++) {
        if(users[i].getUserId() == loggedInUserId) {
            users[i].setPassword(newPassword);
            userWithNewPassword = users[i];
            cout << "Password has been changed." << endl << endl;
            system("pause");
            break;
        }
    }
    usersFile.saveNewDataToFile(userWithNewPassword);
}

void UserManager::logOutUser() {
    loggedInUserId = 0;
    cout << "You have been logged out." << endl;
    system("pause");
}

bool UserManager::ifUserIsLoggedIn() {
    return (loggedInUserId > 0) ? true :  false;
}

int UserManager::getLoggedUserId() {
    return loggedInUserId;
}
