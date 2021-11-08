int led1=13;
int buton1=8;
int buton1Durum;
int led1Durum=0;
////////////////////////////////////////7777
 int DO = 1; //D0 pini
int DA = A0; // A0 pini
int ses1 = 40;//analog ses seviyesi
int ses2 = 45;
int ses3 = 55;
int ses4 = 65;
int ses5 = 70;
int ses6 = 75;
int ses7 = 80;
int ses8 = 85;
int ses9 = 90;
int sesdegeri = 0;
///////////////////////////////////////

//int DA = A0; // A0 pinini DA değişkenine aktarıyoruz
int ses10 = 100;//

//int sesdegeri = 0;
int led_status=0;


int x=0;

void setup(){
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(buton1, INPUT);
  ////////////////
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT);
  ///////////////////
  pinMode(12, OUTPUT);
}

void loop(){
  buton1Durum=digitalRead(buton1);
  if(buton1Durum==HIGH && x==0){
    x=1;
    if(led1Durum==0) led1Durum=1;
    else if(led1Durum==1) led1Durum=0;
  }
  else if(buton1Durum==LOW && x==1){
    x=0;
  }
 
  if (led1Durum==1){
    digitalWrite(led1, HIGH);
    sesdegeri = analogRead(DA); 
  if (sesdegeri >= ses1) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
   if (sesdegeri >= ses2) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
   if (sesdegeri >= ses3) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
   if (sesdegeri >= ses4) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }
   if (sesdegeri >= ses5) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
   if (sesdegeri >= ses6) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
   if (sesdegeri >= ses7) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
   if (sesdegeri >= ses8) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }
    if (sesdegeri >= ses9) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(11, HIGH);
  }
  else {
    digitalWrite(11, LOW);
  }

    
    
  }
  else{
    digitalWrite(led1, LOW);
    //Sensörden Veri Alma
  sesdegeri = analogRead(DA);  
  Serial.println(sesdegeri);
  
  //Açıp Kapama Döngüsü
  if (sesdegeri > ses10 && led_status==0) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
          digitalWrite(12, HIGH);//3.pindeki ledimize güç veriyor
          delay(10);
          led_status=1;//led durumunu 1 konumuna çalışır duruma getirip kapanma durumunda kullanmak için
  }else if(sesdegeri > ses10 && led_status==1){
       digitalWrite(12, LOW);//3.pindeki ledimize güç kesiyor
       led_status=0;
  }
  //Açıp Kapama Döngüsü-end
    
  }
}
  
  
