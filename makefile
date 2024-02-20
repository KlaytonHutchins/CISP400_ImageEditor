CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
EXENAME= ImageEditor

default: lodepng.o picture.o ImageEditor.o main.o
	$(CC) lodepng.o picture.o ImageEditor.o main.o -o $(EXENAME)

lodepng.o: lodepng.cpp
	$(CC) $(CFLAGS) lodepng.cpp

picture.0: picture.cpp
	$(CC) $(CFLAGS) picture.cpp

ImageEditor.0: ImageEditor.cpp
	$(CC) $(CFLAGS) ImageEditor.cpp

main.0: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
