// For more info on the arduino's ports check the specific model's
// datasheet and the avr library documentations
#include <avr/io.h>
#include <util/delay.h>

int main() {
    // setting register bits high uses the following notation:
    // REG |= (1 << n) where n is the bit
    // REG = REG | (1 << n) also works
    // setting register bits log uses the following notation:
    // REG &= ~(1 << n)
    // REQ = REQ &~(1 << n) also works

    // PORTB's 5th bit turns on and off the built in LED so we will
    // be targeting that.

    // use the port B data direction register to make port B5 output
    // (0 means input 1 means output)
    DDRB |= (1 << 5);

    // forever
    while(1) {
        // turn on LED
        PORTB |= (1 << 5);

        // wait
        _delay_ms(500);

        // turn of LED
        PORTB &= ~(1 << 5);

        // wait
        _delay_ms(500);
    }
}
