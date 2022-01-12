all: mozaik mozaik.m1
mozaik: main.c
	gcc -O4 -fexpensive-optimizations -funroll-all-loops -DUSE_JPEG -I/usr/local/include -L/usr/local/lib -Wall -ansi -pedantic -o mozaik main.c -ljpeg -lc -lm
	strip -s mozaik
mozaik.m1: main.c
	gcc -O4 -DUSE_JPEG -I/opt/homebrew/include -L/opt/homebrew/lib -Wall -ansi -pedantic -o mozaik.m1 main.c -ljpeg -lc -lm
	strip ./mozaik.m1
clean:
	rm -f mozaik mozaik.m1
