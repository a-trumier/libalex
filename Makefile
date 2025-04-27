# libalex makefile for my system. using risc-v and qemu,
# I cannot be bothered with writing in x86
# Alex Trumier <adtrumier@gmail.com>

.PHONY=all clean

TOOLCHAIN_PATH=/opt/riscv/bin/
PREF=$(TOOLCHAIN_PATH)riscv64-unknown-elf-
QEMU=qemu-riscv64

CC=$(PREF)gcc
AR=$(CC)-ar
CFLAGS=-Wall -Wextra -nostdlib -ffreestanding
LDFLAGS=

AS_FILES=$(wildcard src/*.s)
AS_OBJS=$(patsubst src/%.s, obj/%.o, $(AS_FILES))

C_FILES=$(wildcard src/*.c)
C_OBJS=$(patsubst src/%.c, obj/%.o, $(C_FILES))

all: libalex.a

test: test/test_driver

test/test_driver: test/test_driver.o
	$(CC) $(LDFLAGS) -o $@ $<

test/test_driver.o: test/test_driver.c
	$(CC) $(CFLAGS) -c -o $@ $<

libalex.a: $(AS_OBJS) $(C_OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf libalex.a obj/ test/*.o test/test_driver
