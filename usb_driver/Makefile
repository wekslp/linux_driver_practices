obj-m := cp210x.o

KDIR := /usr/src/linux-headers-`uname -r`
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko .*cmd modules.* Module.* .tmp_versions *.mod.c test
