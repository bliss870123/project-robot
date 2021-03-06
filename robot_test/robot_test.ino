#include <LedControl.h>
#include <CapacitiveSensor.h>
#define trigPin 12
#define echoPin 13
#define DIN 2
#define CS 3
#define CLK 4 
int t=0,sensor=0,sen=0;
CapacitiveSensor cs_7_9 = CapacitiveSensor(7, 9);
LedControl lc = LedControl(DIN, CLK, CS, 2); 
 //============mouth============ 
 byte mouth [16] = { 

B00000000,
B00000000,
B00000000,
B00100000,
B11100000,
B11000000,
B00000000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00000100,
B00000111,
B00000011,
B00000000,
B00000000,
 };
 byte mouth2 [16] = { 

B00000000,
B00000000,
B00000000,
B10000000,
B11000000,
B11100000,
B11100000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00000001,
B00000011,
B00000111,
B00000111,
B00000000,
 };
  byte mouth3 [16] = { 

B11111111,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B11111111,
//
B11111111,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B11111111,
 };
 byte mouth4 [16] = {
     
B00000000,    
B00000000,
B00000000,
B00010000,
B10101000,
B01000000,
B00000000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00010001,
B00101010,
B00000100,
B00000000,
B00000000,
 };
 byte mouth5 [16] = { 

B11110000,
B01010000,
B01010000,
B01010000,
B01010000,
B01010000,
B01010000,
B11111000,
//
B00011111,
B00010101,
B00010101,
B00010101,
B00010101,
B00010101,
B00010101,
B00111111,
 };
 //-------------------math--------------------------
 byte math [16] = {
     
B11000000,    
B00000000,
B00000000,
B11000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000010,
B00000010,
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
 };

 byte math1 [16] = {
     
B01000000,    
B01000000,
B01000000,
B11000000,
B01000000,
B01000000,
B01000000,
B00000000,
//
B00000010,
B00000010,
B00000010,
B00000011,
B00000000,
B00000000,
B00000000,
B00000000,
 };
 
 byte math2 [16] = {
     
B11000000,    
B01000000,
B01000000,
B11000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
 };
 
 byte math3 [16] = {
     
B11000000,    
B01000000,
B01000000,
B11000000,
B00000000,
B00000000,
B11000000,
B00000000,
//
B00000011,
B00000000,
B00000000,
B00000011,
B00000010,
B00000010,
B00000011,
B00000000,
 };

 byte math4 [16] = {
     
B10000000,    
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B00000000,
//
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000000,
 };

 byte math5 [16] = {
     
B11000000,    
B01000000,
B01000000,
B01000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000011,
B00000000,
 };

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  cs_7_9.set_CS_AutocaL_Millis(0xFFFFFFF);
  Serial.begin(115200);
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  lc.setIntensity(0,1); 
  lc.setIntensity(1,1); 
  lc.clearDisplay(0);
  lc.clearDisplay(1);
}
void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long microsec = pulseIn(echoPin,HIGH);
  float cmMsec=(microsec/2)/29.1;
if(cmMsec<=12)
{
 //5
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math[i]);
      lc.setColumn(1,7-i,math[i+8]);
    }
    delay(1000);
 //4 
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math1[i]);
      lc.setColumn(1,7-i,math1[i+8]);
    }
    delay(1000);
  //3
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math2[i]);
      lc.setColumn(1,7-i,math2[i+8]);
    }
    delay(1000);
  //2
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math3[i]);
      lc.setColumn(1,7-i,math3[i+8]);
    }
    delay(1000);
   //1
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math4[i]);
      lc.setColumn(1,7-i,math4[i+8]);
    }
    delay(1000);
  //0
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,math5[i]);
      lc.setColumn(1,7-i,math5[i+8]);
    }
    delay(1000);
    
  sen=1;
}
long total2 = cs_7_9.capacitiveSensor(50);
if(sen==1)
{
  if (total2>100)
  { 
    t++;
    delay (1000);
  }

  if(t==0)
  {
    for(int i = 0;i<8;i++)
    {
       lc.setColumn(0,7-i,mouth[i]);
       lc.setColumn(1,7-i,mouth[i+8]);
    }
  }
  
  else if(t==1)
  {
    for(int i = 0;i<8;i++)
     {
       lc.setColumn(0,7-i,mouth2[i]);
       lc.setColumn(1,7-i,mouth2[i+8]);
     }
  }
     
  else if(t==2)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth3[i]);
      lc.setColumn(1,7-i,mouth3[i+8]);
    }
  }
  
  else if(t==3)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth4[i]);
      lc.setColumn(1,7-i,mouth4[i+8]);
    }
  } 
  
  else if(t==4)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth5[i]);
      lc.setColumn(1,7-i,mouth5[i+8]);
    }
  } 
  else if(t==5)
  {
    t=0;
  }  
}
}
