#!/bin/sh
rm hornsund.lst
rmdir hornsund_snap
mkdir hornsund_snap
ls /data/jpg/Horn/*.[jJ][pP]*[gG] > hornsund.lst
ls /data/jpg/Horn/NIR/*.[jJ][pP]*[gG] >> hornsund.lst
ls /data/jpg/Horn/VNIR/*.[jJ][pP]*[gG] >> hornsund.lst
#./mozaik --generate-db hornsund.lst --db-outfile hornsund.dat --mode-lf --snap-dir hornsund_snap --jqual 80 --snap-x 192 --snap-y 192 --skip-bmpin --skip-bmpout
./mozaik --generate-db hornsund.lst --db-outfile hornsund.dat --mode-lf --snap-dir hornsund_snap --jqual 70 --snap-x 256 --snap-y 256 --skip-bmpin --skip-bmpout
