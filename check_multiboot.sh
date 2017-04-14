#!/bin/sh

if grub-file --is-x86-multiboot builds/orion.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
