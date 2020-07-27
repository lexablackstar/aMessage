serverapp: NetworkManager.o main.o
	g++ -o serverapp NetworkManager.o main.o

NetworkManager.o: NetworkManager.cpp
	g++ -o NetworkManager.o -c NetworkManager.cpp	

main.o: main.cpp
	g++ -o main.o -c main.cpp	

clean:
	rm -f serverapp *.o		