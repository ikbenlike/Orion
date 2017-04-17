#!/bin/sh
set -e
. ./iso.sh

qemu-system-x86_64 -cdrom orion.iso -serial file:logfile.log
