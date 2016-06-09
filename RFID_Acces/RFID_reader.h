#ifndef RFID_READER
#define RFID_READER
#include "RFID_card.h"
#include <nfc/nfc.h>
#include <string>


class RFID_reader
{
public:
	RFID_reader();
	~RFID_reader();
	bool Reader_Is_Ready();
private:
	bool setup_nfc_config(std::string serial_port);
	nfc_device* pnd;
	nfc_target nt;
	nfc_context* context;
	nfc_modulation nmMifare;
	bool isReady;
public:
	bool read_card(RFID_card& my_card);
	static uint64_t hex_to_uint64_t(const uint8_t * data, const size_t sizeData);
};


#endif