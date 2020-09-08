CXX=g++
CXXFLAGS=-c -Wall -fexceptions -g -fno-elide-constructors -std=c++11 -O0
TARGETS = main.o task.o

all: finish

finish: main.o task.o
	$(CXX) main.o task.o -o 2sem.out
	$> make clean

main.o: main.cpp task.cpp
	$(CXX) $(CXXFLAGS) main.cpp task.cpp


clean:
	rm $(TARGETS)
