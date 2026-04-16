CC = gcc -Wall -pedantic

build_dir:
	mkdir -p build

element: build_dir
	$(CC) -c element.c -o build/element.o

heap_sort: build_dir
	$(CC) -c heap_sort.c -o build/heap_sort.o

main: element heap_sort
	$(CC) build/element.o build/heap_sort.o main.c -o build/main