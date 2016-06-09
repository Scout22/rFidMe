#include "Text_UI.h"

using namespace std;

bool set_email(User &user) {
	string email;
	cout << "Quel est votre adresse email?" << endl;
	cin >> email;
	if (user.set_email(email)) {
		return true;
	}
	return false;
}
bool set_first_name(User &user) {
	string name;
	cout << "Quel est votre prenom?" << endl;
	cin >> name;
	if (name.size() > 0) {
		std::transform(std::begin(name), std::end(name), std::begin(name), std::tolower);
		if (!name.empty()) {
			name[0] = std::toupper(name[0]);
		}
		user.set_first_name(name);
		return true;
	}
	return false;
}
bool set_last_name(User &user) {
	string name;
	cout << "Quel est votre nom de famille?" << endl;
	cin >> name;
	if (name.size() > 0) {
		std::transform(std::begin(name), std::end(name), std::begin(name), std::tolower);
		if (!name.empty()) {
			name[0] = std::toupper(name[0]);
		}
		user.set_last_name(name);
		return true;
	}
	return false;

}
bool set_member_type(User &user) {
	int mtype = -1;
	cout << "Quel est votre status de membre?" << endl << "(1) Membre etudiant \t (2) Membre staff \t (3) Membre exterieur" << endl;
	cin >> mtype;
	if (mtype > 0 && mtype<4) {
		user.set_member_type(mtype);
		return true;
	}
	return false;
}
bool set_current_project_id(User &user) {
	user.set_current_project_id(0);
	return true;
}
bool set_phone_number(User &user) {
	int64_t phone = -1;
	string phone_text;
	cout << "Quel est votre numero de telephone?" << endl;
	cin >> phone_text;
	char *endptr;
	phone = strtoll(phone_text.c_str(), &endptr,10);
	if (phone > -1 && user.set_phone_number(phone)) {
		return true;
	}
	return false;
}
bool set_student_id(User &user) {
	int64_t student_id = -1;
	string student_id_text;
	cout << "Quel est votre numero d'etudiant?" << endl;

	cin >> student_id_text;
	char *endptr;
	student_id = strtoll(student_id_text.c_str(), &endptr, 10);
	if (student_id > -1) {
		user.set_student_id(student_id);
		return true;
	}
	return false;

}
bool set_gender(User &user) {
	int sex;
	cout << "Etes vous un (1)homme ou une (2)femme?" << endl;
	cin >> sex;
	if (sex == 1 || sex == 2) {
		if (sex == 1) {
			user.set_gender('M');
		}
		else {
			user.set_gender('F');
		}
		return true;
	}
	return false;
}
bool set_authorization(User &user) {
	user.set_authorization(0b11110011);
	return true;
}

User create_new_user(uint64_t rfid) {
	User newUser;
	newUser.set_rfid_id(rfid);

	while (!set_first_name(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_last_name(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_email(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}
	while (!set_gender(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_phone_number(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_student_id(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_member_type(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_current_project_id(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}

	while (!set_authorization(newUser)) {
		cout << "Erreur lors de la saisie" << endl;
	}
	return newUser;
}

