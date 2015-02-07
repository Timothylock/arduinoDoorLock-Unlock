int inPin = 4;   
int motorFWD = 8;
int motorBCK = 7;
int greenPin = 12;
int redPin = 3;
int doorSensor = 4;
int lightSensor = A5;
int val = 0;    
boolean closed = false;


void setup(){
  // Variables
  Serial.begin(9600);
  
  // Init 
  pinMode(inPin, INPUT);    
  pinMode(motorFWD, OUTPUT);  
  pinMode(motorBCK, OUTPUT);  
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
}

void lock(){ // Run nultiple times due to my motor not being strong enough
  // LED
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  // Motor
  digitalWrite(motorFWD, HIGH);
  digitalWrite(motorBCK, LOW);
  delay(1500);
  digitalWrite(motorFWD, LOW);
  digitalWrite(motorBCK, LOW);
  delay(500);
  digitalWrite(motorFWD, HIGH);
  digitalWrite(motorBCK, LOW);
  delay(1500);
  digitalWrite(motorFWD, LOW);
  digitalWrite(motorBCK, LOW);
  delay(500);
  digitalWrite(motorFWD, HIGH);
  digitalWrite(motorBCK, LOW);
  delay(1500);
  digitalWrite(motorFWD, LOW);
  digitalWrite(motorBCK, LOW);
}

void unlock(){
  // LED
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  // Motor
  digitalWrite(motorBCK, HIGH);
  digitalWrite(motorFWD, LOW);
  delay(1500);
  digitalWrite(motorFWD, LOW);
  digitalWrite(motorBCK, LOW);
}


void loop(){
  val = digitalRead(inPin);  

  if (val == HIGH) {         // door opened
    delay(1000);
    // Double Check
    if (val == HIGH){ 
      closed = false;
      // LED
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, HIGH);
    }
  } else {                   // door closed
    if (closed == false){
      lock();
      closed = true;
    }
  }
  val = analogRead(lightSensor);    // read the input pin
  Serial.println(val);  
  if (val > 20){
    unlock();
    delay(2000);
  }
}
