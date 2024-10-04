all: compile link run

compile:
	g++ -c main.cpp

link:
	g++ main.o -o main

run:
	./main.exe