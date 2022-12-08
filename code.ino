/* Line 7-51 and Line 143-178 of the code was written by Yufei Ma
 *  Line 53-141 of the code was written by Yutian Wei
 */



#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>

#define PIRPINA 2
#define PIRPINB 4
#define LEDPINA 7
#define LEDPINB 8
#define BUZZER 12

#define NUMPIXELS 12 //number of pixels on the light

int cnt = 0; // To calculate the time it takes for two people to breathe at the same rate
int thresholdVal = 20; //To distinguish between breathing in and out. When the pressure is greater than the threshold, it is determined to be breathing in.

Adafruit_NeoPixel pixelA(NUMPIXELS, LEDPINA, NEO_GRB + NEO_KHZ800); //set up the neo pixels
Adafruit_NeoPixel pixelB(NUMPIXELS, LEDPINB, NEO_GRB + NEO_KHZ800);

/*functions that control the pixels*/
void set_Light_A_On();
void set_Light_B_On();
void set_Light_A_Off();
void set_Light_B_Off();

void setup()
{
  Serial.begin(9600);

  /*set up the pinmodes*/
  pinMode(PIRPINA, INPUT);
  pinMode(PIRPINB, INPUT);
  pinMode(LEDPINA, OUTPUT);
  pinMode(LEDPINB, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  /*set up the pixels*/
  pixelA.begin();           
  pixelA.show();            
  pixelA.setBrightness(50); 

  pixelB.begin();           
  pixelB.show();            
  pixelB.setBrightness(50); 
  
  digitalWrite(BUZZER,LOW);
}

void loop()
{
  int pirValA = digitalRead(PIRPINA);
  int pirValB = digitalRead(PIRPINB);
  Serial.print("pirA:");
  Serial.println(pirValA);
  Serial.print("pirB:");
  Serial.println(pirValB);
  

  int pressureA = analogRead(0);
  Serial.print("pressureA:");
  Serial.println(pressureA);

  int pressureB = analogRead(1);
  Serial.print("pressureB:");
  Serial.println(pressureB);

  if (pirValA == HIGH && pirValB == HIGH) //There are people in front of both installations
  {
    if (pressureA >= thresholdVal && pressureB >= thresholdVal) //The two people are both breathing out
    {
      set_Light_A_On();
      Serial.println("light A on");
      
      set_Light_B_On();
      Serial.println("light B on");
       
      cnt++;
    }

    else if (pressureA < thresholdVal && pressureB < thresholdVal) //The two people are both breathing in
    {
      set_Light_A_Off();
      Serial.println("light A off");
      
      set_Light_B_Off();
      Serial.println("light B off");
      
      cnt++;
    }

    else if(pressureA >= thresholdVal && pressureB < thresholdVal)
    {
      set_Light_A_On();
      Serial.println("light A on");
      
      set_Light_B_Off();
      Serial.println("light B off");
      
      cnt = 0;
       
    }
    
    else if(pressureA < thresholdVal && pressureB >= thresholdVal)
    {
      set_Light_A_Off();
      Serial.println("light A off");
      
      set_Light_B_On();
      Serial.println("light B on");
      
      cnt = 0;
    }


     if (cnt >= 3) //The two people have been breathing at the same rate for a while
     {
        tone(BUZZER, 0); //To stop the noise
        
        delay(5000);
        cnt=0;
     }

     else if(cnt<3)
     {
       digitalWrite(BUZZER,HIGH);
       tone(BUZZER, 1000);
       
       delay(100);          
      }            
    }
                                                   
    Serial.print("cnt:");
    Serial.println(cnt);

    delay(300);

}

void set_Light_A_On()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixelA.setPixelColor(i, pixelA.Color(255, 255, 255));
    pixelA.show();
  }
}

void set_Light_B_On()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixelB.setPixelColor(i, pixelB.Color(255, 255, 255));
    pixelB.show();
  }
}

void set_Light_A_Off()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixelA.clear();
    pixelA.show();
  }
}

void set_Light_B_Off()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixelB.clear();
    pixelB.show();
  }
}
