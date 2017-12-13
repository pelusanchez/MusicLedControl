/**
RGB LED CONTROL by serial port
  <davidiglesanchez@gmail.com>

  Coded to Mega 2560
*/


//LEDS PinOUT:
const int redPin = 9;     // Red pin
const int greenPin = 10;  // Green pin
const int bluePin = 11;   // Blue pin



void setup() {
  // Serial configuration
  Serial.begin(9600);

  // Pinout configuration
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}




// Red, Green, Blue values
int rValue = 0;
int gValue = 0;
int bValue = 0;

int valor = 0;
int pos = 0;

int parseData(int ascii){
  if(ascii>=48 && ascii<=57){
    return ascii-48;
  }
  if(ascii>=65 && ascii<=90){
    return ascii-55;
  }

  
}

/**
Function: loop()
    Main function.
*/

void loop() {

  //Read serial data
  while(Serial.available()>0){
    
    int r = Serial.read();
    if(pos == 0){
      valor +=parseData((int)r)*35;
      pos =1;
    }else{
      valor+=parseData((int)r);
      if(valor <= 255){
        rValue = constrain(valor, 0, 255);
      }else if(valor<=511){
        gValue = constrain(valor-256, 0, 255);
      }else{
        bValue = constrain(valor-512, 0, 255);
      }
      
      //Serial.println("OK");
    
      analogWrite(redPin, rValue);
      analogWrite(greenPin, gValue);
      analogWrite(bluePin, bValue);
      pos = 0;
      valor = 0;
    }
    

    
    if(r==97){
      pos = 0;
      valor = 0;
      rValue = 0;
      gValue = 0;
      bValue = 0;
      analogWrite(redPin, rValue);
      analogWrite(greenPin, gValue);
      analogWrite(bluePin, bValue);
      
    }
    
  }


}








