#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/slab.h>
#define  DEVICE_NAME "filec"    ///< The device will appear at /dev/ebbchar using this value
#define  CLASS_NAME  "ebb"

static int majorNumber;
static char * message;
static short size_of_message;
static int numberOpens;
static int dev_open(struct inode *, struct file *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
static struct file_operations fops =
{
	.open = dev_open,
	.write = dev_write,
};
static int __init hello(void)
{
	printk(KERN_ALERT "Running file corrupter\n");
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
	if(majorNumber<0)
		{
			printk(KERN_ALERT "Failure to register");
			return majorNumber;
		}
	printk(KERN_ALERT "FC registered with %d\n", majorNumber);
	return 0;
}
static int dev_open(struct inode * inodeptr, struct file * fileptr)
{

	return 0;
}
static ssize_t dev_write(struct file * fileptr, const char * ccharptr, size_t size, loff_t * offset)
{
	message = (char *) kmalloc(size, GFP_KERNEL);
	printk(KERN_ALERT "WRITE");
	strcpy(message, ccharptr);
	return 0;
}
static void __exit goodbye(void)
{
	printk(KERN_ALERT "Goodbye world\n");
	unregister_chrdev(majorNumber, DEVICE_NAME);
	return;
}
module_init(hello);
module_exit(goodbye);
MODULE_LICENSE("GPL");