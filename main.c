#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dado[50];
    int prioridade; // 1 = alta, 2 = média, 3 = baixa
} ItemPrioridade;

typedef struct {
    ItemPrioridade itens[MAX];
    int tamanho;
} Fila;

void inicializarFila(Fila *fila) {
    fila->tamanho = 0;
}

bool fila_enqueue_prioridade(Fila *fila, ItemPrioridade item) {
    if (fila->tamanho >= MAX) return false;

    int i = fila->tamanho - 1;
    while (i >= 0 && fila->itens[i].prioridade > item.prioridade) {
        fila->itens[i + 1] = fila->itens[i];
        i--;
    }

    fila->itens[i + 1] = item;
    fila->tamanho++;
    return true;
}

void imprimirFila(Fila *fila) {
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%s (prioridade %d)\n", fila->itens[i].dado, fila->itens[i].prioridade);
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    ItemPrioridade a = {"Atendimento Normal", 3};
    ItemPrioridade b = {"Emergência", 1};
    ItemPrioridade c = {"Atendimento Preferencial", 2};

    fila_enqueue_prioridade(&fila, a);
    fila_enqueue_prioridade(&fila, b);
    fila_enqueue_prioridade(&fila, c);

    imprimirFila(&fila);

    return 0;
}
