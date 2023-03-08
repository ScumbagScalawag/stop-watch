pp1: pp1.o runner.o emptystack.o
	g++ -o pp1 pp1.o runner.o emptystack.o customStack.o

pp1.o: pp1.cpp 
	g++ -c pp1.cpp

runner.o: runner.cpp 
	g++ -c runner.cpp

emptystack.o: emptystack.cpp
	g++ -c emptystack.cpp

customStack.o: customStack.cpp
	g++ -c customStack.cpp

clean:
	rm *.o pp1
