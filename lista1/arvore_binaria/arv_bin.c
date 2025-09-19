#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MIN e INT_MAX na verificação de BST

// Estrutura do nó da árvore
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

// 1) Função para criar e inserir novos nós [cite: 14, 15]
No* criar_no(int chave) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criar_no(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

// 2) Percursos em Árvore [cite: 16]
void pre_ordem(No* raiz) { // (Raiz, Esquerda, Direita) [cite: 18]
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void in_ordem(No* raiz) { // (Esquerda, Raiz, Direita) [cite: 19]
    if (raiz != NULL) {
        in_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        in_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz) { // (Esquerda, Direita, Raiz) [cite: 20]
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

// 3) Altura da Árvore [cite: 21, 22]
int altura(No* raiz) {
    if (raiz == NULL) {
        return -1; // Altura de uma árvore vazia
    }
    int altura_esq = altura(raiz->esquerda);
    int altura_dir = altura(raiz->direita);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

// 4) a) Contagem de Nós Totais [cite: 24, 25]
int contar_nos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

// 4) b) Contagem de Nós Folha [cite: 26]
int contar_folhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1; // É uma folha
    }
    return contar_folhas(raiz->esquerda) + contar_folhas(raiz->direita);
}

// 5) Busca em Árvore Binária de Busca (BST) [cite: 27, 28, 29]
No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

// 6) Menor e Maior Elemento em BST [cite: 30, 31]
No* encontrar_menor(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* encontrar_maior(No* raiz) {
    No* atual = raiz;
    while (atual && atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual;
}

// 7) Verificar se é BST [cite: 32, 33, 34]
int eh_bst_util(No* no, int min, int max) {
    if (no == NULL) {
        return 1; // Árvore vazia é uma BST
    }
    if (no->chave < min || no->chave > max) {
        return 0;
    }
    return eh_bst_util(no->esquerda, min, no->chave - 1) &&
           eh_bst_util(no->direita, no->chave + 1, max);
}

int eh_bst(No* raiz) {
    return eh_bst_util(raiz, INT_MIN, INT_MAX);
}

// função principal para testar a árvore
int main() {
    No* raiz = NULL;
    int elementos[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    printf("Inserindo elementos: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", elementos[i]);
        raiz = inserir(raiz, elementos[i]);
    }
    printf("\n\n");

    printf("Percurso em Pré-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Percurso em In-ordem: ");
    in_ordem(raiz);
    printf("\n");
    
    printf("Percurso em Pós-ordem: ");
    pos_ordem(raiz);
    printf("\n\n");

    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Número total de nós: %d\n", contar_nos(raiz));
    printf("Número de nós folha: %d\n\n", contar_folhas(raiz));

    int valor_busca = 7;
    printf("Buscando pelo valor %d: %s\n", valor_busca, buscar(raiz, valor_busca) ? "Encontrado" : "Não encontrado");
    valor_busca = 99;
    printf("Buscando pelo valor %d: %s\n\n", valor_busca, buscar(raiz, valor_busca) ? "Encontrado" : "Não encontrado");

    No* menor = encontrar_menor(raiz);
    No* maior = encontrar_maior(raiz);
    printf("Menor elemento da BST: %d\n", menor ? menor->chave : -1);
    printf("Maior elemento da BST: %d\n\n", maior ? maior->chave : -1);

    printf("A árvore é uma BST? %s\n", eh_bst(raiz) ? "Sim" : "Não");

    // exemplo de uma árvore que NÃO é BST para teste
    No* nao_bst = criar_no(10);
    nao_bst->esquerda = criar_no(5);
    nao_bst->direita = criar_no(15);
    nao_bst->esquerda->direita = criar_no(20); // viola a propriedade da BST
    printf("A segunda árvore é uma BST? %s\n", eh_bst(nao_bst) ? "Sim" : "Não");

    return 0;
}