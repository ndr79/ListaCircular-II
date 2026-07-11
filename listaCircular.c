#include "listaCircular.h"

#include <stdlib.h>

// Verifica se a lista é vazia
// Entrada: lista
// Retorno: 1 se a lista estivar vazia ou 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia(Lista* l) {
    return (l == NULL);
}

// Faz a inserção de um item na cauda da lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é inserido na cauda da lista
Lista* inserir(Lista* l, TipoItem info) {
    Lista* aux = malloc(sizeof(Lista));

    if(aux == NULL) {
        printf("Erro de alocação.\n");
        return l;
    }

    aux->info = info;

    if(vazia(l)) {
        aux->prox = aux;
        aux->ant = aux;
        return aux;
    }

    Lista* ultimo = l->ant;

    aux->prox = l;
    aux->ant = ultimo;

    ultimo->prox = aux;
    l->ant = aux;

    return l;
}

// Libera todos os nós da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: toda a memória alocada para a lista é liberada
void liberar(Lista* l) {
    if(vazia(l))
        return;

    Lista* p = l->prox;

    while(p != l) {
        Lista* aux = p;
        p = p->prox;
        free(aux);
    }

    free(l);
}

// Imprimi todos os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: os elementos da lista são exibidos na tela
void imprimir(Lista* l) {
    if(vazia(l))
        printf("Lista vazia.\n");
    else {
        Lista* p = l;

        printf("[ ");
        do {
            printf("%d ", p->info);
            p = p->prox;
        } while(p != l);
        printf("]\n");
    }
}

// Faz a remoção de um item da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é removido da lista, caso exista
Lista* retirar(Lista* l, TipoItem x) {
    if(vazia(l)) {
        printf("Lista vazia.\n");
        return l;
    }

    Lista* p = l;

    do {
        if(p->info == x)
            break;
        p = p->prox;
    } while(p != l);

    if(p->info != x) {
        printf("Elemento não encontrado.\n");
        return l;
    }

    if(p->prox == p) {  // lista com apenas um elemento
        free(p);
        return NULL;
    }

    // Ajusta os ponteiros
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;

    if(p == l)  // caso a cabeça tenha sido removida
        l = p->prox;
    
    free(p);

    return l;
}