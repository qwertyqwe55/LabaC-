laba: main.o methods.o bilets.o list.o 
	g++ main.o methods.o bilets.o list.o  -o laba

main.o: main.cpp
	g++ -c main.cpp 
methods.o: methods.cpp
	g++ -c methods.cpp
bilets.o: bilets.cpp
	g++ -c bilets.cpp
list.o: list.cpp
	g++ -c list.cpp
clean:
	rm *.o laba