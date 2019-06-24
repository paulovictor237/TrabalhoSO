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
		// ioctl(fd,0x03,0);
		// ioctl(fd,0x03,0);
		// ioctl(fd,0x03,0);
		// ioctl(fd,0x02,0);
		// ioctl(fd,LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE,0);
		// ioctl(fd,LCD_DISPLAYCONTROL | LCD_DISPLAYON,0);
		// ioctl(fd,LCD_CLEARDISPLAY,0);
		// ioctl(fd,LCD_ENTRYMODESET | LCD_ENTRYLEFT,0);
		// sleep(0.2);
		write(fd, "Test session 2", 0);
		sleep(2);
	}
	~lcdd(){
		//close(fd);
	}

	void lcd_display_string(const char* palavra,unsigned int line=1,unsigned int pos=0){
		if (line == 1)pos_new = pos;
		else if (line == 2)pos_new = 0x40 + pos;
		else if (line == 3) pos_new = 0x14 + pos;
		else if (line == 4)pos_new = 0x54 + pos;
		ioctl(fd, LCD_CURSORSHIFT, pos_new);
		write(fd, palavra, 0);
		sleep(3);
	}
   	void lcd_clear(void){
		ioctl(fd, LCD_CLEARDISPLAY, 0);
   	}

private:
	int fd;
	unsigned int cmd;
	unsigned long arg;
	unsigned long pos_new;
};

int main()
{
	printf("teste\n");
	char sair;
	lcdd displaypv;
	//displaypv.lcd_clear();
	displaypv.lcd_display_string("teste do pv",2,4);
	std::cin >> sair;
	return 0;
}
