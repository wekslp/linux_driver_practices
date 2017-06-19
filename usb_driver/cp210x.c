/** usb driver practice 
 *  To understand how to regsiter a usb device.
 *
 *  1. Use usb_serial_driver to register device. Must insert usbserial module first.
 */
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/tty.h>
#include <linux/tty_driver.h>
#include <linux/tty_flip.h>
#include <linux/serial.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/spinlock.h>
#include <linux/uaccess.h>
#include <linux/usb.h>
#include <linux/usb/serial.h>
#include <asm/unaligned.h>

#define DRIVER_DESC		"CP210x driver for practice"

#define CP210X_VENDOR_ID	0x10C4
#define CP210X_DEVICE_ID	0xEA60



static const struct usb_device_id id_table[] = {
	{ USB_DEVICE(CP210X_VENDOR_ID, CP210X_DEVICE_ID) },
	{ }
};

MODULE_DEVICE_TABLE(usb, id_table);

static int cp210x_probe(struct usb_serial *serial, const struct usb_device_id *id)
{
	printk(KERN_INFO "cp210x_probe\n");
	return -1;
}

static void cp210x_disconnect(struct usb_serial *serial)
{
	printk(KERN_INFO "cp210x disconnect\n");
	return -1;
}

static void cp210x_release(struct usb_serial *serial)
{
	printk(KERN_INFO "cp210x release\n");
	return -1;
}

static struct usb_serial_driver cp210x_device = {
	.driver = {
		.owner =THIS_MODULE,
		.name ="cp210x driver practice",
	},
	.id_table =		id_table,
	.probe =		cp210x_probe,
	.disconnect =		cp210x_disconnect,
	.release =		cp210x_release,
};

static struct usb_serial_driver * const serial_drivers[] = {
    &cp210x_device, NULL
};

module_usb_serial_driver(serial_drivers, id_table);
/*
static struct usb_driver cp210x_driver = {
	.name =			"cp210x",
	.probe =		usb_serial_probe,
	.id_table =		id_table,
	.disconnect =		usb_serial_disconnect,
	.suspend =		usb_serial_suspend,
	.resume =		usb_serial_resume,
};

int cp210x_probe(struct usb_interface *intf, const struct usb_device_id *id) {
	printk(KERN_INFO "%s\n", __FUNCTION__);
	return -1;
}

int cp210x_init_module(void)
{
	int retval;
	retval = usb_serial_register_drivers(&cp210x_serial_driver, "cp210x serial driver", id_table);
	if (retval) {
		printk(KERN_ALERT "usb serial register failed\n");
		return retval;
	}
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
	usb_serial_deregister_drivers(&cp210x_serial_driver);
	printk(KERN_ALERT "cp210x module: unregisterd.\n");
}

module_init(cp210x_init_module);
module_exit(cp210x_cleanup_module);
*/
MODULE_LICENSE("GPL");
