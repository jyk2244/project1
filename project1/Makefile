library: main.o library.o member.o resource.o
	g++ -std=c++14 -o library library.o main.o member.o resource.o
main.o: main.cpp
	g++ -std=c++14 -c main.cpp
library.o: library.cpp
	g++ -std=c++14 -c library.cpp
member.o: member.cpp
	g++ -std=c++14 -c member.cpp
resource.o: resource.cpp
	g++ -std=c++14 -c resource.cpp

