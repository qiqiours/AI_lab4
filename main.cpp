#include "mbed.h"

Serial pc(USBTX, USBRX);

// Initialize a pins to perform analog and digital output functions
AnalogOut aout(p18);
AnalogIn ain(p20);

char text[128];
float voltage;
// Adjust VCC to get best scaling
float VCC1=3.292;
float VCC2=3.292;

int main(void){
   while (1) {
        pc.printf("Please enter an output voltage\n\r");
        pc.scanf("%s", text);
        voltage = atof(text);
        pc.printf("Voltage output is %f\n\r", voltage);
        // set the output value to be voltage/VCC
        aout = voltage/VCC1;
        // read the output voltage
        pc.printf("Voltage read is %f\n\r", ain*VCC2);
    }
}

