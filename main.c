#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main() {
    Lista* lista1 = cria_lista();
    Lista* lista2 = cria_lista();

    struct produto p1 = {1, "cpu", 150.0f};
    struct produto p2 = {2, "mobo", 80.0f};
    struct produto p3 = {3, "fonte", 900.0f};
    struct produto p4 = {4, "gpu", 50.0f};
    struct produto p5 = {5, "ram", 300.0f};
    struct produto produto;

    if (lista1 != NULL) {
        printf("lista 1 criada com sucesso\n");
    } else {
        printf("falha ao criar a lista 1\n");
    }
    if (lista2 != NULL) {
        printf("lista 2 criada com sucesso\n");
    } else {
        printf("falha ao criar a lista 2\n");
    }
    printf("lista vazia: %d\n", lista_vazia(lista1));
    printf("lista cheia: %d\n", lista_cheia(lista1));
    printf("tamanho inicial: %d\n", tamanho_lista(lista1));
    printf("espaco para 5 itens: %d\n", lista_tem_espaco(lista1, 5));

    printf("insere no final: %d\n", insere_lista_final(lista1, p1));
    printf("insere no inicio: %d\n", insere_lista_inicio(lista1, p2));
    printf("insere ordenado: %d\n", insere_lista_ordenada(lista1, p3));
    printf("tamanho atual: %d\n", tamanho_lista(lista1));

    if (busca_lista_pos(lista1, 1, &produto)) {
        printf("busca na posicao 1: %s cod %d\n", produto.nome, produto.codigo);
    }
    if (busca_lista_cod(lista1, 1, &produto)) {
        printf("busca pelo codigo 1: %s\n", produto.nome);
    }
    if (busca_por_nome(lista1, "cpu", &produto)) {
        printf("busca pelo nome cpu: cod %d\n", produto.codigo);
    }
    if (busca_por_nome(lista1, "ssd", &produto)) {
        printf("busca pelo nome ssd: cod %d\n", produto.codigo);
    } else {
        printf("produto ssd nao encontrado\n");
    }

    printf("soma dos precos: R$ %.2f\n", soma_precos(lista1));
    printf("itens entre R$ 70 e R$ 200: %d\n", conta_faixa_preco(lista1, 70.0f, 200.0f));
    printf("espaco para mais 5 itens: %d\n", lista_tem_espaco(lista1, 5));

    printf("insere decrescente na outra lista: %d\n", insere_lista_decrescente(lista2, p4));
    printf("insere decrescente na outra lista: %d\n", insere_lista_decrescente(lista2, p5));
    printf("itens inseridos na mescla: %d\n", mescla_listas(lista1, lista2));
    printf("tamanho apos mescla: %d\n", tamanho_lista(lista1));

    if (remove_mais_caro(lista1, &produto)) {
        printf("mais caro removido: %s cod %d R$ %.2f\n", produto.nome, produto.codigo, produto.preco);
    }
    printf("remove pelo codigo 2: %d\n", remove_lista(lista1, 2));
    printf("remove otimizado pelo codigo 4: %d\n", remove_lista_otimizado(lista1, 4));
    printf("remove o primeiro: %d\n", remove_lista_inicio(lista1));
    printf("remove o ultimo: %d\n", remove_lista_final(lista1));
    printf("itens removidos abaixo de R$ 100: %d\n", remove_abaixo_de(lista1, 100.0f));

    printf("lista vazia no final: %d\n", lista_vazia(lista1));
    libera_lista(lista1);
    libera_lista(lista2);
    return 0;
}