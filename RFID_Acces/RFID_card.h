#pragma once
#include <cstdint>
class RFID_card
{
public:
	RFID_card();
	~RFID_card();
	int64_t ATQA;
	int64_t UID;
	int64_t SAK;
	int64_t ATS;
	char type[255];
};

