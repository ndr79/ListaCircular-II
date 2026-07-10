#ifndef listaCircular_h
#define listaCircular_h

#include <stdio.h>

typedef int TipoItem;   // tipo do elemento da lista

// Declaração da estrutura nó
typedef struct no {
    TipoItem info;
    struct no* ant;
    struct no* prox;
} Lista;


#endif /* listaCircular_h */