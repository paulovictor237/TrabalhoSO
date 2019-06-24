#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x90b4ce31, "module_layout" },
	{ 0x407d0233, "try_module_get" },
	{ 0xe92db5d9, "module_put" },
	{ 0xe346f67a, "__mutex_init" },
	{ 0xdc791e51, "cdev_add" },
	{ 0x2fb24008, "cdev_init" },
	{ 0x7ed07774, "devm_kmalloc" },
	{ 0x91c1cf9f, "i2c_del_driver" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x45a2790f, "i2c_unregister_device" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3670886b, "i2c_put_adapter" },
	{ 0xc6d76ea5, "i2c_register_driver" },
	{ 0xa9480141, "i2c_new_device" },
	{ 0x1e4f164d, "i2c_get_adapter" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x67ea780, "mutex_unlock" },
	{ 0xdc165e81, "mutex_lock_interruptible" },
	{ 0xef839987, "i2c_smbus_write_byte" },
	{ 0x8e865d3c, "arm_delay_ops" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x7c32d0f0, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:lcdisplay");

MODULE_INFO(srcversion, "4D839E9214AE0C786728287");
