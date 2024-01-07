/*
  DS1302 RTC Modülü Arduino'ya Nasıl Bağlanır?
 
  DS1302 RTC Modülünün detaylı açıklaması ve örnek projelerini
  web sitemizde bulabilirsiniz.
 
  Mete Hoca
  https://www.metehoca.com/
*/

#include <virtuabotixRTC.h>        // Kütüphanemizi ekliyoruz
                                   // Chris Fryer'ın virtuabotixRTC kütüphanesi

int CLK = 6;                       // DS1302'nin CLK pini
int DAT = 7;                       // DS1302'nin DAT pini
int RST = 8;                       // DS1302'nin RST pini

virtuabotixRTC RTC(CLK, DAT, RST); // Kütüphanemizi ayarlıyoruz

void setup() {
  Serial.begin(9600);              // Seri Port Ekranı'nı başlatıyoruz

  // Anlık saati buraya girin, RTC'ye doğru saati yükleyeceğiz.
  int yil = 2022;
  int ay = 1;
  int gun = 3;
  int haftanin_gunu = 1;           // Pazartesi ise 1, Pazar ise 7
  int saat = 19;
  int dakika = 54;
  int saniye = 0;

  // Alttaki satır saati yükler. Bu halde bir defalığına Arduino'ya yükledikten
  // sonra satırı başına // koyarak yorum yapıp tekrar yüklemeliyiz.
  // Aksi halde her açılışta yukarıdaki saati geri yükler.
  RTC.setDS1302Time(saniye, dakika, saat, haftanin_gunu, gun, ay, yil);
}

void loop() {
  RTC.updateTime();                             // Güncel saati bu satırda okuyoruz
  if (RTC.dayofmonth < 10) {Serial.print("0");} // 3. ayı 03 olarak gösterelim
  Serial.print(RTC.dayofmonth);                 // Günü yazalım
  Serial.print(".");
  if (RTC.month < 10) {Serial.print("0");}
  Serial.print(RTC.month);                      // Ayı yazalım
  Serial.print(".");
  Serial.print(RTC.year);                       // Yılı yazalım
  Serial.print(" | ");
  if (RTC.hours < 10) {Serial.print("0");}
  Serial.print(RTC.hours);                      // Saati yazalım
  Serial.print(":");
  if (RTC.minutes < 10) {Serial.print("0");}
  Serial.print(RTC.minutes);                    // Dakikayı yazalım
  Serial.print(":");
  if (RTC.seconds < 10) {Serial.print("0");}
  Serial.println(RTC.seconds);                  // Saniyeyi yazalım
  delay(100);                                   // Biraz bekleyelim
}