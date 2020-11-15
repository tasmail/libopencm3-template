#ifndef __RAMDISK_H
#define __RAMDISK_H

#include <stdint.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/msc.h>

extern usbd_mass_storage *ramdisk_init(usbd_device * usb_device);
extern int ramdisk_read(uint32_t lba, uint8_t *copy_to);
extern int ramdisk_write(uint32_t lba, const uint8_t *copy_from);
extern int ramdisk_blocks(void);

#endif
