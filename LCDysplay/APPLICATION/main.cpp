#include <iostream>
#include <string>

#include "I2C_LCD_INTERFACE.h"

using namespace std;


int main(int argc, char const *argv[])
{
	cout << "teste" << endl;
	char sair;
	lcdd displaypv;
	//displaypv.lcd_clear();
	displaypv.lcd_display_string("teste do pv",2,4);
    sleep(3);
	std::cin >> sair;
	return 0;
}