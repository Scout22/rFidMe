#include "User.h"



using namespace std;
User::User()
{
	phone_number = 0;
	student_id = 0;
	registred_user = false;
}

User::~User()
{
}

//Set the user RFID 
bool User::set_rfid_id(uint64_t id)
{
	rfid_id = id;
	return true;
}

//Get the user RFID
uint64_t User::get_rfid_id()
{
	return rfid_id;
}

//Set the user email and check if it is a valid email
bool User::set_email(string email) {
	if (email.find('@') < email.npos && email.find('.') > email.find('@') && email.find('.') < email.npos) {
		email_adress = email;
		return true;
	}
	return false;
}

//Get the user email
string User::get_email() {
	return email_adress;
}

//Set the user first name
bool User::set_first_name(string name)
{
	first_name = name;
	return true;
}

//Get the user first name
string User::get_first_name() {
	registred_user = true;
	return first_name;
}

//Set the user last name
bool User::set_last_name(string name)
{
	last_name = name;
	return true;
}

//Get the user last name
string User::get_last_name() {
	return last_name;
}

//Set the member type
bool User::set_member_type(unsigned int mtype)
{
	member_type = mtype;
	return true;
}

//Get member type
unsigned int User::get_member_type() {
	return member_type;
}

//Set the current project of the user
bool User::set_current_project_id(uint64_t id)
{
	current_project = id;
	return false;
}

//Get the id of the project the user is working on
uint64_t User::get_current_project_id()
{
	return current_project;
}

//Set the phone number and check if it is valid
bool User::set_phone_number(unsigned int num)
{
	if (num < 0100000000) {
		return false;
	}
	phone_number = num;
	return true;
}

//Get the user phone number
uint64_t User::get_phone_number() {
	return phone_number;
}

//Set the student number
bool User::set_student_id(unsigned int sid)
{
	student_id = sid;
	return true;
}

//Get the user student number
uint64_t User::get_student_id() {
	return student_id;
}

//Set the gender (M)ale or (F)emale, valid answer are M and F
bool User::set_gender(char mf)
{
	if (mf == 'M' || mf == 'F') {
		gender = mf;
		return true;
	}
	return false;
}

//Get the user gender (M)ale or (F)emale
char User::get_gender() {
	return gender;
}

//Set the registration date
bool User::set_registered_date(string reg_date)
{
	register_date = reg_date;
	return true;
}

//Get the user registration date
string User::get_registered_date() {
	return register_date;
}

//Set the user authorization
bool User::set_authorization(uint64_t auth)
{
	authorization = auth;
	return true;
}

//Get the user authorization
uint64_t User::get_authorization() {
	return authorization;
}

bool User::is_authorized(uint64_t auth_request) {
	return (authorization&auth_request);
}

//Mark the user as registered in the database
void User::setRegistred(bool reg) {
	registred_user = reg;
}

//Check if the user is registered in the database
bool User::isRegistred() {
	return registred_user;
}











