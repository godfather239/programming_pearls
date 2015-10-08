CXX = g++
CXXFLAGS = -g -I../common

OUTPUT = main
all: $(OUTPUT)

SRC := $(wildcard *.cpp)
OBJS := $(SRC:.CPP=.o)

main : main.o
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OUTPUT) *.o
