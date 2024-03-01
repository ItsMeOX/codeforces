all: compile link run

compile:
	g++ -c test.cpp

link:
	g++ test.o -o test

run:
	./test.exe