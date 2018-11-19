library: main.o library.o space.o member.o resource.o
	g++ -std=c++14 -o library library.o main.o space.o member.o resource.o
main.o: main.cpp
	g++ -std=c++14 -c main.cpp
library.o: library.cpp
	g++ -std=c++14 -c library.cpp
space.o: space.cpp
	g++ -std=c++14 -c space.cpp
member.o: member.cpp
	g++ -std=c++14 -c member.cpp
resource.o: resource.cpp
	g++ -std=c++14 -c resource.cpp

