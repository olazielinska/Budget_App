#include "UsersFile.h"

void UsersFile::addUserToFile(User &user) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(USERS_FILENAME);

    if(!fileExists) {
        xmlFile.AddElem("Users");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("User");
    xmlFile.IntoElem();
    xmlFile.AddElem("UserId", user.getUserId());
    xmlFile.AddElem("Login", user.getLogin());
    xmlFile.AddElem("Password", user.getPassword());
    xmlFile.AddElem("Name", user.getName());
    xmlFile.AddElem("Surname", user.getSurname());
    xmlFile.Save(USERS_FILENAME);

}

vector <User> UsersFile::loadUsersFromFile() {
    CMarkup xmlFile;
    User user;
    vector <User> users;

    xmlFile.Load(USERS_FILENAME);

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("User")) {
        xmlFile.IntoElem();
        xmlFile.FindElem("UserId");
        user.setUserId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.FindElem("Login");
        user.setLogin(xmlFile.GetData());
        xmlFile.FindElem("Password");
        user.setPassword(xmlFile.GetData());
        xmlFile.FindElem("Name");
        user.setName(xmlFile.GetData());
        xmlFile.FindElem("Surname");
        user.setSurname(xmlFile.GetData());
        users.push_back(user);
        xmlFile.OutOfElem();
    }
    return users;
}

void UsersFile::saveNewDataToFile(User& user) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(USERS_FILENAME);

    if(fileExists) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while(xmlFile.FindElem("User")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("UserId");
            if(user.getUserId() == atoi(MCD_2PCSZ(xmlFile.GetData()))) {
                xmlFile.FindElem("Password");
                xmlFile.RemoveElem();
                xmlFile.AddElem("Password", user.getPassword());
                break;
            }
        }
        xmlFile.Save(USERS_FILENAME);
    }
}
