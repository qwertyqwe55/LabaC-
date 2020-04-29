laba: main.o methods.o bilets.o list.o search.o
	g++ main.o methods.o bilets.o list.o search.o -o laba

main.o: main.cpp
	g++ -c main.cpp 
methods.o: methods.cpp
	g++ -c methods.cpp
bilets.o: bilets.cpp
	g++ -c bilets.cpp
list.o: list.cpp
	g++ -c list.cpp
search.o:
	g++ -c search.cpp
clean:
	rm *.o laba