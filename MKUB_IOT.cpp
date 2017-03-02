#include "MKUB_IOT.h"
#include "Arduino.h"
#include "String.h"
#include "SoftwareSerial.h"

SoftwareSerial MKUB_PIN_ESP(8, 9);

MKUB_IOT::MKUB_IOT(){
    //semacam fungsi void setup
}

MKUB_IOT::~MKUB_IOT(){

}

void MKUB_IOT::baud(int nilai){
	MKUB_PIN_ESP.begin(nilai);
	delay(200);
}

void MKUB_IOT::konek(String ssid, String password){
	String gabungKonek = "AT+CWJAP=\"";
	gabungKonek += ssid;
	gabungKonek += "\",\"";
	gabungKonek += password;
	gabungKonek += "\"";
	MKUB_PIN_ESP.println("AT+RST");
	delay(2000);
	MKUB_PIN_ESP.println("AT+CWMODE=3");
	delay(2000);
	MKUB_PIN_ESP.println(gabungKonek);
	delay(2000);
}

void MKUB_IOT::kirim(String apiKeyKirim, int field, String nilai){
	String HubungkanThingspeak = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80";
	MKUB_PIN_ESP.println(HubungkanThingspeak);
	delay(100);
	if (MKUB_PIN_ESP.find("ERROR"))
	{
	MKUB_PIN_ESP.println("Gagal konek ke server");
	return;
	}
	String Luncurkan = "GET /update?api_key=";
	Luncurkan += apiKeyKirim;
	Luncurkan += "&field";
	Luncurkan += String(field);
	Luncurkan += "=";
	Luncurkan += String(nilai);
	Luncurkan += "\r\n\r\n";
	HubungkanThingspeak = "AT+CIPSEND=";
	HubungkanThingspeak += String(Luncurkan.length());
	MKUB_PIN_ESP.println(HubungkanThingspeak);
	if (MKUB_PIN_ESP.find(">")) { 
		MKUB_PIN_ESP.print(Luncurkan);
	}
	else {
		MKUB_PIN_ESP.println("AT+CIPCLOSE");
	}
}

String MKUB_IOT::Ambil(String ID_Chanel, int field, String apiKeyAmbil){
	String Hasil_Baca;
	String HubungkanThingspeak = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80";
	MKUB_PIN_ESP.println(HubungkanThingspeak);
	delay(100);
	if (MKUB_PIN_ESP.find("ERROR"))
	{
		MKUB_PIN_ESP.println("Gagal konek ke server");
	return;
	}
	String AmbilData = "GET /channels/";
	AmbilData += ID_Chanel;
	AmbilData += "/fields/";
	AmbilData += String(field);
	AmbilData += "/last?key=";
	AmbilData += apiKeyAmbil;
	AmbilData += "\r\n\r\n";
	HubungkanThingspeak = "AT+CIPSEND=";
	HubungkanThingspeak += String(AmbilData.length());
	MKUB_PIN_ESP.println(HubungkanThingspeak);
	if (MKUB_PIN_ESP.find(">")) {
		MKUB_PIN_ESP.print(AmbilData);
	}
	else {
		MKUB_PIN_ESP.println("AT+CIPCLOSE");
	}
	delay(3000);
	while (MKUB_PIN_ESP.available()) {
		//Hasil_Baca = MKUB_PIN_ESP.readStringUntil('\n');
		if (MKUB_PIN_ESP.read() == '+') {
			if (MKUB_PIN_ESP.read() == 'I') {
				if (MKUB_PIN_ESP.read() == 'P') {
					if (MKUB_PIN_ESP.read() == 'D') {
						if (MKUB_PIN_ESP.read() == ',') {
							if (MKUB_PIN_ESP.read() == '4' || '3' || '2' || '1' ) {
								if (MKUB_PIN_ESP.read() == ':') {
									Hasil_Baca = MKUB_PIN_ESP.readStringUntil('C');
								}
							}
						}
					}
				}
			}
		}
	}
	return Hasil_Baca;
}

void MKUB_IOT::GantiBaudESP(int baudrate){
	MKUB_PIN_ESP.println("AT+RST");
	delay(2000);
	String rate = "AT+CIOBAUD=";
	rate += String(baudrate);
	MKUB_PIN_ESP.println(rate);
	delay(2000);
}
