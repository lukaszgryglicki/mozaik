#!/bin/sh
rm -rf best.lst best.dat* best_snap
mkdir best_snap
# find /data/jpg -type f -iname '*.jp*g' > best.lst
# find /data/jpg/best -type f -iname '*.jp*g' > best.lst
find /data/jpg/best/bialka -type f -iname '*.jp*g' > best.lst
# ./mozaik.dbg --generate-db best.lst --db-outfile best.dat --mode-lf --snap-dir best_snap --jqual 66 --snap-x 512 --snap-y 512 --skip-bmpin --skip-bmpout
./mozaik_mt --generate-db best.lst --db-outfile best.dat --mode-lf --snap-dir best_snap --jqual 66 --snap-x 512 --snap-y 512 --skip-bmpin --skip-bmpout
# ./mozaik --generate-db best.lst --db-outfile best.dat --mode-lf --snap-dir best_snap --jqual 66 --snap-x 512 --snap-y 512 --skip-bmpin --skip-bmpout

