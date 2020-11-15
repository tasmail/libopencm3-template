
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "logging.h"
#include "blinking.h"

int main(void)
{
	int i, j = 0, c = 0;

	initialize_log();

	write_line_to_log("Starting...");
	write_line_to_log("Log sub-system initialized.");

	initialize_blinking();
	write_line_to_log("Blinking sub-system initialized.");

	while (1) {

		led_toggle();

		for (i = 0; i < 3000000; i++) {	/* Wait a bit. */
			__asm__("NOP");
		}
	}

	return 0;
}
