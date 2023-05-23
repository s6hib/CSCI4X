BINARIES=binaryVsLinear tryStack tryQueue tryPriorityQueue tryList tryMap

all: $(BINARIES)

binaryVsLinear: binaryVsLinear.cpp timer.cpp
        g++ $^ -o $@

tryStack: tryStack.cpp
        g++ $^ -o $@

tryQueue: tryQueue.cpp
        g++ $^ -o $@

tryPriorityQueue: tryPriorityQueue.cpp
        g++ $^ -o $@

tryList: tryList.cpp
        g++ $^ -o $@

tryMap: tryMap.cpp
        g++ $^ -o $@

clean:
        rm -f $(BINARIES)