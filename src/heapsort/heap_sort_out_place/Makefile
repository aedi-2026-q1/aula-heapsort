CC = gcc -Wall -pedantic

build_dir:
	mkdir -p build

element: build_dir
	$(CC) -c element.c -o build/element.o

binary_heap: build_dir
	$(CC) -c binary_heap.c -o build/binary_heap.o

heap_sort: build_dir
	$(CC) -c heap_sort.c -o build/heap_sort.o

main: element binary_heap heap_sort
	$(CC) build/element.o build/binary_heap.o build/heap_sort.o main.c -o build/main