#include <stdio.h>

int soma_lista_recursiva(int lista[], int tamanho) {
    // Caso base: a soma de uma lista vazia é 0.
    if (tamanho <= 0) {
        return 0;
    }
    
    // Passo recursivo: soma o último elemento com a soma do resto da lista
    return lista[tamanho - 1] + soma_lista_recursiva(lista, tamanho - 1);
}

int main() {
    int numeros[] = {1, 2, 3, 4};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    int soma = soma_lista_recursiva(numeros, tamanho);
    
    printf("A lista é: [1, 2, 3, 4]\n");
    printf("A soma dos elementos é: %d\n", soma); // Exemplo: 10
    
    return 0;
}