CC = gcc -Wall -pedantic

build_dir:
	mkdir -p build

element: build_dir
	$(CC) -c element.c -o build/element.o

selection_sort: build_dir
	$(CC) -c selection_sort.c -o build/selection_sort.o

main: element selection_sort
	$(CC) build/element.o build/selection_sort.o main.c -o build/main