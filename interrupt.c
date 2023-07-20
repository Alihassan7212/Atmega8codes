#include <avr/io.h>
#include <avr/interrupt.h>

void LED_init() {
	// Set Pin 0 of PORTB as output
	DDRB |= (1 << DDB0);
}

void button_init() {
	// Set Pin 2 of PORTD as input with internal pull-up resistor
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << PORTD2);

	// Enable external interrupt INT0
	GICR |= (1 << INT0);

	// Trigger interrupt on falling edge (button press)
	MCUCR |= (1 << ISC01);
}

ISR(INT0_vect) {
	// Toggle the LED (Pin 0 of PORTB)
	PORTB ^= (1 << PORTB0);
}

int main(void) {
	// Initialize LED and button
	LED_init();
	button_init();

	// Enable global interrupts
	sei();

	while (1) {
		// Your main program can continue here or remain empty
	}

	return 0;
}
