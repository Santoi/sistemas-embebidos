#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // Set variable gasDetector in digital pin 2
    DigitalIn gasDetector(D2);

    // Show the state of alarmLed variable with LED1
    DigitalOut alarmLed(LED1);

    // Turns the gas detector OFF by default
    gasDetector.mode(PullDown);

    // Turn the led OFF
    alarmLed = OFF;

    // Change the state of the alarmLED by reading the gasDetector input
    while (true) {
        // If gas detector is on, then turn on the alarm.
        if ( gasDetector == ON ) {
        printf("%s\n", "Turning led ON");
        alarmLed = ON;
        }

        // If gas detector is off, then turn off the alarm.        
        if ( gasDetector == OFF ) {
        printf("%s\n", "Turning led OFF");
            alarmLed = OFF;
        }
    }
    
    // Return OK signal
    return 0;
}