#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BUILT_IN_LED_DDR        (DDRB)
#define BUILT_IN_LED_PORT       (PORTB)
#define BUILT_IN_LED_PIN        (5)

void built_in_led_init(void)
{
    BUILT_IN_LED_DDR |= (1 << BUILT_IN_LED_PIN);
}

void built_in_led_set(bool state)
{
    if (state == true)
    {
        BUILT_IN_LED_PORT = (1 << BUILT_IN_LED_PIN);
    }
    else
    {
        BUILT_IN_LED_PORT &= ~(1 << BUILT_IN_LED_PIN);
    }
}

int main(void)
{
    // setup GPIO
    built_in_led_init();

    while(true)
    {
        built_in_led_set(true);
        _delay_ms(500);
        built_in_led_set(false);
        _delay_ms(500);
    }
    return 0;
}