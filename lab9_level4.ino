// C++ code
// Emre YILMAZ
// 27.07.2021


// library
#include <IRremote.h>

int IRpin = 12; // IR sensor is set to pin 12
IRrecv irrecv(IRpin);
decode_results results;
int value;

boolean start = true;
boolean start1 = true;
// LED

int redLed = 6; // red led is set to pin 6
int greenLed = 9; // green led is set to pin 9
int blueLed = 10; // blue led is set to pin 10

int red1 = 2; // single red led is set to pin 2
int blue1 = 3; // single blue led is set to pin 3
int green1 = 4; // single green led is set to pin 4


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop() {
  // It will call the method
  lightShow();
}
// button 1 will control the single red1 led
// button 2 will control the single blue1 led
// button 3 will control the single green1 led
// Up Arrow button will start the Led to fade in
// Down Arrow button will break the loop
// Play/Pause button will stop the Led while it is fading in and out


void lightShow() {

  if (irrecv.decode(&results)) {
    value = results.value;
    Serial.print("Value: ");
    Serial.println(value); //prints the value a a button press 
    irrecv.resume(); 
    Serial.println("*****************");
    // Red
    while(value == 2295){ // if the button 1 is pressed the loop will start
      if (irrecv.decode(&results)) {
        value = results.value;
        Serial.print("Value: ");
        Serial.println(value); //prints the value a a button press 
        irrecv.resume(); 
        Serial.println("*****************");
        if(value == 10455){ // if the button 4 is pressed the red1 will be On
          digitalWrite(red1, HIGH);
          while(start1){
            if (irrecv.decode(&results)) {
              value = results.value;
              Serial.print("Value: ");
              Serial.println(value); //prints the value a a button press 
              irrecv.resume(); 
              Serial.println("*****************");
              if(value == 20655){ // if the Up Arrow is pressed the redLed will start fading in
                for(int i=0; i<256; i++){
                  Serial.println(i);
                  analogWrite(redLed, i);
                  delay(200);
                  if (irrecv.decode(&results)) {
                    value = results.value;
                    if(value == -24481){ //if the Play/Pause button is pressed the loop will terminate 
                      break; 
                    }
                  }
                }
              }else if(value == 4335){ // if the Down Arrow button is pressed it will turn off bot the redLed and red1 and break the loop
                digitalWrite(red1, LOW);
                digitalWrite(redLed, LOW);
                break;
              }
            }
          }
        }
      } 
    }
    // Blue
    while(value == -30601){ // if the button 2 is pressed the loop will start
      if (irrecv.decode(&results)) {
        value = results.value;
        Serial.print("Value: ");
        Serial.println(value); //prints the value a a button press 
        irrecv.resume(); 
        Serial.println("*****************");
        if(value == -22441){// if the button 5 is pressed the blue1 will be On
          digitalWrite(blue1, HIGH);
          while(start1){
            if (irrecv.decode(&results)) {
              value = results.value;
              Serial.print("Value: ");
              Serial.println(value); //prints the value a a button press 
              irrecv.resume(); 
              Serial.println("*****************");
              if(value == 20655){ // if the Up Arrow is pressed the blueLed will start fading in
                for(int i=0; i<256; i++){
                  Serial.println(i);
                  analogWrite(blueLed, i);
                  delay(200);
                  if (irrecv.decode(&results)) {
                    value = results.value;
                    if(value == -24481){ //if the Play/Pause button is pressed the loop will terminate 
                      break; 
                    }
                  }
                }
              }else if(value == 4335){ // if the Down Arrow button is pressed it will turn off bot the blueLed and blue1 and break the loop
                digitalWrite(blue1, LOW);
                digitalWrite(blueLed, LOW);
                break;
              }
            }
          }
        }
      } 
    }
    // Green
    while(value == 18615){ // if the button 3 is pressed the loop will start
      if (irrecv.decode(&results)) {
        value = results.value;
        Serial.print("Value: ");
        Serial.println(value); //prints the value a a button press 
        irrecv.resume(); 
        Serial.println("*****************");
        if(value == 26775){ // if the button 6 is pressed the green1 will be On
          digitalWrite(green1, HIGH);
          while(start1){
            if (irrecv.decode(&results)) {
              value = results.value;
              Serial.print("Value: ");
              Serial.println(value); //prints the value a a button press 
              irrecv.resume(); 
              Serial.println("*****************");
              if(value == 20655){ // if the Up Arrow is pressed the greenLed will start fading in
                for(int i=0; i<256; i++){
                  Serial.println(i);
                  analogWrite(greenLed, i);
                  delay(200);
                  if (irrecv.decode(&results)) {
                    value = results.value;
                    if(value == -24481){ //if the Play/Pause button is pressed the loop will terminate 
                      break; 
                    }
                  }
                }
              }else if(value == 4335){ // if the Down Arrow button is pressed it will turn off bot the greenLed and green1 and break the loop
                digitalWrite(green1, LOW);
                digitalWrite(greenLed, LOW);
                break;
              }
            }
          }
        }
      } 
    }
  }
}































