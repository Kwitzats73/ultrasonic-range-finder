#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
 
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

long duration, distance; // Duration used to calculate distance

void setup() {
   
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
  lcd.init(); // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  // Blinking block cursor
  lcd.blink_on();
}

void loop() {
  
   // Delay 50ms before next reading.
   delay(150);
  
  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */ 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); 
   
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   
   //Calculate the distance (in cm) based on the speed of sound.
   distance = duration/58.2;
   
   // display on lcd
   
   String disp = String(distance);
   
   lcd.clear();
   lcd.setCursor(5, 0); // second line
   lcd.print("IdeaLabKids ");
    lcd.setCursor(0, 1); // second line
    lcd.print("UltraSonicRngefinder");
   lcd.setCursor(3, 2); // second line
   lcd.print("distance :"); // first line 
   
   lcd.print(disp);
   lcd.print(" cm");
    lcd.setCursor(4, 3); // second line
   lcd.print("By K");

}
