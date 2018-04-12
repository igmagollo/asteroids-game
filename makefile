CC = g++
CFLAGS = -Wall
objects = Lista2D.o Fisica.o

install: main.o
	$(CC) -o asteroids main.o $(objects) -L /SFML-2.4.2/lib -lsfml-graphics -lsfml-window -lsfml-system $(CFLAGS)
	./asteroids

main.o: $(objects) main.cpp
	$(CC) -c main.cpp Lista2D.o Fisica.o -I /SFML-2.4.2/include

Lista2D.o: Lista2D.cpp Lista2D.hpp
	$(CC) -c Lista2D.cpp

Fisica.o: Fisica.cpp Fisica.hpp
	$(CC) -c Fisica.cpp

clean:
	rm main.o asteroids $(objects)