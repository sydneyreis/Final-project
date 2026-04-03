#ifndef USERPROFILE_H
#define USERPROFILE_H

#include "Closet.h"
#include <string>

using namespace std;

class UserProfile {
public:
    UserProfile();
    UserProfile(string username, string zipCode);

    bool login(const string& username, const string& password);
    void logout();
    string getLocation();
    Closet& getCloset();
    void updateProfile();
    string getUsername();
private:
    string username;
    string zipCode;
    string password;
    Closet closet;

    void saveToFile();
    bool loadFromFile();
};

#endif