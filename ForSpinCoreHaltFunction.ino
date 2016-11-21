const int FromSpinCoreTriggerPin = 2; //  the number of receiving external trigger pin
const int PowerLineTriggerPin = 3;  //  the number of the LED pin
const int ToSpinCoreHardTriggerPin = 4; //  the number of sending external trigger pin


// variables will change:
volatile int PowerLineTRiggerState = LOW;         // variable for 60Hz trigger

void setup() {
  // initialize the pin as an input:
  pinMode(FromSpinCoreTriggerPin, INPUT);
  
  // initialize the pin as an input:
  pinMode(PowerLineTriggerPin, INPUT);
  
  // initialize the pin as an output:
  pinMode(ToSpinCoreHardTriggerPin, OUTPUT);
  digitalWrite(ToSpinCoreHardTriggerPin, HIGH);
  
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(FromSpinCoreTriggerPin), sp_ISR, FALLING);
}

void loop() {
  if(PowerLineTRiggerState){
    digitalWrite(ToSpinCoreHardTriggerPin, LOW);
    delayMicroseconds(1); 
    digitalWrite(ToSpinCoreHardTriggerPin, HIGH);
    PowerLineTRiggerState = !PowerLineTRiggerState;
    detachInterrupt(digitalPinToInterrupt(PowerLineTriggerPin));
  }
}

void sp_ISR() {
  attachInterrupt(digitalPinToInterrupt(PowerLineTriggerPin), pl_ISR, FALLING);
}

void pl_ISR() {
  PowerLineTRiggerState = HIGH;
}
