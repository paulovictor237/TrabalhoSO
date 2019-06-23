// # # -*- coding: utf-8 -*-
// # # Original code found at:
// # # https://gist.github.com/DenisFromHR/cc863375a6e19dce359d

// # """
// # Compiled, mashed and generally mutilated 2014-2015 by Denis Pleic
// # Made available under GNU GENERAL PUBLIC LICENSE

// # # Modified Python I2C library for Raspberry Pi
// # # as found on http://www.recantha.co.uk/blog/?p=4849
// # # Joined existing 'i2c_lib.py' and 'lcddriver.py' into a single library
// # # added bits and pieces from various sources
// # # By DenisFromHR (Denis Pleic)
// # # 2015-02-10, ver 0.1

// # """

// # # i2c bus (0 -- original Pi, 1 -- Rev 2 Pi)
// # I2CBUS = 1

// # # LCD Address
// # ADDRESS = 0x27

// # import smbus
// # from time import sleep

// # class i2c_device:
// #    def __init__(self, addr, port=I2CBUS):
// #       self.addr = addr
// #       self.bus = smbus.SMBus(port)

// # # Write a single command
// #    def write_cmd(self, cmd):
// #       self.bus.write_byte(self.addr, cmd)
// #       sleep(0.0001)

// # # Write a command and argument
// #    def write_cmd_arg(self, cmd, data):
// #       self.bus.write_byte_data(self.addr, cmd, data)
// #       sleep(0.0001)

// # # Write a block of data
// #    def write_block_data(self, cmd, data):
// #       self.bus.write_block_data(self.addr, cmd, data)
// #       sleep(0.0001)

// # # Read a single byte
// #    def read(self):
// #       return self.bus.read_byte(self.addr)

// # # Read
// #    def read_data(self, cmd):
// #       return self.bus.read_byte_data(self.addr, cmd)

// # # Read a block of data
// #    def read_block_data(self, cmd):
// #       return self.bus.read_block_data(self.addr, cmd)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include <iostream>
#include <sys/ioctl.h> /* ioctl */

// #define # comman
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80
// #define # fla for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00
// #define # fla for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00
// #define # fla for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00
// #define # fla for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00
// #define # fla for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00
#define En 0b00000100 //# Enable bit
#define Rw 0b00000010 //# Read/Write bit
#define Rs 0b00000001 //# Register select bit



//write(fd, "ABCDEFGHIJKLMNOPQRSTUVXZ", 0);	sleep(3); if(g_stop == 'q') break;

class lcdd{
public:
	lcdd(){
		fd = open("/dev/lcdisplay", O_RDWR);
		
		ioctl(fd,0x03,0);
		ioctl(fd,0x03,0);
		ioctl(fd,0x03,0);
		ioctl(fd,0x02,0);

		ioctl(fd,LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE,0);
		ioctl(fd,LCD_DISPLAYCONTROL | LCD_DISPLAYON,0);
		ioctl(fd,LCD_CLEARDISPLAY,0);
		ioctl(fd,LCD_ENTRYMODESET | LCD_ENTRYLEFT,0);
		sleep(0.2);
		
		write(fd, "Test session 2", 0);
		sleep(2);
	}
	~lcdd(){
		//close(fd);
	}

	void caralho(const char* palavra,int line=2,int pos=0){
		if (line == 1)pos_new = pos;
		else if (line == 2)pos_new = 0x40 + pos;
		else if (line == 3) pos_new = 0x14 + pos;
		else if (line == 4)pos_new = 0x54 + pos;
		ioctl(fd, LCD_CLEARDISPLAY, 0);
		ioctl(fd, 0x80 + 0x54, 0);
		write(fd, palavra, 0x80);
		sleep(3);
	}
private:
	int fd;
	unsigned int pos_new;
};

int main()
{
	printf("teste\n");
	char sair;
	lcdd displaypv;
	displaypv.caralho("teste do pv");
	std::cin >> sair;
	return 0;
}




// # class lcd:
// #    #initializes objects and lcd
// #    def __init__(self):
// #       self.lcd_device = i2c_device(ADDRESS)

// #       self.lcd_write(0x03)
// #       self.lcd_write(0x03)
// #       self.lcd_write(0x03)
// #       self.lcd_write(0x02)

// #       self.lcd_write(LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE)
// #       self.lcd_write(LCD_DISPLAYCONTROL | LCD_DISPLAYON)
// #       self.lcd_write(LCD_CLEARDISPLAY)
// #       self.lcd_write(LCD_ENTRYMODESET | LCD_ENTRYLEFT)
// #       sleep(0.2)


// #    # clocks EN to latch command
// #    def lcd_strobe(self, data):
// #       self.lcd_device.write_cmd(data | En | LCD_BACKLIGHT)
// #       sleep(.0005)
// #       self.lcd_device.write_cmd(((data & ~En) | LCD_BACKLIGHT))
// #       sleep(.0001)

// #    def lcd_write_four_bits(self, data):
// #       self.lcd_device.write_cmd(data | LCD_BACKLIGHT)
// #       self.lcd_strobe(data)

// #    # write a command to lcd
// #    def lcd_write(self, cmd, mode=0):
// #       self.lcd_write_four_bits(mode | (cmd & 0xF0))
// #       self.lcd_write_four_bits(mode | ((cmd << 4) & 0xF0))

// #    # write a character to lcd (or character rom) 0x09: backlight | RS=DR<
// #    # works!
// #    def lcd_write_char(self, charvalue, mode=1):
// #       self.lcd_write_four_bits(mode | (charvalue & 0xF0))
// #       self.lcd_write_four_bits(mode | ((charvalue << 4) & 0xF0))
  
// #    # put string function with optional char positioning
// #    def lcd_display_string(self, string, line=1, pos=0):
// #     if line == 1:
// #       pos_new = pos
// #     elif line == 2:
// #       pos_new = 0x40 + pos
// #     elif line == 3:
// #       pos_new = 0x14 + pos
// #     elif line == 4:
// #       pos_new = 0x54 + pos

// #     self.lcd_write(0x80 + pos_new)

// #     for char in string:
// #       self.lcd_write(ord(char), Rs)

// #    # clear lcd and set to home
// #    def lcd_clear(self):
// #       self.lcd_write(LCD_CLEARDISPLAY)
// #       self.lcd_write(LCD_RETURNHOME)

// #    # define backlight on/off (lcd.backlight(1); off= lcd.backlight(0)
// #    def backlight(self, state): # for state, 1 = on, 0 = off
// #       if state == 1:
// #          self.lcd_device.write_cmd(LCD_BACKLIGHT)
// #       elif state == 0:
// #          self.lcd_device.write_cmd(LCD_NOBACKLIGHT)

// #    # add custom characters (0 - 7)
// #    def lcd_load_custom_chars(self, fontdata):
// #       self.lcd_write(0x40);
// #       for char in fontdata:
// #          for line in char:
// #             self.lcd_write_char(line)         
         
