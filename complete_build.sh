#!/bin/sh

./build.sh
echo -e  "\n"
./check_multiboot.sh
echo -e "\n"
./mk_iso.sh
qemu-system-x86_64 -cdrom builds/orion.iso
