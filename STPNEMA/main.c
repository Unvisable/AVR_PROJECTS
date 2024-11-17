#define F_CPU 16000000UL  // Define the CPU frequency as 16 MHz
#include <avr/io.h>
#include <util/delay.h>

// Define the control pins
#define STEP_PIN PD2
#define DIR_PIN PD3
#define ENABLE_PIN PD4

// Define the step delay (in microseconds)
#define STEP_DELAY 1000  // Adjust this value for speed control

void setup() {
    // Set the control pins as outputs
    DDRD |= (1 << STEP_PIN) | (1 << DIR_PIN) | (1 << ENABLE_PIN);

    // Enable the driver by setting ENABLE_PIN low
    PORTD &= ~(1 << ENABLE_PIN);
}

void stepMotor(int steps, int direction) {
    // Set the direction
    if (direction == 1) {
        PORTD |= (1 << DIR_PIN);  // Set DIR_PIN high
    } else {
        PORTD &= ~(1 << DIR_PIN); // Set DIR_PIN low
    }

    // Small delay to ensure the DIR pin is read correctly by the DRV8825
    _delay_ms(10);

    for (int i = 0; i < steps; i++) {
        // Generate a pulse on the STEP pin
        PORTD |= (1 << STEP_PIN);  // Set STEP_PIN high
        _delay_us(STEP_DELAY);     // Wait for a short period
        PORTD &= ~(1 << STEP_PIN); // Set STEP_PIN low
        _delay_us(STEP_DELAY);     // Wait for a short period
    }
}

int main(void) {
    // Initialize the pins
    setup();

    // Main loop
    while (1) {
        // Step 200 steps forward
        stepMotor(200, 1);
        _delay_ms(1000);  // Wait for a second

        // Step 200 steps backward
        stepMotor(200, 0);
        _delay_ms(1000);  // Wait for a second
    }

    return 0;
}
