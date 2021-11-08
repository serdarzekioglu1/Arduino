int DO = 1; //D0 pini
int DA = A0; // A0 pini
int ses1 = 40;//analog ses seviyesi
int ses2 = 45;
int ses3 = 50;
int ses4 = 65;
int ses5 = 60;
int ses6 = 65;
int ses7 = 70;
int ses8 = 75;
int ses9 = 80;


int sesdegeri = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
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
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
   if (sesdegeri >= ses8) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
    if (sesdegeri >= ses9) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }
   
}
