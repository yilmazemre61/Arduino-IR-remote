// C++ Code
// Emre YILMAZ
// 27.07.2021

#include <IRremote.h> 
//including infrared remote header file
int RECV_PIN = 12; // the pin where you connect the output pin of IR sensor 
IRrecv irrecv(RECV_PIN);
decode_results results;
int redLed = 11; // red led is set to pin 11
int blueLed = 10; // blue led is set to pin 10
int value = 0; // the value from the button will be store 
int dt = 500; // delay time

void setup() {
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  
}
void loop() {

  if (irrecv.decode(&results)) {
    value = results.value;
    if(value == 2295){ // if the button 1 is pressed blue led will be On
      Serial.print("Blue is On: ");
      Serial.print(value);
      Serial.println(" ");
      irrecv.resume(); Serial.println("*****************");
      digitalWrite(blueLed,HIGH); 
      delay(dt);
    }
    if(value == -30601){ // if the button 2 pressed red led will be On
      Serial.print("Red is On: ");
      Serial.print(value);
      Serial.println(" ");
      irrecv.resume(); Serial.println("*****************");
      digitalWrite(redLed, HIGH);
      delay(dt);
    }
    if(value == 18615){ // if the button 3 is pressed blue led will be Off
      Serial.print("Blue is Off: ");
      Serial.print(value);
      Serial.println(" ");
      irrecv.resume(); Serial.println("*****************");
      digitalWrite(blueLed, LOW);
      delay(dt);
    }
    if(value == 10455){ // if the button 4 is pressed red led will be Off
      Serial.print("Red is Off: ");
      Serial.print(value);
      Serial.println(" ");
      irrecv.resume(); Serial.println("*****************");
      digitalWrite(redLed, LOW);
      delay(dt);
    }
    if(value == -22441){ // if the button 5 is pressed both led will be Off for 100 milliseconds 
      //and after that they will flash three times

      Serial.print("Blue and Red is On Three Times: ");
      Serial.print(value);
      Serial.println(" ");
      irrecv.resume(); Serial.println("*****************");
      // both will be Off
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(100);
      // blue and red led will be On
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, HIGH);
      delay(dt);
      // blue and red led will be Off
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt);
      // blue and red led will be On
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, HIGH);
      delay(dt);
      // blue and red led will be Off
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt);
      // blue and red led will be On
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, HIGH);
      delay(dt);
      // blue and red led will be Off
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      delay(dt);
    }


  } 

}















