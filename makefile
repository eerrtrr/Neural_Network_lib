neuralNetworkTest: main.o neuralNetwork.o matrix.o
	gcc -o exe main.o neuralNetwork.o matrix.o

main.o : main.c neuralNetwork.h matrix.h
	gcc -c -Wall main.c

neuralNetwork.o : neuralNetwork.c neuralNetwork.h matrix.h
	gcc -c -Wall neuralNetwork.c

matrix.o : matrix.c matrix.h
	gcc -c -Wall matrix.c
	
rm :
	rm *.o

