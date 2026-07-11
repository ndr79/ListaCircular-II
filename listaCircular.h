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

// Verifica se a lista é vazia
// Entrada: lista
// Retorno: 1 se a lista estivar vazia ou 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia(Lista* l);

// Faz a inserção de um item na cauda da lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é inserido na cauda da lista
Lista* inserir(Lista* l, TipoItem info);

// Libera todos os nós da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: toda a memória alocada para a lista é liberada
void liberar(Lista* l);

// Imprimi todos os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: os elementos da lista são exibidos na tela
void imprimir(Lista* l);

// Faz a remoção de um item da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é removido da lista, caso exista
Lista* retirar(Lista* l, TipoItem x);

#endif /* listaCircular_h */