cmd_/usr/driver/hello/hello.ko := ld -r -m elf_i386 -T /usr/src/linux-headers-3.0.0-12-generic/scripts/module-common.lds --build-id  -o /usr/driver/hello/hello.ko /usr/driver/hello/hello.o /usr/driver/hello/hello.mod.o