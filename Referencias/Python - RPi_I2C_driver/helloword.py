import I2C_LCD_driver
from time import *

mylcd = I2C_LCD_driver.lcd()

# comentario
# sys.path.append('/home/user/python-libs')
# mylcd.lcd_display_string("Hello World!", 2, 3)
# 16 x 2 LCD the rows are numbered 1 - 2.
# while the columns are numbered 0 - 15.

mylcd.lcd_display_string("Hello World!", 1)
mylcd.lcd_display_string("Hello World!", 2, 3)