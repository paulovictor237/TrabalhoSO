// hello-kernel.c
#include <linux/module.h> // Necessario para todo modulo
#include <linux/kernel.h> // Necessario para KERNEL_INFO
int init_module(void)
{
	printk(KERN_INFO "Hello Kernel!\n");
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye Kernel!\n");
}
