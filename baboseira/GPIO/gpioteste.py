import RPi.GPIO as GPIO
import time


from tkinter import *
class Application:
def __init__(self, master=None):
      self.widget1 = Frame(master)
      self.widget1.pack()
      self.msg = Label(self.widget1, text="Primeiro widget")
      self.msg.pack ()
root = Tk()
Application(root)
root.mainloop()

#GPIO.cleanup()
GPIO.setmode(GPIO.BCM)

BOTAO_APERTAR = 21
LED_SAIDA = 20
TEMPO_DELAY_MS = 100
PERIODO = 1000

tempo_espera = TEMPO_DELAY_MS / PERIODO

GPIO.setup(BOTAO_APERTAR, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED_SAIDA, GPIO.OUT)
GPIO.output(LED_SAIDA, 1)

while True:
    leitura = not GPIO.input(BOTAO_APERTAR)
    print (leitura)
    GPIO.output(LED_SAIDA, leitura)
    time.sleep(tempo_espera)


