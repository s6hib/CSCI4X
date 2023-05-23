a.out: prime_check.o search_loop.o
	g++ -O3 prime_check.o search_loop.o

prime_check.o: prime_check.cc
	g++ -c -o prime_check.o -std=c++17 prime_check.cc

search_loop.o: search_loop.cc
	g++ -c -o search_loop.o -std=c++17 search_loop.cc

clean:
	rm -f a.out core *.o
