# Linux Modules
These are two Linux kernel modules. 

## keylogger

This module hooks itself onto the notify_keypress event and logs every keystroke to the kernal logs.

## reboot blocker(Syscall Hook)

This module prevents the user from shutting down the system via software. 

## Build Guide

- first you need to install the linux headers
```
sudo apt-get install linux-headers-$(uname -r)
```
- then you can build the module you want by using make
```
make
```
- And finally, you can insert the module into the kernal.
```
sudo insmod keylogger.ko
```
## Additional info

- If you want to remove the module, you can use
```
sudo rmmod keylogger.ko
```
- To check if the module has started correctly, you can check the logs with:
```
sudo dmesg
```
