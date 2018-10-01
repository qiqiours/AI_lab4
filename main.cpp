#include "mbed.h"

// In the sections below, change
// /* to // and */ to // to make a program active

// PROGRAM #1
/*
// This controls two digital out lines connected to LEDs
// and two others that go outon pins 21 and 22
// The program alternates these lines with a 2 second delay;
DigitalOut led1(LED1);  // Controls LED1
DigitalOut led2(LED2);  // Controls LED2
DigitalOut d1(p21);  // Controls pin 21
DigitalOut d2(p22);  // Controls pin 22

bool valOut = false; //logical variable to flip on and off

int main(void){
  while(1){
    led1 = valOut;
    d1 = valOut;
    led2 = !valOut;
    d2 = !valOut;
    valOut = !valOut;
    wait(2.);  // wait 2 seconds. Use wait_ms or wait_us using integers of milli or micro seconds
  }
}
*/

// PROGRAM #2
/*
// This program uses PWM to vary the LED brightness
PwmOut led1(LED1);  // PWM output will control LED1
PwmOut led2(LED2);  // PWM output will control LED2
// Could use PwmOut a1(p21) through p(26)
float brightness1 = 0.1;
float brightness2 = 0.5;

int main() {
    // Initialize
    led1.period(0.01);  //  period in seconds both outputs use the same period
    // Could use led.period_ms (for milliseconds) or led.period_us (for microseconds)
    // Could use led.pulsewidth (or led.pulsewidth_ms, led.pulsewidth_us) to set the on width for a given frequency
    
    while(1) {
        led1 = brightness1; // set the fraction of period on
        led2 = brightness2; // set the fraction of period on
        // Could use led.write(brightness);
    }
}
*/

// PROGRAM #3
/*
// This program writes out a sine wave
AnalogOut  aout(p18);
int main(void){
    while(1){
        for (int k = 0; k < 32; k++){
            aout = (1+sin(3.14159*k/16.))/2.;
        }
    }
 }
*/


// PROGRAM #4
/*
// This program writes out a sine wave quickly
int main(void){
// Define an array to hold the function values
// Change the 32 if you want more or fewer values
    float temp[32];
// If you calculate the values before you output them
// the wave can be much faster
    for (int k = 0; k < 32; k++){
        temp[k] = (1+sin(3.14159*k/16.))/2.;
    }
    while(1){
      for (int k = 0; k < 32; k++){
            aout = temp[k];
      }
    }
 }
*/



// PROGRAM #5

// This program reads an analog voltage and 
// echoes it outon the analog output line
AnalogOut aout(p18);
AnalogIn ain(p20);
float volts;
float VCC = 3.292;
int main(void){
    while(1){
        volts = VCC*ain;
        aout = volts/VCC;
    }
 }
