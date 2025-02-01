#!/bin/bash
rm -rf best.lst best.dat* best_snap
mkdir best_snap
find /data/jpg -type f -iname '*.jp*g' > best.lst
./mozaik_mt --generate-db best.lst --db-outfile best.dat --mode-lf --snap-dir best_snap --jqual 70 --snap-x 1024 --snap-y 1024 --skip-bmpin --skip-bmpout
