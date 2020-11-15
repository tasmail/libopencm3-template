
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "logging.h"

static void clock_setup(void)
{
	/* Enable GPIOC clock for LED */
	rcc_periph_clock_enable(RCC_GPIOC);
}

static void gpio_setup(void)
{
	/* Setup GPIO pin GPIO13 on GPIO port C for LED. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
}


int main(void)
{
	int i, j = 0, c = 0;

	initialize_log();

	write_line_to_log("Starting...");
	write_line_to_log("Log system initialized.");

	clock_setup();
	gpio_setup();

	/* Blink the LED (PD12) on the board with every transmitted byte. */
	while (1) {
		gpio_toggle(GPIOC, GPIO13);	/* LED on/off */
		usart_send_blocking(USART2, c + '0'); /* USART2: Send byte. */
		c = (c == 9) ? 0 : c + 1;	/* Increment c. */
		if ((j++ % 80) == 0) {		/* Newline after line full. */
			write_to_log("\r\nHello World!!!\r\n");
		}
		for (i = 0; i < 150000; i++) {	/* Wait a bit. */
			__asm__("NOP");
		}
	}

	return 0;
}
