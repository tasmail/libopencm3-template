#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "logging.h"

static void usart_setup(void)
{
	/* Setup USART2 parameters. */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void initialize_log(void)
{
	/* Enable GPIOC clock for UART */
	rcc_periph_clock_enable(RCC_GPIOA);

    /* Enable clocks for USART2. */
	rcc_periph_clock_enable(RCC_USART2);

	/* Setup GPIO pins for USART2 transmit. */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

	/* Setup USART2 TX pin as alternate function. */
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);

    usart_setup();
}

void write_to_log(const char* message)
{
	char* transmitter = (char*)message;
	while(*transmitter)
		usart_send_blocking(USART2, *transmitter++);
}

void write_line_to_log(const char* message)
{
    write_to_log(message);
    write_to_log("\r\n");
}

