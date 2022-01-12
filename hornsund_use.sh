#!/bin/sh
echo usage hornsund_use.sh infile outfile pixelsize snapsize
./mozaik --skip-bmpin --skip-bmpout --jqual 80 --mode-lf --part-x $3 --part-y $3 --snap-x $4 --snap-y $4 --snap-dir hornsund_snap --use-db hornsund.dat --img-infile $1 --img-outfile $2
