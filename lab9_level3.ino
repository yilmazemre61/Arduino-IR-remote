// C++ Code
// Emre YILMAZ
// 27.07.2021

// library
#include <IRremote.h>

int IRpin = 12; // IR sensor is set to pin 12
IRrecv irrecv(IRpin);
decode_results results;
int value;

// LED

int redLed = 6; // red led is set to pin 6
int greenLed = 9; // green led is set to pin 9
int blueLed = 10; // blue led is set to pin 10

int redBrightness;
int greenBrightness;
int blueBrightness;

boolean start1 = true;
boolean start2 = true;
boolean start3 = true;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}


void loop() {

  // it will start looping
  while(start1){

    Serial.println("1");
    delay(1000);

    if(irrecv.decode(&results)){

      value = results.value;
      Serial.print("Value : ");
      Serial.println(value);
      irrecv.resume();

      if(value == -32641){ // when the VOL+ button is pressed the red led will start fading in

        redBrightness += 17;
        Serial.print("red : ");
        Serial.println(redBrightness);
        analogWrite(redLed, redBrightness);

        if(redBrightness >= 255){ // when the brightness value reaches the 255 it will stay in the highest 
          redBrightness = 255;
          analogWrite(redLed, 255); 
        }  

      }

      if(value == -28561){ // when the VOL- button is pressed the red led will start fading out

        redBrightness -= 17;
        Serial.print("red : ");
        Serial.println(redBrightness);
        analogWrite(redLed, redBrightness);

        if(redBrightness <= 0){ // when the brightness value reaches the 0 it will stay Off
          redBrightness = 0;
          analogWrite(redLed, 0);
        }

      }

      if(value == -24481){ // when the Play/Pause button is pressed 
        //it will set the value 0 for red led and break the while loop
        analogWrite(redLed, 0);
        break;
      }
    }
  }

  // after the Play/Pause button is pressed, it will start looping 
  while(start2){

    Serial.println("2");
    delay(1000);

    if(irrecv.decode(&results)){

      value = results.value;
      Serial.print("Value : ");
      Serial.println(value);
      irrecv.resume();

      if(value == -32641){ // when the VOL+ button is pressed the blue led will start fading in

        blueBrightness += 17;
        Serial.print("blue : ");
        Serial.println(blueBrightness);
        analogWrite(blueLed, blueBrightness);

        if(blueBrightness >= 255){ // when the brightness value reaches the 255 it will stay in the highest 
          blueBrightness = 255;
          analogWrite(blueLed, 255); 
        }  
      }

      if(value == -28561){ // when the VOL- button is pressed the blue led will start fading out

        blueBrightness -= 17;
        Serial.print("blue : ");
        Serial.println(blueBrightness);
        analogWrite(blueLed, blueBrightness);

        if(blueBrightness <= 0){ // when the brightness value reaches the 0 it will stay Off
          blueBrightness = 0;
          analogWrite(blueLed, 0);
        }
      }

      if(value == -24481){ // when the Play/Pause button is pressed 
        //it will set the value 0 for blue led and break the while loop
        analogWrite(blueLed, 0);
        break;
      }
    } 




  }

  // after the Play/Pause button is pressed, it will start looping
  while(start3){

    Serial.println("3");
    delay(1000);

    if(irrecv.decode(&results)){

      value = results.value;
      Serial.print("Value : ");
      Serial.println(value);
      irrecv.resume();

      if(value == -32641){ // when the VOL+ button is pressed the green led will start fading in

        greenBrightness += 17;
        Serial.print("green : ");
        Serial.println(greenBrightness);
        analogWrite(greenLed, greenBrightness);

        if(greenBrightness >= 255){ // when the brightness value reaches the 255 it will stay in the highest
          greenBrightness = 255;
          analogWrite(greenLed, 255); 
        }  
      }

      if(value == -28561){ // when the VOL- button is pressed the green led will start fading out

        greenBrightness -= 17;
        Serial.print("green : ");
        Serial.println(greenBrightness);
        analogWrite(greenLed, greenBrightness);

        if(greenBrightness <= 0){ // when the brightness value reaches the 0 it will stay Off
          greenBrightness = 0;
          analogWrite(greenLed, 0);
        }
      }

      if(value == -24481){ // when the Play/Pause button is pressed 
        //it will set the value 0 for green led and break the while loop
        analogWrite(greenLed, 0);
        break;
      }
    } 

  }
  
}








