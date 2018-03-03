list:	main person personlist
	g++ -std=c++11 main.o person.o personlinkedlist.o -o list

person:	person.cpp person.h
	g++ -std=c++11 -c person.cpp

personlist:	person.h personlinkedlist.h personlinkedlist.cpp
	g++ -std=c++11 -c personlinkedlist.cpp

main:	main.cpp person.h personlinkedlist.h
	g++ -std=c++11 -c main.cpp

unit:	unittest person personlist
	g++ -std=c++11 unittest.o person.o personlinkedlist.o -o unit

unittest:	unittest.cpp person.h person.cpp
	g++ -std=c++11 -c unittest.cpp 

clean:
	rm *.o list
