# Makefile
TARGET_MODULE := hello
BUILDSYSTEM_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += $(TARGET_MODULE).o

# Run kernel build system to make module
all:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules

# Run kernel build system to cleanup in current directory
clean:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean
	
load:
	insmod ./$(TARGET_MODULE).ko

# Unload the module
unload:
	rmmod ./$(TARGET_MODULE).ko

# Compile and run the application test
run:
	dmesg | tail
