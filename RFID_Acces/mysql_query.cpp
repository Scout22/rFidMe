#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "User.h"
#include "mysql_query.h"

using namespace std;

User get_user_from_id(uint64_t id)
{
	User myUser;
	myUser.set_rfid_id(id);
	
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect(DATABASE_ADRESS, USER, PASSWORD_DEF);
		/* Connect to the MySQL test database */
		con->setSchema(DATABASE);

		stmt = con->createStatement();
		char buff[255];
		sprintf(buff, "SELECT * FROM USERS WHERE rfid_id=%llu;", id);
		res = stmt->executeQuery(buff);
		
		if(res->next()) {
			myUser.set_last_name( res->getString("last_name"));
			myUser.set_first_name(res->getString("first_name"));
			myUser.set_email(res->getString("email"));
			myUser.set_gender(res->getString("sex").c_str()[0]);
			myUser.set_current_project_id(res->getInt("current_project_id"));
			myUser.set_student_id(res->getInt("student_id"));
			myUser.set_phone_number(res->getInt("phone_number"));
			myUser.set_registered_date(res->getString("register_date"));
			myUser.set_authorization(res->getUInt64("authorization"));
			myUser.setRegistred(true);
		}
		else {
			myUser.setRegistred(false);
		}
		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	return myUser;
}

bool log_user_access(User logged_user,string location) {
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect(DATABASE_ADRESS, USER, PASSWORD_DEF);
		/* Connect to the MySQL test database */
		con->setSchema(DATABASE);
		stmt = con->createStatement();
		char buff[500];
		sprintf(buff, "INSERT ACCESS_HISTORY (rfid_id,access_time,location,id_project) VALUES(%llu,NOW(),'%s','%llu');", logged_user.get_rfid_id(), location.c_str(), logged_user.get_current_project_id());
		stmt->execute(buff);
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}

	return true;

}

string get_project_from_project_id(uint64_t project_id) {
	string project_name = "unknow";
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect(DATABASE_ADRESS, USER, PASSWORD_DEF);
		/* Connect to the MySQL database */
		con->setSchema(DATABASE);

		stmt = con->createStatement();
		char buff[255];
		sprintf(buff, "SELECT * FROM PROJECT WHERE id_project=%llu;", project_id);
		res = stmt->executeQuery(buff);

		if (res->next()) {
			project_name = res->getString("project_name");
		}
		delete res;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	return project_name;
}

//TODO Complete this function
bool add_user_database(User newUser) {
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect(DATABASE_ADRESS, USER, PASSWORD_DEF);
		/* Connect to the MySQL test database */
		con->setSchema(DATABASE);
		stmt = con->createStatement();
		char buff[2048];
		sprintf(buff, "INSERT INTO USERS (rfid_id,student_id,phone_number,last_name,first_name,email,sex,register_date,member_type,authorization,current_project_id) VALUES(%llu, %llu, %llu, '%s', '%s', '%s', '%c', NOW(), %d, %llu, %d); ",newUser.get_rfid_id(), newUser.get_student_id(),newUser.get_phone_number(),newUser.get_last_name().c_str(),newUser.get_first_name().c_str(),newUser.get_email().c_str(),newUser.get_gender(),newUser.get_member_type(),newUser.get_authorization(),newUser.get_current_project_id());
		stmt->execute(buff);
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}

	return true;
}