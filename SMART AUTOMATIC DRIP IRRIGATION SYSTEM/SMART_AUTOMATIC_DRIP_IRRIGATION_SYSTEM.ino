#include <LiquidCrystal.h> 
#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523

int temp;
int T_Sensor = A4;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
void setup()

{
lcd.begin(16, 2);
lcd.clear(); 
pinMode(13,OUTPUT); 
pinMode(7,INPUT); 
pinMode(9,OUTPUT);
val = analogRead(T_Sensor); 
int mv = ( val/1024.0)*5000; 
cel = mv/10;
lcd.setCursor(0,0); 
lcd.print("Project By:"); 
lcd.setCursor(0,1); 
lcd.print("The Technocrat"); 
delay(1000);
lcd.clear(); 
lcd.clear();

lcd.setCursor(0,0); 
lcd.print("Project By:"); 
lcd.setCursor(0,1); 
lcd.print("Sandesh Hegde"); 
delay(1000);
}
void loop() {
lcd.clear();
int Moisture = analogRead(M_Sensor); 
lcd.setCursor(0,0); 
lcd.print("TEMP:"); 
lcd.setCursor(5,0);
lcd.print(cel);
lcd.setCursor(7,0);
lcd.print("*C");
if (Moisture> 700) {
lcd.setCursor(11,0); 
lcd.print("DRY"); 
lcd.setCursor(11,1); 
lcd.print("SOIL");
if (digitalRead(W_led)==1) {
digitalWrite(13, HIGH); 
lcd.setCursor(0,1);

lcd.print("PUMP:ON"); }
else {
digitalWrite(13, LOW); 
lcd.setCursor(0,1); 
lcd.print("PUMP:OFF");
tone(Speaker, NOTE_C4, 500); 
delay(500);
tone(Speaker, NOTE_D4, 500); 
delay(500);
tone(Speaker, NOTE_E4, 500); 
delay(500);
tone(Speaker, NOTE_F4, 500); 
delay(500);
tone(Speaker, NOTE_G4, 500);
delay(500); }
}
if (Moisture>= 300 && Moisture<=700)
{ lcd.setCursor(11,0);
lcd.print("MOIST"); 
lcd.setCursor(11,1); 
lcd.print("SOIL"); 
digitalWrite(13,LOW); 
lcd.setCursor(0,1); 
lcd.print("PUMP:OFF");

}
if (Moisture < 300) {
lcd.setCursor(11,0); 
lcd.print("SOGGY"); 
lcd.setCursor(11,1); 
lcd.print("SOIL"); 
digitalWrite(13,LOW); 
lcd.setCursor(0,1); 
lcd.print("PUMP:OFF");
} 
delay(1000);
}
