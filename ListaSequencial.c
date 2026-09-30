#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista {
    int qtd;
    struct produto dados[MAX];
};

Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li) {
    free(li);
}

int tamanho_lista(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return li->qtd;
}

int lista_cheia(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return (li->qtd == 0);
}

int insere_lista_inicio(Lista* li, struct produto p) {
    if (li == NULL || lista_cheia(li)) {
        return 0;
    }
    for (int i = li->qtd; i > 0; i--) {
        li->dados[i] = li->dados[i - 1];
    }
    li->dados[0] = p;
    li->qtd++;
    return 1;
}

int insere_lista_final(Lista* li, struct produto p) {
    if (li == NULL || lista_cheia(li)) {
        return 0;
    }
    li->dados[li->qtd] = p;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct produto p) {
    if (li == NULL || lista_cheia(li)) {
        return 0;
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].codigo < p.codigo) {
        i++;
    }
    for (int j = li->qtd; j > i; j--) {
        li->dados[j] = li->dados[j - 1];
    }
    li->dados[i] = p;
    li->qtd++;
    return 1;
}

int remove_lista_inicio(Lista* li) {
    if (li == NULL || lista_vazia(li)) {
        return 0;
    }
    for (int i = 0; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL || lista_vazia(li)) {
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista(Lista* li, int cod) {
    if (li == NULL || lista_vazia(li)) {
        return 0;
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].codigo != cod) {
        i++;
    }
    if (i == li->qtd) {
        return 0;
    }
    for (int j = i; j < li->qtd - 1; j++) {
        li->dados[j] = li->dados[j + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int cod) {
    if (li == NULL || lista_vazia(li)) {
        return 0;
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].codigo != cod) {
        i++;
    }
    if (i == li->qtd) {
        return 0;
    }
    li->dados[i] = li->dados[li->qtd - 1];
    li->qtd--;
    return 1;
}

int busca_lista_pos(Lista* li, int pos, struct produto *p) {
    if (li == NULL || pos <= 0 || pos > li->qtd) {
        return 0;
    }
    *p = li->dados[pos - 1];
    return 1;
}

int busca_lista_cod(Lista* li, int cod, struct produto *p) {
    if (li == NULL) {
        return 0;
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].codigo != cod) {
        i++;
    }
    if (i == li->qtd) {
        return 0;
    }
    *p = li->dados[i];
    return 1;
}

int lista_tem_espaco(Lista* li, int n) {
    if (li == NULL || n < 0) {
        return 0;
    }
    return (li->qtd + n <= MAX);
}

float soma_precos(Lista* li) {
    if (li == NULL) {
        return 0.0f;
    }
    float soma = 0.0f;
    for (int i = 0; i < li->qtd; i++) {
        soma += li->dados[i].preco;
    }
    return soma;
}

int busca_por_nome(Lista* li, char* nome, struct produto *p) {
    if (li == NULL || nome == NULL || p == NULL) {
        return 0;
    }
    for (int i = 0; i < li->qtd; i++) {
        if (strcmp(li->dados[i].nome, nome) == 0) {
            *p = li->dados[i];
            return 1;
        }
    }
    return 0;
}

int insere_lista_decrescente(Lista* li, struct produto p) {
    if (li == NULL || lista_cheia(li)) {
        return 0;
    }
    int i = 0;
    while (i < li->qtd && li->dados[i].preco > p.preco) {
        i++;
    }
    for (int j = li->qtd; j > i; j--) {
        li->dados[j] = li->dados[j - 1];
    }
    li->dados[i] = p;
    li->qtd++;
    return 1;
}

int remove_mais_caro(Lista* li, struct produto *removido) {
    if (li == NULL || lista_vazia(li) || removido == NULL) {
        return 0;
    }
    int mais_caro = 0;
    for (int i = 1; i < li->qtd; i++) {
        if (li->dados[i].preco > li->dados[mais_caro].preco) {
            mais_caro = i;
        }
    }
    *removido = li->dados[mais_caro];
    li->dados[mais_caro] = li->dados[li->qtd - 1];
    li->qtd--;
    return 1;
}

int conta_faixa_preco(Lista* li, float min, float max) {
    if (li == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < li->qtd; i++) {
        if (li->dados[i].preco >= min && li->dados[i].preco <= max) {
            count++;
        }
    }
    return count;
}

int remove_abaixo_de(Lista* li, float precoMinimo) {
    if (li == NULL) {
        return 0;
    }
    int removidos = 0;
    int i = 0;
    while (i < li->qtd) {
        if (li->dados[i].preco < precoMinimo) {
            li->dados[i] = li->dados[li->qtd - 1];
            li->qtd--;
            removidos++;
        } else {
            i++;
        }
    }
    return removidos;
}

int mescla_listas(Lista* destino, Lista* origem) {
    if (destino == NULL || origem == NULL) {
        return 0;
    }
    int inseridos = 0;
    for (int i = 0; i < origem->qtd; i++) {
        if (lista_cheia(destino)) {
            break;
        }
        struct produto p = origem->dados[i];
        struct produto temp;
        if (!busca_lista_cod(destino, p.codigo, &temp)) {
            if (insere_lista_final(destino, p)) {
                inseridos++;
            } else {
                break;
            }
        }
    }
    return inseridos;
}