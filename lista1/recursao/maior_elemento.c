#include <stdio.h>

int maximo_lista_recursivo(int lista[], int tamanho) {
    // Caso base: se a lista tem um só elemento, ele é o maior.
    if (tamanho == 1) {
        return lista[0];
    }
    
    // Chamada recursiva para encontrar o maior no restante da lista
    int max_do_resto = maximo_lista_recursivo(lista, tamanho - 1);
    
    // Compara o resultado da chamada recursiva com o último elemento
    if (lista[tamanho - 1] > max_do_resto) {
        return lista[tamanho - 1];
    } else {
        return max_do_resto;
    }
}

int main() {
    int numeros[] = {3, 7, 2, 9, 1};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    int maior = maximo_lista_recursivo(numeros, tamanho);
    
    printf("A lista é: [3, 7, 2, 9, 1]\n");
    printf("O maior elemento é: %d\n", maior); // Exemplo: 9
    
    return 0;
}