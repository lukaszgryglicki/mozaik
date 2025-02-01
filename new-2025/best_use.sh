#!/bin/sh
echo usage best_use.sh infile outfile pixelsize snapsize
echo ./mozaik_mt --skip-bmpin --skip-bmpout --jqual 80 --mode-lf --part-x $3 --part-y $3 --snap-x $4 --snap-y $4 --snap-dir best_snap --use-db best.dat --img-infile $1 --img-outfile $2
./mozaik_mt --skip-bmpin --skip-bmpout --jqual 80 --mode-lf --part-x $3 --part-y $3 --snap-x $4 --snap-y $4 --snap-dir best_snap --use-db best.dat --img-infile $1 --img-outfile $2
