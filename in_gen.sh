#!/bin/sh
rm in.lst
rm -rf in_snap
mkdir in_snap
find in -iname "*.jp*g" > in.lst
./mozaik.m1 --generate-db in.lst --db-outfile in.dat --mode-lf --snap-dir in_snap --jqual 80 --snap-x 128 --snap-y 128 --skip-bmpin --skip-bmpout
