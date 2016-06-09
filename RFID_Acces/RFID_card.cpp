#include "RFID_card.h"
#include <stdio.h>



RFID_card::RFID_card()
{
	ATQA = 0;
	UID = 0;
	SAK = 0;
	ATS = 0;
	sprintf(type,"ISO14443A\0");
}


RFID_card::~RFID_card()
{
}
