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

using namespace std;

// #define # comman
#define LCD_CLEARDISPLAY 	0x01
#define LCD_RETURNHOME 		0x02
#define LCD_BACKLIGHT 		0x08
#define LCD_CURSORSHIFT 	0x10

//write(fd, "ABCDEFGHIJKLMNOPQRSTUVXZ", 0);	sleep(3); if(g_stop == 'q') break;

class lcdd{
public:
	lcdd(){
		fd = open("/dev/lcdisplay", O_RDWR);
		if(fd < 0){
			cout << "WARNING: failed to open the device!" << endl;
		}
		write(fd, "LCD Iniciado", 0);
		sleep(2);
	}
	~lcdd(){
		//close(fd);
	}
	
	void mover_cursor(unsigned int line,unsigned int pos){
		if (line == 1)pos_new = pos;
		else if (line == 2)pos_new = 0x40 + pos;
		else if (line == 3) pos_new = 0x14 + pos;
		else if (line == 4)pos_new = 0x54 + pos;
		ioctl(fd, LCD_CURSORSHIFT, 0x80 +  pos_new);
	}


	void lcd_display_string(const char* palavra,unsigned int line=1,unsigned int pos=0){
		mover_cursor(line,pos);
		write(fd, palavra, 0);
		sleep(3);
	}

	void typeFloat(float myFloat,unsigned int line=1,unsigned int pos=0)){
	  char buffer[20];
	  sprintf(buffer, "%4.2f",  myFloat);
	  lcd_display_string(buffer,line,pos);
	}

	// int to string
	void typeInt(int i,unsigned int line=1,unsigned int pos=0))   {
	  char array1[20];
	  sprintf(array1, "%d",  i);
	  lcd_display_string(array1,line,pos);
	}

	void home(void){
		ioctl(fd, LCD_RETURNHOME, 0);
   	}

	void black_Light(void){
		ioctl(fd, LCD_BACKLIGHT, 0);
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
