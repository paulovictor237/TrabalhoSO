// hello-kernel.c
#include <linux/init.h>
#include <linux/module.h> // Necessario para todo modulo
#include <linux/kernel.h> // Necessario para KERNEL_INFO
/**
int init_module(void)
{
	printk(KERN_INFO "Hello Kernel!\n");
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye Kernel!\n");
}
*/
static int __init helloworld_init(void) {
	pr_info("Hello world!\n");
	//printk(KERN_ALERT "Hello, world\n");
return 0;
}
static void __exit helloworld_exit(void) {
	pr_info("End of the world\n");
	//printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("John Madieu <john.madieu@gmail.com>");
MODULE_LICENSE("GPL");

