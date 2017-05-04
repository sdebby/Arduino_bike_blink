/*Created by Shmulik Debby
 * 28.03.17
 * Bike leds- controled by RF remote control
 * works on Arduino nano v3.0
 * This version will flag HIGH in pin 12 for LED if PowerBankPresent flag is TRUE
 * and keep alive the USB Power bank by consuming constant power
*/
  // NeoPixel define
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif
//Left LED define
#define LeftNeoPixelPin 6
#define LeftNeoPixelNo 10
//Right LED define
#define RightNeoPixelPin 7
#define RightNeoPixelNo 10
//Input pins define
#define InputBtn1Pin 2
#define InputBtn2Pin 3
#define InputBtn3Pin 4
#define InputBtn4Pin 5
int delayval=25; //25 ms

int PowerBankWakeUpPin=12;

Adafruit_NeoPixel pixelsL = Adafruit_NeoPixel(LeftNeoPixelNo, LeftNeoPixelPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsR = Adafruit_NeoPixel(RightNeoPixelNo, RightNeoPixelPin, NEO_GRB + NEO_KHZ800);
  
int btn1State = 0;
int btn2State = 0;
int btn3State = 0;
int btn4State = 0;

boolean WhiteState=false;
boolean PowerBankPresent=true; //if power connected to power bak usb battery.

void setup() {
  // NeoPixel define
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
pixelsL.begin(); // This initializes the NeoPixel library.
pixelsR.begin(); // This initializes the NeoPixel library.
//Initize button input
  pinMode(InputBtn1Pin, INPUT); // Left turn
  pinMode(InputBtn2Pin, INPUT);// Right turn
  pinMode(InputBtn3Pin, INPUT);
  pinMode(InputBtn4Pin, INPUT);

  pinMode(PowerBankWakeUpPin, OUTPUT);

//Initize NeoPixel Output
  pinMode(LeftNeoPixelPin, OUTPUT);
  pinMode(RightNeoPixelPin, OUTPUT);
  AllStripsBlack(); //start with black
  Serial.begin(9600);

    if (PowerBankPresent ){ //if connected to power bank usb
    Serial.println("PowerBankResistor : on");
    digitalWrite(PowerBankWakeUpPin,HIGH);  
  }
}

void loop() {
  //Serial.println("PowerBankResistor :"+String(digitalRead(PowerBankWakeUpPin)));
  btn1State = digitalRead(InputBtn1Pin);
  btn2State = digitalRead(InputBtn2Pin);
  btn3State = digitalRead(InputBtn3Pin);
  btn4State = digitalRead(InputBtn4Pin);
  /* This code is use to wake up the power USB bank if connected as power sorce and have 
  build in power-save mode*/
    

// Button 1
if (btn1State==HIGH){
  Serial.println("1 On");
  for(int j=0;j<1000/delayval;j++){
      for(int i=0;i<LeftNeoPixelNo;i++){
      PixelRed(i,0);
      delay(delayval);
      PixelBlack(i,0);
    }
  }
    Serial.println(WhiteState);
  if (WhiteState){
    AllStripsWhite();
  }
}
// Button 2
if (btn2State==HIGH){
    Serial.println("2 On");
  for(int j=0;j<1000/delayval;j++){
      for(int i=0;i<RightNeoPixelNo;i++){
      PixelRed(i,1);
      delay(delayval);
      PixelBlack(i,1);
    }
  }
  Serial.println(WhiteState);
    if (WhiteState){
    AllStripsWhite();
  }
}
//Button 3
if (btn3State==HIGH){
    Serial.println("3 On");
    if (WhiteState){
       AllStripsBlack();
     WhiteState=false; 
    } else{
      AllStripsWhite();
     WhiteState=true;  
    }
    delay(50);//fix double press button
    Serial.println(WhiteState);
}
// Button 4
if (btn4State==HIGH){
    Serial.println("4 On");

}

}
/* Side - 0 = LEFT
          1 = RIGHT*/
void PixelRed(int i,int Side){
switch (Side){
  case 0:
     pixelsL.setPixelColor(i, pixelsL.Color(255,0,0));
     pixelsL.show();
  break;
  case 1:
     pixelsR.setPixelColor(i, pixelsR.Color(255,0,0));
     pixelsR.show();
  break;
  }
}

void PixelWhite(int i,int Side){
switch (Side){
  case 0:
     pixelsL.setPixelColor(i, pixelsL.Color(255,255,255));
     pixelsL.show();
     break;
  case 1:
     pixelsR.setPixelColor(i, pixelsR.Color(255,255,255));
     pixelsR.show();
     break;
  }
}

void PixelBlack(int i,int Side){
switch (Side){
  case 0:
     pixelsL.setPixelColor(i, pixelsL.Color(0,0,0));
     pixelsL.show(); 
  break;
  case 1:
     pixelsR.setPixelColor(i, pixelsR.Color(0,0,0));
     pixelsR.show();
  break;
  }
}

void AllStripsWhite(){
  for(int i=0;i<LeftNeoPixelNo;i++){
  PixelWhite(i,0);
  }
 for(int i=0;i<RightNeoPixelNo;i++){
  PixelWhite(i,1);
  }
}

void AllStripsBlack(){
  for(int i=0;i<LeftNeoPixelNo;i++){
  PixelBlack(i,0);
  }
  for(int i=0;i<RightNeoPixelNo;i++){
  PixelBlack(i,1);
  }
}


