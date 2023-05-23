a.out: main.o neon_darken.o greyscale.o
	g++ -mfpu=neon main.o neon_darken.o greyscale.o -lrt

neon_darken.o: neon_darken.s
	as -mfpu=neon -o neon_darken.o neon_darken.s

greyscale.o: greyscale.s
	as -mfpu=neon -o greyscale.o greyscale.s

main.o: main.cc
	g++ -O3 -mfpu=neon -ftree-vectorize -DHAVE_NEON=1 -Dstudent_code -c -Dcimg_display=0 -fexceptions main.cc
	@#This one will compile the code using the C++ intrinsics
	@#g++ -O3 -mfpu=neon -ftree-vectorize -DHAVE_NEON=1 -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -O4 -mfpu=neon -ftree-vectorize -ftree-vectorizer-verbose=2 -DHAVE_NEON=1 -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -O4 -mfpu=neon -DHAVE_NEON=1 -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -O3 -mfpu=neon -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -O1 -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -c -Dcimg_display=0 -fexceptions main.cc
	@#g++ -c -Dcimg_display=0 -Dstudent_darken -fexceptions main.cc

clean:
	rm -rf *.o a.out output.*
