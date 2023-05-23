a.out: main.o vfp.o
	g++ main.o vfp.o

vfp.o: vfp.s
	as -mfpu=neon -o vfp.o vfp.s

main.o: main.c
	gcc -c -O3 -mfpu=neon -ftree-vectorize -fexceptions main.c

clean:
	rm -rf *.o a.out
