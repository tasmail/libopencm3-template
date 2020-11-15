#include <libopencm3/stm32/rcc.h>

#include "logging.h"
#include "blinking.h"
#include "usb-device.h"
#include "ramdisk.h"

int main(void)
{
	rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);

	initialize_log();

	LOG_INFO("Starting...");
	LOG_INFO("Log sub-system initialized.");

	initialize_blinking();
	LOG_INFO("Blinking sub-system initialized.");

	usbd_device *usb_dev = initialize_usb_device();

	if (usb_dev) {
		LOG_INFO("USB sub-system initialized.");
	} else {
		LOG_ERR("USB sub-system initialization FAILED.");
	}

	usbd_mass_storage *usb_stg = ramdisk_init(usb_dev);
	if (usb_stg) {
		LOG_INFO("RAM disk sub-system initialized.");
	} else {
		LOG_ERR("RAM disk sub-system initialization FAILED.");
	}

	while (1) {

		led_toggle();

		usbd_poll(usb_dev);
	}

	return 0;
}
