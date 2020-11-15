#ifndef __USB_DEVICE__
#define __USB_DEVICE__

#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/msc.h>

usbd_device *initialize_usb_device(void);

#endif //__USB_DEVICE__
