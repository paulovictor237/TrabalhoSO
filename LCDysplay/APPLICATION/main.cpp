#include <iostream>
#include <string>

#include "I2C_LCD_INTERFACE.h"

using namespace std;


int main(int argc, char const *argv[])
{
	cout << "teste" << endl;
	//char sair;
	lcdd displaypv;
	//displaypv.lcd_clear();
	displaypv.lcd_display_string("teste do pv",2,4);
    sleep(1);
    //-----------------------------
    displaypv.lcdd::lcd_clear();
    sleep(1);
    displaypv.mover_cursor(2,3);
	sleep(1);
	displaypv.lcdd::lcd_display_string("batatinha MC'Donalds");
	sleep(1);
	displaypv.lcdd::lcd_clear();
    sleep(1);
	displaypv.mover_cursor(1,0);
	sleep(1);
	displaypv.lcdd::typeFloat(13.45);
	sleep(1);
	//VERIFICAR MOVE CURSOR
	displaypv.mover_cursor(2,8);
	sleep(1);
	displaypv.lcdd::typeInt(55,2,8);
	sleep(1);
	displaypv.lcdd::home();
	sleep(1);
	displaypv.lcdd::lcd_clear();
	displaypv.lcdd::lcd_display_string("desligar luz");
	sleep(1);
	displaypv.lcdd::back_Light_OFF();
	sleep(1);
	//displaypv.lcdd::lcd_clear();
	//displaypv.lcdd::lcd_display_string("Ligar luz");
	sleep(1);
	displaypv.lcdd::back_Light_ON();
	sleep(1);
	//displaypv.lcdd::lcd_clear();
	//displaypv.lcdd::lcd_display_string("FIM");
	sleep(5);
    //-----------------------------
    std::cout << "FIM" << endl;
	//std::cin >> sair;
	return 0;
}



