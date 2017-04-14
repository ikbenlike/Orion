#!/bin/sh
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
    (cd $PROJECTS && $MAKE clean)
done

rm -rf sysroot
rm -rf isodir
rm -rf orion.iso
