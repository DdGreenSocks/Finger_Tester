#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

void servo_init() {
    // Set the data direction of the servo control pin (PE3) as output
    DDRE |= (1 << PE3);

    // Timer 3 configuration for Fast PWM mode
    TCCR3A |= (1 << COM3A1) | (1<<COM3B1)|(1 << WGM31);               // NON Inverted PWM
    TCCR3B |= (1 << WGM33) | (1 << WGM32) | (1 << CS31)| (1 << CS30); // Prescaler 64 

    // Set the ICR3 register for a frequency of 50Hz (20ms period)
    ICR3 = 4999; // (16,000,000 / (64 * 50)) - 1
}

void servo_write(uint16_t pulse_width) {
    // Set the OCR3A register to the desired pulse width
    OCR3A = pulse_width;
}

int main(void) {
    servo_init(); // Initialize the servo
    _delay_ms(1000); // Wait for the servo to settle

    while (1) {
        // Your servo motion control code here

        // Example: Set servo to 0 degrees
       
        servo_write(97);
        _delay_ms(4000);

        // Example: Set servo to 90 degrees
        
        servo_write(316);
        _delay_ms(4000);

        // Example: Set servo to 180 degrees
        
         servo_write(535);
        _delay_ms(4000);
    }

    return 0;
}
