### REQUIRED ###
# OPENCM3_DIR - duh
# PROJECT - will be the basename of the output elf, eg usb-gadget0-stm32f4disco
# CFILES - basenames only, eg main.c blah.c
# CXXFILES - same for C++ files. Must have cxx suffix!
# DEVICE - the full device name, eg stm32f405ret6
#  _or_
# LDSCRIPT - full path, eg ../../examples/stm32/f4/stm32f4-discovery/stm32f4-discovery.ld
# OPENCM3_LIB - the basename, eg: opencm3_stm32f4
# OPENCM3_DEFS - the target define eg: -DSTM32F4
# ARCH_FLAGS - eg, -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
#    (ie, the full set of cpu arch flags, _none_ are defined in this file)
#
### OPTIONAL ###
# INCLUDES - fully formed -I paths, if you want extra, eg -I../shared
# BUILD_DIR - defaults to bin, should set this if you are building multiarch
# OPT - full -O flag, defaults to -Os
# CSTD - defaults -std=c99
# CXXSTD - no default.
# OOCD_INTERFACE - eg stlink-v2
# OOCD_TARGET - eg stm32f4x
#    both only used if you use the "make flash" target.
# OOCD_FILE - eg my.openocd.cfg
#    This overrides interface/target above, and is used as just -f FILE
######################################################################################

PROJECT = usb-flash
BUILD_DIR = bin

SHARED_DIR = ../logging
# SHARED_DIR += ../logging
CFILES = main.c
CFILES += logging.c

DEVICE = stm32f401cc

VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
