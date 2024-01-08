# Makefile for building programs for Arduino MKR Vidor 4000
# Using Atmel's ASF for most libc / syscall implementations
# 
# Also includes target 'flash' which uses BOSSA to write to flash


# Location of ASF_ROOT may be private so obtain from .gitignored file
# Similarly, set VIDOR_PORT there
include .make.local

# ARM GNU details
arm_gnu_stem = arm-none-eabi-
AR = $(arm_gnu_stem)ar
AS = $(arm_gnu_stem)as
GCC = $(arm_gnu_stem)gcc
GDB = $(arm_gnu_stem)gdb
LD = $(arm_gnu_stem)ld
NM = $(arm_gnu_stem)nm
OBJCOPY = $(arm_gnu_stem)objcopy
OBJDUMP = $(arm_gnu_stem)objdump
READELF = $(arm_gnu_stem)readelf

# Flags
CFLAGS := -Wall -mtune=cortex-m0plus -mcpu=cortex-m0plus -marm
COBJFLAGS := $(CLFAGS) -c

# Dirs
INCLUDE_DIR_PRJ = include
SRC_DIR_PRJ = src
BIN_DIR_PRJ = bin
TOOLS_DIR_PRJ = tools

# ASF_INCLUDE = \
# 	${ASF_ROOT}/common/services/clock \
# 	${ASF_ROOT}/common/services/usb \
# 	${ASF_ROOT}/common/services/usb/udc \
# 	${ASF_ROOT}/common/services/usb/uhc \
# 	${ASF_ROOT}/common/services/delay \
# 	${ASF_ROOT}/common/utils \
# 	${ASF_ROOT}/common/utils/stdio/stdio_usb \
# 	${ASF_ROOT}/sam0/drivers/usb \
# 	${ASF_ROOT}/sam0/drivers/system/clock/clock_samd21_r21_da_ha1 \
# 	${ASF_ROOT}/sam0/drivers/system/power/power_sam_d_r_h \
# 	${ASF_ROOT}/sam0/drivers/system/power \


ASF_SRC = $(ASF_ROOT)/sam0/utils/syscalls/gcc/syscalls.c
ASF_OBJ := $(addprefix $(BIN_DIR_PRJ)/asf/, $(addsuffix .o, $(notdir $(basename $(ASF_SRC)))))

SRC := $(foreach x, $(SRC_DIR_PRJ), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(BIN_DIR_PRJ)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

TARGET := $(BIN_DIR_PRJ)/embedded.elf

# Bossa 
BOSSA = $(TOOLS_DIR_PRJ)/bossa/bossac
BOSSAFLAGS = -i -d --port=$(VIDOR_PORT)

default: all

$(TARGET): $(OBJ) $(ASF_OBJ)
	$(GCC) -o $@ $(OBJ) $(ASF_OBJ) $(CFLAGS)

$(BIN_DIR_PRJ)/%.o: $(SRC_DIR_PRJ)/%.c*
	$(GCC) $(COBJLAGS) -c -o $@ $<

$(ASF_OBJ): $(ASF_SRC)
	$(GCC) $(COBJFLAGS) -o $@ $<

.PHONY: all
all: $(TARGET)

.PHONY: flash 
flash: all 
	@echo FLASH $(TARGET)
	$(BOSSA) $(BOSSAFLAGS) -e -w -v $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(BIN_DIR_PRJ)
	@rm -f $(BIN_DIR_PRJ)
