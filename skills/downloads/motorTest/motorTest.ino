//Test the EEEBug motors by generating two PWM signals
//The speed of each motor should rise and fall over a period of 2 seconds

unsigned int i=0;
unsigned long nextTime=0;
const unsigned long INTERVAL = 63;
const unsigned int STEP = 16;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis()>nextTime){ //Is it time to update the output?
    nextTime += INTERVAL;  //Calculate next update time
    i += STEP;            //Increment output counter
  
    if (i&0x100) {        //Bit 8 of counter determines if each output PWM is rising or falling
      analogWrite(9,i&0xff);          //Pin 9 duty cycle is rising
      analogWrite(10,0xff-(i&0xff));} //Pin 10 duty cycle is falling
    else {
      analogWrite(9,0xff-(i&0xff));   //Pin 9 duty cycle is falling
      analogWrite(10,i&0xff);}        //Pin 10 duty cycle is rising
    }

    digitalWrite(LED_BUILTIN,i&0x80); //Flash the LED
}
