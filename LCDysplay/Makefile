TARGET_MODULE := lcdisplay

BUILDSYSTEM_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += $(TARGET_MODULE).o

# Run kernel build system to make module
all:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules

# Run kernel build system to cleanup in current directory
clean:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean

# Load the module
load:
	insmod ./$(TARGET_MODULE).ko
	sudo chmod 777 load.sh
	sudo ./load.sh

# Unload the module
unload:
	rmmod ./$(TARGET_MODULE).ko
	sudo chmod 777 unload.sh
	sudo ./unload.sh

# Mostrar System Calls do Driver
print:
	dmesg | tail

# Mostrar informações do Driver
info:
	modinfo ./$(TARGET_MODULE).ko

# Mostrar modulos ativos no kernel
modulos:
	lsmod

# Rodar Aplicação
app:
	cd APPLICATION; \
    g++ *.cpp -o Executavel -pthread; \
    ./Executavel
