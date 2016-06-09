#pragma once
#include <string>
#include "User.h"

#define USER "RFID"
#define PASSWORD_DEF "c@kerfid"
#define DATABASE_ADRESS "tcp://37.187.4.166:3306"
#define DATABASE "RFID"

//TODO Implement a configuration function and read config from a file
User get_user_from_id(uint64_t id);
bool log_user_access(User logged_user, std::string location);
bool add_user_database(User newUser);
std::string get_project_from_project_id(uint64_t project_id);
