main.out: main.o Matriz.o
	g++ main.o Matriz.o -o main.out
main.o: main.cpp Matriz.cpp
	g++ -c main.cpp