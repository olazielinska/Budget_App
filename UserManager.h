#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {

    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserDetails();
    int getNewUserId();
    bool ifLoginExist(string login);
public:
    UserManager(string filenameWithUsers) : usersFile(filenameWithUsers) {
        loggedInUserId = 0;
        users = usersFile.loadUsersFromFile();
    };

    void registerUser();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOutUser();
    bool ifUserIsLoggedIn();
    int getLoggedUserId();
};

#endif
