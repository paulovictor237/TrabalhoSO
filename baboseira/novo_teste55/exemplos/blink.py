import time
import I2C_LCD_driver
mylcd = I2C_LCD_driver.lcd()

#time (in seconds)
#To end the program, press Ctrl-C.

while True:
    mylcd.lcd_display_string(u"Hello world!")
    time.sleep(1)
    mylcd.lcd_clear()
    time.sleep(1)