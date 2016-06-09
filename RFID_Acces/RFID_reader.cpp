#include "RFID_reader.h"
#include <iostream>
#include <ostream>


RFID_reader::RFID_reader()
{
	isReady = true;
	setup_nfc_config("COM4");
	nfc_init(&context);
	if (context == NULL) {
		printf("Unable to init libnfc (malloc)\n");
		isReady = false;
	}
	else {
		int i = 0;
		do {
			i++;
			pnd = nfc_open(context, NULL);
		} while (i < 10 && pnd== NULL);
		if (pnd == NULL) {
			printf("ERROR: %s\n", "Impossible de se connecter au lecteur NFC.");
			isReady = false;
		}
		else if (nfc_initiator_init(pnd) < 0) {
			nfc_perror(pnd, "nfc_initiator_init");
			isReady = false;
		}
	}
	nmMifare.nmt = NMT_ISO14443A;
	nmMifare.nbr = NBR_106;
}


RFID_reader::~RFID_reader()
{
	isReady = false;
	nfc_close(pnd);
	nfc_exit(context);
}

//Verifie si le lecteur est pret à lire la carte
bool RFID_reader::Reader_Is_Ready()
{
	return isReady;
}

bool RFID_reader::setup_nfc_config(std::string serial_port)
{/*
	std::ofstream myfile;
	myfile.open("c:\nfclib\libnfc2.conf");
	myfile << "device.name = \"microBuilder.eu\"\ndevice.connstring = \"pn532_uart:"<<serial_port<<"COM4:115200\"\n";
	myfile.close();*/
	return false;
}

//Fonction permettant de lire une carte rfid
//Retourne vrai si la lecture reussie
//my_card est la carte a lire
bool RFID_reader::read_card(RFID_card& my_card)
{
	if (isReady) {
		if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0) {
			my_card.ATQA = hex_to_uint64_t(nt.nti.nai.abtAtqa, 2);
			my_card.UID = hex_to_uint64_t(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);
			my_card.SAK = hex_to_uint64_t(&nt.nti.nai.btSak, 1);
			if (nt.nti.nai.szAtsLen) {
				my_card.ATS = hex_to_uint64_t(nt.nti.nai.abtAts, nt.nti.nai.szAtsLen);
			}
			return true;
		}
	}
	
	return false;
}

//Fonction permettant de convertir une chaine de caractere hexadecimale en entier
uint64_t RFID_reader::hex_to_uint64_t(const uint8_t * data, const size_t sizeData)
{
	//On se limite a 8 caracteres hexadecimal max afin d'eviter un debordement
	size_t maxData = sizeData;
	if (maxData > 8) {
		maxData = 8;
	}
	uint64_t res = 0;
	for (unsigned int i = 0; i < maxData; i++) {
		res = (res << 8) + data[i];
	}

	return res;
}
