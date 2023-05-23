a.out: main.o get.o set.o alloc.o free.o
	g++ -O3 main.o get.o set.o alloc.o free.o

alloc.o: alloc.s
	as -o alloc.o alloc.s

free.o: free.s
	as -o free.o free.s

set.o: set.s
	as -o set.o set.s

get.o: get.s
	as -o get.o get.s

main.o: main.cc
	g++ -c -o main.o -std=c++17 main.cc

clean: 
	rm -f a.out core *.o
