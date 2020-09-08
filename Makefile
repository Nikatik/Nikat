CXX=g++
CXXFLAGS=-c -Wall -fexceptions -g
TARGETS = main.o

all: finish

finish: main.o
	$(CXX) -I "./build" main.o -o 1lecture.out
	$> make clean

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp 


clean:
	rm $(TARGETS)
