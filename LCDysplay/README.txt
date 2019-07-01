====================================================================
Driver para um display LCD utilizando comunicação I2C em uma Raspberry Pi.

:Autor: Paulo Victor Duarte
:Autor: Matheus Luiz Anderle de Souza

Universidade Federal de Santa Catarina (Campus Joinville)
EMB5632(20191) - Sistemas Operacionais

COMANDOS
====================================================================

Inicie o terminal na pasta /LCDysplay.

--------------------------------------------------------------------
Compilar o módulo:
	$ sudo make
--------------------------------------------------------------------
Carregar o módulo no kernel:
	$ sudo make load
--------------------------------------------------------------------
Descarregar o módulo do kernel:
	$ sudo make unload
--------------------------------------------------------------------
Remover os arquivos gerados pelo módulo:
	$ sudo make clean
--------------------------------------------------------------------
Mostrar System Calls do Driver
	$ make print
--------------------------------------------------------------------
Mostrar informações do Driver
	$ make info
--------------------------------------------------------------------
Mostrar modulos ativos no kernel
	$ make modulos
--------------------------------------------------------------------
Rodar Aplicação
	$ make app
