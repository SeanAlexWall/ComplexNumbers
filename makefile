a.out: main.o complexNum.o
	c++ main.o complexNum.o

main.o: main.cpp complexNum.h
	c++ -c main.cpp

complexNum.o: complexNum.cpp complexNum.h
	c++ -c complexNum.cpp
