#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <windows.h>
#include <vector>

#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFile {
    const string USERS_FILENAME;

public:
    UsersFile(string filenameWithUsers) : USERS_FILENAME(filenameWithUsers) {};
    void addUserToFile(User& user);
    vector <User> loadUsersFromFile();
    void saveNewDataToFile(User& user);
};

#endif
