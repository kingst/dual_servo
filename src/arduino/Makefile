BOARD_TAG    = uno
ARDUINO_PORT = /dev/cu.usb*
ARDUINO_LIBS = Servo

# hard coded for uno because I could not get YAML perl to work
VARIANT = standard
MCU = atmega328p
F_CPU = 16000000L
AVRDUDE_ARD_PROGRAMMER = arduino
AVRDUDE_ARD_BAUDRATE = 115200
ISP_LOCK_FUSE_PRE = 0x3F
ISP_LOCK_FUSE_POST = 0x0F
ISP_HIGH_FUSE = 0xde
ISP_LOW_FUSE = 0xff
ISP_EXT_FUSE = 0x05

include ../../../Arduino-Makefile/arduino-mk/Arduino.mk

up: build-cli/arduino.hex
	$(AVRDUDE) -D -C $(AVRDUDE_CONF) -c $(AVRDUDE_ARD_PROGRAMMER) \
		-p $(MCU) -P $(ARDUINO_PORT) -b $(AVRDUDE_ARD_BAUDRATE) -U flash:w:$<
