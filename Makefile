CXX=g++
CXXFLAGS=-c -Wall -fexceptions -g -fno-elide-constructors -std=c++11 -O0
TARGETS = main.o

all: finish

finish: main.o
	$(CXX) main.o -o 1lecture.out
	$> make clean

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp 


clean:
	rm $(TARGETS)
