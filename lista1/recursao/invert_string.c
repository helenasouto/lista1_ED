#include <stdio.h>
#include <string.h>

void inverter_string_recursivo(char str[], int inicio, int fim) {
    // caso base: se o início for maior ou igual ao fim, a string está invertida.
    if (inicio >= fim) {
        return;
    }
    
    // troca o caractere do início com o do fim
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    // chamada recursiva para o resto
    inverter_string_recursivo(str, inicio + 1, fim - 1);
}

int main() {
    char minha_string[] = "recursao";
    printf("String original: %s\n", minha_string);
    
    int n = strlen(minha_string);
    inverter_string_recursivo(minha_string, 0, n - 1);
    
    printf("String invertida: %s\n", minha_string); // Exemplo: "oasrucer"
    
    return 0;
}