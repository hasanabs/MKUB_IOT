#ifndef MKUB_IOT_H
#define MKUB_IOT_H

#include "Arduino.h"
#include "String.h"
#include "SoftwareSerial.h"

class MKUB_IOT { 
public:
	MKUB_IOT();
	~MKUB_IOT();
	void baud(int nilai);
	void konek(String ssid, String password);
    void kirim(String apiKeyKirim, int field, String nilai);
	String Ambil(String ID_Chanel, int field, String apiKeyAmbil);
	void GantiBaudESP(int baudrate);
};

#endif