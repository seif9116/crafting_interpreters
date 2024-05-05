HelloWorld: HelloWorld.java
	javac HelloWorld.java
doublyLinked.o: doublyLinked.c doublyLinked.h
	gcc -Wall -c doublyLinked.c -o doublyLinked.o
main: doublyLinked.o main.c
	gcc -Wall main.c doublyLinked.o -o main
debug: main.c doublyLinked.c
	gcc -g -Wall main.c doublyLinked.c -o main_debug
