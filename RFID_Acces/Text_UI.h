#ifndef TEXT_UI_H
#define TEXT_UI_H

#include "User.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool set_email(User &user);
bool set_first_name(User &user);
bool set_last_name(User &user);
bool set_member_type(User &user);
bool set_current_project_id(User &user);
bool set_phone_number(User &user);
bool set_student_id(User &user);
bool set_gender(User &user);
bool set_authorization(User &user);

User create_new_user(uint64_t rfid);


#endif // !TEXT_UI_H
