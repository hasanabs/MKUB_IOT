
/* *-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**
   --------------------------------------------------------------------------------------------------------------------
                     Contoh program pengiriman data ke Thingspeak dengan pustaka MKUB_IOT
            Contoh program dan pustaka ini dibuat oleh Divisi Mikrokontroler Universitas Brawijaya
                  Untuk informasi lebih lanjut silahkan unjungi http://mk.elektro.ub.ac.id
   --------------------------------------------------------------------------------------------------------------------
*/

#include <MKUB_IOT.h>
MKUB_IOT IOT;

String ApikeyWrite1 = "Apikey write anda";

void setup() {
  //Inisialisasi nilai baudrate untuk komunikasi ke ESP8266
  IOT.baud(9600);
  //Menghubungkan modul ke akses poin
  IOT.konek("SSID", "Password");
}

void loop() {
  //Pembacaan nilai analog (10 bit) di pin analog 0
  int NilaiSensor = analogRead(A0);
  //Konversi nilai ADC ke nilai tegangan
  float Tegangan = NilaiSensor * (5.0 / 1023.0);
  //Pengiriman data ke Thingspeak
  IOT.kirim(ApikeyWrite1, 1, String(Tegangan)); //NamaVariabel.kirim( ApikeyWrite (string), field (integer), Data(string));
  //Jeda sebesar 15 detik karena pengiriman data tercepat yang diizinkan adalah 15 detik 1 pengiriman
  delay(15000);
}
