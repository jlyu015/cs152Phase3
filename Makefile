CC = g++
CFLAGS = -g -O0 -std=c++11

SRC  = lib.cpp                        # list of C++ source files
OBJS = $(patsubst %.cpp, %.o, $(SRC)) # list of object files


miniL: miniL-lex.o miniL-parser.o $(OBJS)
	$(CC) $^ -o $@ -lfl

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

miniL-lex.cpp: miniL.lex miniL-parser.cpp
	flex -o $@ $< 

miniL-parser.cpp: miniL.y
	bison -d -v -g -o $@ $<


miniL: miniL.lex miniL.y
	bison -d -v --file-prefix=y miniL.y
	flex miniL.lex
	g++ $(CFLAGS) lex.yy.c y.tab.c -lfl -o phase3
	rm -f lexy.yy.c *.output *.tab.c 
	cat ./testFiles/fibonacci.min | ./phase3

test: miniL
	cat ./testfiles/fibonacci.min | ./phase3
clean:
	rm -f *.o miniL-lex.cpp miniL-parser.cpp miniL-parser.hpp stack.hh *.output *.dot miniL