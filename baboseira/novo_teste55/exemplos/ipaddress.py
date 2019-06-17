import I2C_LCD_driver
import socket
import fcntl
import struct

#This code prints the IP address of your ethernet connection (eth0).
#To print the IP of your WiFi connection, change eth0 to wlan0 in line 18:

mylcd = I2C_LCD_driver.lcd()

def get_ip_address(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915, 
        struct.pack('256s', ifname[:15])
    )[20:24])

mylcd.lcd_display_string("IP Address:", 1) 

mylcd.lcd_display_string(get_ip_address('wlan0'), 2)
