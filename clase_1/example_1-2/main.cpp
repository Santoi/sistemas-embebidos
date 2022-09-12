#include "arm_book_lib.h"
#include "mbed.h"
#include "hal/gpio_api.h"

int main()
{
    // Set the USER BUTTON to control the variable gas_detector
    // Turns the gas detector OFF by default
    gpio_t gas_detector;
    gpio_init_in_ex(&gas_detector, BUTTON1, PullDown);

    // // Show the state of alarmLed variable with LED1
    gpio_t alarm_led;
    gpio_init_out(&alarm_led, LED3);


    // Turn the led OFF
    gpio_write(&alarm_led, OFF);

    // Change the state of the alarmLED by reading the gasDetector input
    while (true) {
        if (gpio_read(&gas_detector) == ON) {
            printf("%s\n", "Turning led ON");
            gpio_write(&alarm_led, ON);;
        }
        
        if (gpio_read(&gas_detector) == OFF) {
            printf("%s\n", "Turning led OFF");
            gpio_write(&alarm_led, OFF);;
        }
    }
    
    // Return OK signal
    return 0;
}