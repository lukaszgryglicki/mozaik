#!/bin/bash
rm -rf best.lst best.dat* best_snap
mkdir best_snap
find /data/jpg/best -type f -iname '*.jp*g' > best.lst
./mozaik_mt --generate-db best.lst --db-outfile best.dat --mode-lf --snap-dir best_snap --jqual 66 --snap-x 512 --snap-y 512 --skip-bmpin --skip-bmpout
echo -n 'press enter...'
./merge_mts best
rm best.dat.?
