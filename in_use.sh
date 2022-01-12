#!/bin/sh
echo usage in_use.sh infile outfile pixelsize snapsize
echo example: ./in_use.sh p1020310 out 12 128
# ./mozaik.m1 --skip-bmpin --skip-bmpout --jqual 80 --mode-lf --part-x $3 --part-y $3 --snap-x $4 --snap-y $4 --snap-dir in_snap --use-db in.dat --img-infile $1 --img-outfile $2 --idx-file in.idx
./mozaik.m1 --skip-bmpin --skip-bmpout --jqual 80 --mode-lf --part-x $3 --part-y $3 --snap-x $4 --snap-y $4 --snap-dir in_snap --use-db in.dat --img-infile $1 --img-outfile $2
