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