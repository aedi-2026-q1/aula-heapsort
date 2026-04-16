# Aula - Selection Sort e Heap Sort

Este repositório contém o código-base da aula sobre algoritmos de ordenação, com foco em:

- Selection Sort
- Heap Sort in-place
- Heap Sort out-of-place (com heap binario auxiliar)

## Aviso importante

Este material está intencionalmente incompleto.

Trata-se de starter code para uso em aula, para ser preenchido e discutido durante as atividades.
Alguns trechos podem estar parciais, com implementações faltando, ou ainda em formato de esqueleto.

## Estrutura do projeto

```
src/
    selection_sort/
        element.c
        element.h
        selection_sort.c
        selection_sort.h
        main.c
        Makefile

    heapsort/
        heap_sort_in_place/
            element.c
            element.h
            heap_sort.c
            heap_sort.h
            main.c
            Makefile

        heap_sort_out_place/
            binary_heap.c
            binary_heap.h
            element.c
            element.h
            heap_sort.c
            heap_sort.h
            main.c
            Makefile
```

## Compilação e execução

Cada variação possui seu próprio `Makefile`. Entre no diretório desejado e execute:

```bash
make main
./build/main
```

Exemplo:

```bash
cd src/selection_sort
make main
./build/main
```
