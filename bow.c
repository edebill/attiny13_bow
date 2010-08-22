#define F_CPU 1200000UL
#include <avr/io.h>
#include <util/delay.h>

#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

int led_list[] = {PB1,PB2,PB3,PB4};
int led;

void delay_ms(uint16_t millis) {
 uint16_t loop;
 while ( millis ) {
 _delay_ms(1);
 millis--;
 }
}

void setup() {
  int i;
  for(i = 0; i < 6; i++) {
    DDRB |= 1<< led_list[i]; // set led pins to output
  }
}

void loop() {
  int i;
  for(i = 0; i < 4; i++) {
    int led = led_list[i];
    // turn on the LED for 100ms
    output_high(PORTB, led);
    delay_ms(100);
    // now turn off the LED for another 100ms
    output_low(PORTB, led);
    delay_ms(100);
  }
}


int main(void) {
  setup();

  while(1) {
    loop();
  }

  return 0;
}
