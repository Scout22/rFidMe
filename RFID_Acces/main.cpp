#include "RFID_reader.h"
#include "mysql_query.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include "User.h"
#include "Text_UI.h"


using namespace std;
int main() {
	RFID_READER::RFID_reader pn532;
	RFID_card my_card;
	if (pn532.Reader_Is_Ready()) {
		while (1) {
			cout << "Lecteur pret, veuillez presenter une carte" << endl;
			if (pn532.read_card(my_card)) {
				printf("UID:%I64x\n", my_card.UID);
				User myUser = get_user_from_id(my_card.UID);
				if (myUser.isRegistred()) {
					std::cout << "Bienvenu \nPrenom: " << myUser.get_first_name() << "\nNom: " << myUser.get_last_name() << "\nEmail: " << myUser.get_email() << std::endl;
					log_user_access(myUser, "Beta");
				}
				else {
					char key;
					cout << "Utilisateur inconnu!!" << endl;
					cout << "Appuyer sur la touche c pour ajouter cette utilisateur à la base de donnée sinon sur q"<<endl;
					cin >> key;
					if (key == 'c') {
						User new_user=create_new_user(my_card.UID);
						add_user_database(new_user);
						cout << "Utilisateur correctement ajouter à la base de donnée!" << endl;
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}
	return 0;
}