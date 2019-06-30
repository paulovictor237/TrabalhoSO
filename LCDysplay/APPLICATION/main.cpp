#include <iostream>
#include <string>

#include "I2C_LCD_INTERFACE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "||| APLICAÇÃO INICIADA |||" << endl;
	lcdd displaypv;
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("APLICACAO",1,4);
	displaypv.lcd_display_string("INICIADA",2,4);
  //-----------------------------
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Linha 1",1);
	displaypv.lcd_display_string("Linha 2",2);
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever float");
	displaypv.typeFloat(13.45,2,5);
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Escrever int");
	displaypv.typeInt(456,2,6);
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Desligar luz");
	sleep(3);
	displaypv.back_Light_OFF();
	sleep(3);
	displaypv.back_Light_ON();
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("Ligar luz");
	sleep(3);
	displaypv.lcd_clear();
	displaypv.lcd_display_string("FIM DO PROGRAMA");
	sleep(3);
  //-----------------------------
	cout << "||| FIM DA APLICAÇÃO |||" << endl;
	return 0;
}
