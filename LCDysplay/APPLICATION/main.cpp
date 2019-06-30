#include <iostream>
#include <string>

#include "I2C_LCD_INTERFACE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "||| APLICAÇÃO INICIADA |||" << endl;
	lcdd displaypv;
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("APLICAÇÃO INICIADA");
  //-----------------------------
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Linha 1",1);
	displaypv.lcd_display_string("Linha 2",2);
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever um float");
	displaypv.typeFloat(13.45,2,5);
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever um int");
	displaypv.typeInt(55,2,5);
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Desligar luz");
	sleep(1);
	displaypv.back_Light_OFF();
	sleep(1);
	displaypv.back_Light_ON();
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Ligar luz");
	sleep(1);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("FIM DO PROGRAMA");
	sleep(1);
  //-----------------------------
	cout << "||| FIM DA APLICAÇÃO |||" << endl;
	return 0;
}
