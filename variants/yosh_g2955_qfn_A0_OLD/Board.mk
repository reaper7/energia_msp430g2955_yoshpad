######################################
# Board specific
ARCH = msp430
MCU = msp430g2955
MCU_FLAG = -mmcu=$(MCU)
F_CPU = 16000000L
FLASH_SIZE = 57088
UPLOAD_COMMAND = $(MSPDEBUG) $(VERBOSE_UPLOAD) tilib --force-reset "prog build/$(SKETCH_NAME).bin"
######################################
