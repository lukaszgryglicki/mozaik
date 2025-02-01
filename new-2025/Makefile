all: mozaik mozaik_mt mozaik.dbg mozaik_mt.dbg merge_mts
mozaik: main.c
	gcc -DUSE_JPEG -I/usr/local/include -L/usr/local/lib -Wall -ansi -pedantic -o mozaik main.c -ljpeg -lc -lm
	strip -s mozaik
mozaik.dbg: main.c
	gcc -g -DUSE_JPEG -I/usr/local/include -L/usr/local/lib -Wall -ansi -pedantic -o mozaik.dbg main.c -ljpeg -lc -lm -lefence
mozaik_mt: main_mt.c
	gcc -DUSE_JPEG -I/usr/local/include -L/usr/local/lib -o mozaik_mt main_mt.c -ljpeg -lc -lm
	strip -s mozaik_mt
mozaik_mt.dbg: main_mt.c
	gcc -DUSE_JPEG -I/usr/local/include -L/usr/local/lib -g -o mozaik_mt.dbg main_mt.c -ljpeg -lc -lm -lefence
merge_mts: merge_mts.c
	gcc -Wall -ansi -pedantic -o merge_mts merge_mts.c -lc
	strip -s merge_mts
