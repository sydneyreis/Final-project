#ifndef AUTHSYSTEM_H
#define AUTHSYSTEM_H

#include "UserProfile.h"

class AuthSystem {
public:
    // Returns true and opens profile if successful
    bool showLoginMenu(UserProfile& profile);

private:
    bool handleLogin(UserProfile& profile);
    bool handleSignup(UserProfile& profile);
};

#endif