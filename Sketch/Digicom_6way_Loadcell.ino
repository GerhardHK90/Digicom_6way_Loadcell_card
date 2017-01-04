/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 15 - Serial clock out (SCLK)
// pin 16 - Serial data out (DIN)
// pin 18 - Data/Command select (D/C)
// pin 20 - LCD chip select (CS)
// pin 19 - LCD reset (RST)
//Adafruit_PCD8544 display = Adafruit_PCD8544(15, 16, 18, 20, 19);

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
 Adafruit_PCD8544 display = Adafruit_PCD8544(4, 9, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!

#define ADC_FACTOR 0.0009536888685 // 2 Volt is 50 Ton 2.5 Volt 62.5 Ton

unsigned int Analog1,Analog2,Analog3,Analog4,Analog5,Analog6;
float Rope1,Rope2,Rope3,Rope4,Rope5,Rope6;

void setup()   {
  Serial.begin(9600);
  analogReadRes(16);  // SetrbADC resolution to 16 bits
  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(65);

  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  ECAM_Info();
 

}


void loop() {
  
  Analog1 = analogRead(A0);
  Rope1 = (Analog1 * ADC_FACTOR);
  Analog2 = analogRead(A1);
  Rope2 = (Analog2 * ADC_FACTOR);
  Analog3 = analogRead(A2);
  Rope3 = (Analog3 * ADC_FACTOR);
  Analog4 = analogRead(A3);
  Rope4 = (Analog4 * ADC_FACTOR);
  Analog5 = analogRead(A4);
  Rope5 = (Analog5 * ADC_FACTOR);
  Analog6 = analogRead(A5);
  Rope6 = (Analog6 * ADC_FACTOR);
  display.clearDisplay();   // clears the screen and buffer 
  DisplayADC();
}





void ECAM_Info(void) {

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("ECAM(PTY)Ltd");
  display.setCursor(0,15);
  display.println("+27119553379");
  display.setCursor(0,25);
  display.println("+27119551053");
  display.display();
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
}


void DisplayADC(void) {
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(60,0);
  display.println("Ton");
  display.setCursor(0,0);
  display.println("LC1=");
  display.setCursor(24,0);
  display.println(Rope1);
  display.setCursor(60,8);
  display.println("Ton");
  display.setCursor(0,8);
  display.println("LC2=");
  display.setCursor(24,8);
  display.println(Rope2);
  display.setCursor(60,16);
  display.println("Ton");
  display.setCursor(0,16);
  display.println("LC3=");
  display.setCursor(24,16);
  display.println(Rope3);
  display.setCursor(60,24);
  display.println("Ton");
  display.setCursor(0,24);
  display.println("LC4=");
  display.setCursor(24,24);
  display.println(Rope4);
  display.setCursor(60,32);
  display.println("Ton");
  display.setCursor(24,32);
  display.println(Rope5);
  display.setCursor(0,32);
  display.println("LC5=");
  display.setCursor(24,40);
  display.println(Rope6);
  display.setCursor(60,40);
  display.println("Ton");
  display.setCursor(0,40);
  display.println("LC6=");
  display.display();
  


  
}


