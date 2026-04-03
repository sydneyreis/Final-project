all:
	make clothing
	g++ clothing.o main.cpp -o main

clothing: Clothing.cpp Clothing.h
	g++ -c Clothing.cpp -o clothing.o

clean:
	rm -f main clothing.o closet.o