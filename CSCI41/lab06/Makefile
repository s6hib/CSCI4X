CXX=g++
CXXFLAGS=-g

BINARIES=hashMapTests

all: $(BINARIES)

testing.o : testing.cpp
        $(CXX) $(CXXFLAGS) -c $^

hashMapTests.o: hashMapTests.cpp hashMap.h
        $(CXX) $(CXXFLAGS) -c hashMapTests.cpp

hashMapTests: hashMapTests.o testing.o
        $(CXX) $(CXXFLAGS) $^ -o $@

clean:
        rm -f $(BINARIES) *.o