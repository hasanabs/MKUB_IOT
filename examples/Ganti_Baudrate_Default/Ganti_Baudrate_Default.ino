
/* *-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**
   --------------------------------------------------------------------------------------------------------------------
                      Contoh program pengganti nilai baudrate dengan pustaka MKUB_IOT
            Contoh program dan pustaka ini dibuat oleh Divisi Mikrokontroler Universitas Brawijaya
                  Untuk informasi lebih lanjut silahkan unjungi http://mk.elektro.ub.ac.id
              HATI-HATI, PROGRAM INI HANYA DAPAT DIJALANKAN 1 KALI SETIAP PINDAH NILAI BAUDRATE
            SANGAT DIREKOMENDASIKAN PILIHLAH NILAI BAUDRATE YANG UMUM UNTUK ESP8266 (9600/115200)
   --------------------------------------------------------------------------------------------------------------------
*/

#include <MKUB_IOT.h>
MKUB_IOT IOT;

void setup() {
  IOT.baud(115200); //Baudrate sekarang
  IOT.GantiBaudESP(9600); //Baudrate tujuan
}

void loop() {

}
