
#include "I2C_LCD_INTERFACE.h"
/**
    * Construtor
*/
lcdd::lcdd(){
	fd = open("/dev/lcdisplay", O_RDWR);
	if(fd < 0){
		cout << "WARNING: failed to open the device!" << endl;
	}
	write(fd, "LCD Iniciado", 0);
	// sleep(2);
}
/**
    * Destrutor
*/
lcdd::~lcdd(){
	//close(fd);
}
/**
    * Move o cursor
    * line -> linha 1 - 2
    * pos -> coluna 0 - 16
*/
void lcdd::mover_cursor(unsigned int line,unsigned int pos){
	if (line == 1)pos_new = pos;
	else if (line == 2)pos_new = 0x40 + pos;
	else if (line == 3) pos_new = 0x14 + pos;
	else if (line == 4)pos_new = 0x54 + pos;
	ioctl(fd, LCD_CURSORSHIFT, 0x80 +  pos_new);
}
/**
    * Escreve uma String
    * line -> linha 1 - 2
    * pos -> coluna 0 - 16
*/
void lcdd::lcd_display_string(const char* palavra,unsigned int line,unsigned int pos){
	mover_cursor(line,pos);
	write(fd, palavra, 0);
	// sleep(3);
}
/**
	* Escreve um  float
    * line -> linha 1 - 2
    * pos -> coluna 0 - 16
*/
void lcdd::typeFloat(float myFloat,unsigned int line,unsigned int pos){
	char buffer[20];
	sprintf(buffer, "%4.2f",  myFloat);
	lcd_display_string(buffer,line,pos);
}
/**
    * Escreve um int
    * line -> linha 1 - 2
    * pos -> coluna 0 - 16
*/
void lcdd::typeInt(int i,unsigned int line,unsigned int pos){
	char array1[20];
	sprintf(array1, "%d",  i);
	lcd_display_string(array1,line,pos);
}
/**
    * Retorna em linha = 1 e pos = 0
*/
void lcdd::home(void){
	ioctl(fd, LCD_RETURNHOME, 0);
}
/**
    * Desliga tela
*/
void lcdd::back_Light_OFF(void){
	ioctl(fd, LCD_NOBACKLIGHT, 0);
}
/**
    * Liga tela
*/
void lcdd::back_Light_ON(void){
	ioctl(fd, LCD_BACKLIGHT, 1);
	// ioctl(fd, LCD_BACKLIGHT, 1);
}
/**
    * Limpa tela
*/
void lcdd::lcd_clear(void){
	ioctl(fd, LCD_CLEARDISPLAY, 0);
}
