a.out: main.o rainfall.o
	g++ -g main.o rainfall.o

main.o: main.cc
	g++ -c -g main.cc

rainfall.o: rainfall.s
	g++ -c -g rainfall.s

clean:
	rm -rf a.out core *.o
