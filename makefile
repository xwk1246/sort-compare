all: main.o data_generator.o quicksort.o mergesort.o heapsort.o
	gcc main.o data_generator.o quicksort.o mergesort.o heapsort.o -o main

main.o: main.c
	gcc -c main.c -o main.o

data_generator.o: data_generator.c data_generator.h
	gcc -c data_generator.c -o data_generator.o

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c -o quicksort.o

mergesort.o: mergesort.c mergesort.h
	gcc -c mergesort.c -o mergesort.o

heapsort.o: heapsort.c heapsort.h
	gcc -c heapsort.c -o heapsort.o

clean:
	rm -f data_generator.o quicksort.o mergesort.o heapsort.o main.o main
	