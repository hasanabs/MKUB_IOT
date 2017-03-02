
/* *-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**
   --------------------------------------------------------------------------------------------------------------------
                     Contoh program pembacaan data dari Thingspeak dengan pustaka MKUB_IOT
            Contoh program dan pustaka ini dibuat oleh Divisi Mikrokontroler Universitas Brawijaya
                  Untuk informasi lebih lanjut silahkan unjungi http://mk.elektro.ub.ac.id
   --------------------------------------------------------------------------------------------------------------------
*/

#include <MKUB_IOT.h>
MKUB_IOT IOT;

String ApikeyRead1 = "Apikey read anda";
String ID_Chanel1 = "CH_ID anda";

void setup() {
  //Inisialisasi nilai baudrate untuk komunikasi ke ESP8266
  IOT.baud(9600);
  //Menghubungkan modul ke akses poin
  IOT.konek("SSID", "Password");
  //Inisialisasi nilai baudrate untuk komunikasi ke serial dari board
  Serial.begin(19200);
}

void loop() {
  //Pengambilan nilai dari Thingspeak yang akan dimasukan ke variabel Baca
  String Baca = x.Ambil(ID_Chanel1, 1, ApikeyRead1); //NamaVariabel.Ambil(ID_Chanel1 (string), field (integer), ApikeyRead (string));
  //Pengiriman nilai variabel Baca melalui serial dari board
  Serial.println(Baca);
  //Jeda sebesar 10 detik
  delay(10000);
}
