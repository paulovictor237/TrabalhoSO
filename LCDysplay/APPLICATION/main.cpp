#include <iostream>
#include <string>

#include "I2C_LCD_INTERFACE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "||| APLICAÇÃO INICIADA |||" << endl;
	lcdd displaypv;
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("APLICACAO",1,4);
	displaypv.lcd_display_string("INICIADA",2,4);
  //-----------------------------
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Linha 1",1);
	displaypv.lcd_display_string("Linha 2",2);
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever float");
	displaypv.typeFloat(13.45,2,5);
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever int");
	displaypv.typeInt(456,2,6);
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Desligar luz");
	sleep(5);
	displaypv.back_Light_OFF();
	sleep(5);
	displaypv.back_Light_ON();
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Ligar luz");
	sleep(5);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("FIM DO PROGRAMA");
	sleep(5);
  //-----------------------------
	cout << "||| FIM DA APLICAÇÃO |||" << endl;
	return 0;
}
