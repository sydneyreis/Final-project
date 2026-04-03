all:
	make clothing
	make closet
	g++ clothing.o closet.o main.cpp -o main

clothing: Clothing.cpp Clothing.h
	g++ -c Clothing.cpp -o clothing.o

closet: Closet.cpp Closet.h Clothing.h
	g++ -c Closet.cpp -o closet.o

clean:
	rm -f main clothing.o closet.o