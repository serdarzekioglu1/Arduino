#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3f, 16, 2);
//s�cakl�k
int lm35Pin = A2;
unsigned long zaman = 0, eskizaman = 0; //lcd ekranda s�cakl��� 2 saniye bir g�ncellemek i�in zaman de�i�kenleri
//ses i�in sabitler
int ses_sensoru = A0;
// ses 1
int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;
boolean isik_durumu = false;
int esik=500;
//ses 2
int ses1 = 100;
int ses2 = 200;
int ses3 = 300;
int ses4 = 400;
int ses5 = 500;
int ses6 = 600;
//lcd control
int sahip=0;

//for button 1
int buton=3;
int durum=0;
int butondeger=0;

//for button 2
int buton2=4;
int durum2=0;
int butondeger2=0;

void setup() {
	//lcd ba�latma ve arka ���k ayd�nlatmas�
lcd.begin();
lcd.backlight();
//Ledler
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
//butonlar
pinMode(buton, INPUT);
pinMode(buton2,INPUT);
//Sens�r ve di�er de�i�kenler i�in serial monit�r 
Serial.begin(1000000);
}
 
void loop() {
 
if(sahip==0){
   lcd.setCursor(0,1);
 lcd.print("Cemre Eren");
 
 lcd.setCursor(10,0);
     lcd.print("/");
     
     lcd.setCursor(11,0);
     lcd.print(durum2);
     
     lcd.setCursor(12,0);
     lcd.print("/");
     
     lcd.setCursor(13,0);
   lcd.print("V.1");
   
    lcd.setCursor(13,1);
            lcd.print("OFF");
            lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.setCursor(7,0);
lcd.print(".C");
 sahip=1;
}

  zaman = millis();
  int fark = zaman - eskizaman;
  
  if (fark > 2000){
    int sicaklikVolt = analogRead(lm35Pin);
    int sicaklikC  = sicaklikVolt / 9.31; 
    lcd.setCursor(5, 0);
    lcd.print(sicaklikC);
    eskizaman = zaman;
  }
 



//button 1
  butondeger=digitalRead(buton);
  
  if(butondeger==HIGH && durum==0){
    durum=1;
    lcd.setCursor(13,0);
    lcd.print("V.2");
    delay(100);
  }else if(butondeger==HIGH && durum==1){
     lcd.setCursor(13,0);
   lcd.print("V.1");
    durum=0;
     delay(100);
  }
  
  //button 2
 butondeger2=digitalRead(buton2);
 
  if(butondeger2==HIGH && durum2==0){
    esik=400;
    durum2=1;
    delay(100);
  }else if(butondeger2==HIGH && durum2==1){
    esik=600;
    durum2=2;
    delay(100);
  }else if(butondeger2==HIGH && durum2==2){
    esik=700;
    durum2=3;
    delay(100);
  }else if(butondeger2==HIGH && durum2==3){
    esik=500;
    durum2=0;
    delay(100);
  }
   
   lcd.setCursor(11,0);
   lcd.print(durum2);
  
 int sensor_durumu = analogRead(ses_sensoru);
 Serial.println(sensor_durumu); //Serial monit�rde de�erleri kontrol etmek i�in
  //Modlar
  if(durum==0){
  	
     if (sensor_durumu >esik)
  {
    if (alkis == 0)
    {
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
    }
    else if (alkis > 0 && millis()-algilama_araligi >= 50)
    {
      algilama_araligi = millis();
      alkis++;
    }
  }
 
  if (millis()-algilama_araligi_baslangic >= 400)
  {
    if (alkis == 2)
    {
      if (!isik_durumu)
        {
          isik_durumu = true;
          lcd.setCursor(13,1);
          lcd.print(" ON");
          
          for(int i=5;i<=10;i++){
            digitalWrite(i, HIGH);
          }
          
        }
        else if (isik_durumu)
        {
          isik_durumu = false;
           lcd.setCursor(13,1);
            lcd.print("OFF");
           for(int i=5;i<=10;i++){
            digitalWrite(i, LOW);
           
          }
        }
    }
    alkis = 0;
  }

  }
  if(durum==1){
  	if (sensor_durumu >= ses1) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }

   if (sensor_durumu >= ses2) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  
   if (sensor_durumu >= ses3) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
   if (sensor_durumu >= ses4) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
   if (sensor_durumu >= ses5) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
    if (sensor_durumu >= ses6) { //E�er alg�lanan ses seviyesi belirledi�imiz de�erden b�y�kse
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }
  
  }

}
