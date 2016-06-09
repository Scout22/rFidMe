#pragma once
#include <string>
class User
{
public:
	User();
	~User();
	bool set_rfid_id(uint64_t id);
	bool set_email(std::string email);
	bool set_first_name(std::string name);
	bool set_last_name(std::string name);
	bool set_member_type(unsigned int mtype);
	bool set_current_project_id(uint64_t id);
	bool set_phone_number(unsigned int num);
	bool set_student_id(unsigned int sid);
	bool set_gender(char mf);
	bool set_registered_date(std::string reg_date);
	bool set_authorization(uint64_t auth);

    //TODO ADD getters and convert date time to another structure
	uint64_t get_rfid_id();
	std::string get_email();
	std::string get_first_name();
	std::string get_last_name();
	unsigned int get_member_type();
	uint64_t get_current_project_id();
	uint64_t get_phone_number();
	uint64_t get_student_id();
	char get_gender();
	std::string get_registered_date();
	uint64_t get_authorization();
	bool is_authorized(uint64_t);
	
	
	bool isRegistred();
	void setRegistred(bool reg);
private:
	bool registred_user;
	uint64_t rfid_id;
	std::string first_name;
	std::string last_name;
	std::string register_date;
	std::string email_adress;
	uint64_t current_project;
	uint64_t authorization;
	uint64_t phone_number;
	uint64_t student_id;
	unsigned int member_type;
	char gender;
	
public:
	
};

