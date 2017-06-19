/** usb driver practice 
 *  To understand how to regsiter a usb device.
 */
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/vmalloc.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/input.h>
#include <asm/io.h>
#include <linux/usb.h>

#define DRIVER_DESC		"CP210x driver for practice"

#define CP210X_VENDOR_ID	0x10C4
#define CP210X_DEVICE_ID	0xEA60

int cp210x_probe(struct usb_interface *intf, const struct usb_device_id *id) {
	printk(KERN_INFO "%s\n", __FUNCTION__);
	return -1;
}

static const struct usb_device_id id_table[] = {
	{ USB_DEVICE(CP210X_VENDOR_ID, CP210X_DEVICE_ID) },
	{ }
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver cp210x_driver = {
	.name =			"cp210x",
	.probe =		cp210x_probe,
	.id_table =		id_table,
};

int cp210x_init_module(void)
{
	int retval;
	retval = usb_register(&cp210x_driver);
	if (retval) {
		printk(KERN_ALERT "usb register failed\n");
		return retval;
	}
	printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_DESC "\n");
	return 0;
}

void cp210x_cleanup_module(void)
{
	usb_deregister(&cp210x_driver);
	printk(KERN_ALERT "cp210x module: unregisterd.\n");
}

module_init(cp210x_init_module);
module_exit(cp210x_cleanup_module);

MODULE_LICENSE("GPL");
