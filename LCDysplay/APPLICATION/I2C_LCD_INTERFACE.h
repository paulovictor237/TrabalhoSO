#ifndef I2C_LCD_INTERFACE_h
#define I2C_LCD_INTERFACE_h

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
#define LCD_NOBACKLIGHT     0x00
#define LCD_CURSORSHIFT 	0x10

//write(fd, "ABCDEFGHIJKLMNOPQRSTUVXZ", 0);	sleep(3); if(g_stop == 'q') break;

class lcdd{
public:
    /**
        * Construtor
    */
    lcdd();
    /**
        * Destrutor
    */
    ~lcdd();
    /** 
        * Escreve uma String
        * line -> linha 1 - 2
        * pos -> coluna 0 - 16
    */
    void lcd_display_string(const char* palavra,unsigned int line=1,unsigned int pos=0);
    /** 
        * Escreve um  float
        * line -> linha 1 - 2
        * pos -> coluna 0 - 16
    */
    void typeFloat(float myFloat,unsigned int line=1,unsigned int pos=0);
	/** 
        * Escreve um int
        * line -> linha 1 - 2
        * pos -> coluna 0 - 16
    */
    void typeInt(int i,unsigned int line=1,unsigned int pos=0);
    /** 
        * Desliga tela
    */
    void back_Light_OFF(void);
    /** 
    * Liga tela
    */
    void back_Light_ON(void);
    /** 
        * Limpa tela
    */
   	void lcd_clear(void);
private:
    /** 
        * Retorna em linha = 1 e pos = 0
    */
    void home(void);
    /** 
        * Move o cursor
        * line -> linha 1 - 2
        * pos -> coluna 0 - 16
    */
    void mover_cursor(unsigned int line,unsigned int pos);
    
private:
    int fd;
    unsigned int cmd;
    unsigned long arg;
    unsigned long pos_new;
};

#endif
