
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "logging.h"
#include "blinking.h"

int main(void)
{
	int i, j = 0, c = 0;

	initialize_log();

	LOG_INFO("Starting...");
	LOG_INFO("Log sub-system initialized.");

	initialize_blinking();
	LOG_INFO("Blinking sub-system initialized.");

	while (1) {

		led_toggle();

		for (i = 0; i < 3000000; i++) {	/* Wait a bit. */
			__asm__("NOP");
		}
	}

	return 0;
}
