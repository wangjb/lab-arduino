const int FromSpinCoreTriggerPin = 2; //  the number of receiving external trigger pin
const int PowerLineTriggerPin = 3;  //  the number of the LED pin
const int ToSpinCoreHardTriggerPin = 4; //  the number of sending external trigger pin

// variables will change:    
volatile int PowerLineTRiggerState1;   // variable for 60Hz trigger
volatile int PowerLineTRiggerState2;   // variable for 60Hz trigger

void setup() {
  // initialize the pin as an input:
  pinMode(FromSpinCoreTriggerPin, INPUT_PULLUP);
  
  // initialize the pin as an input:
  pinMode(PowerLineTriggerPin, INPUT_PULLUP);
  
  // initialize the pin as an output:
  pinMode(ToSpinCoreHardTriggerPin, OUTPUT);
  digitalWrite(ToSpinCoreHardTriggerPin, HIGH);
  
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(FromSpinCoreTriggerPin), sp_ISR, FALLING);
}

void loop() {

}

void sp_ISR() {
  while(true){
    PowerLineTRiggerState1 = digitalRead(PowerLineTriggerPin);
    delayMicroseconds(1); 
    PowerLineTRiggerState2 = digitalRead(PowerLineTriggerPin);
    if(PowerLineTRiggerState1 and !PowerLineTRiggerState2){
      digitalWrite(ToSpinCoreHardTriggerPin, LOW);
      delayMicroseconds(1); 
      digitalWrite(ToSpinCoreHardTriggerPin, HIGH);
      break;
    }
  }
}

