#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[10];
    float peso;
    float velocidade;
    int vida;
    int forca;
} Carta;

void mostrarAtributos(int ignorar) {
    if (ignorar != 1) printf("1 - Peso (kg)\n");
    if (ignorar != 2) printf("2 - Velocidade (km/h)\n");
    if (ignorar != 3) printf("3 - Expectativa de Vida (anos)\n");
    if (ignorar != 4) printf("4 - Força\n");
}

float obterValor(Carta c, int atributo) {
    if (atributo == 1) return c.peso;
    if (atributo == 2) return c.velocidade;
    if (atributo == 3) return c.vida;
    if (atributo == 4) return c.forca;
    return 0;
}

void nomeAtributo(int atributo) {
    if (atributo == 1) printf("Peso");
    if (atributo == 2) printf("Velocidade");
    if (atributo == 3) printf("Expectativa de Vida");
    if (atributo == 4) printf("Força");
}

int main() {

    srand(time(NULL));

    Carta cartas[3] = {
        {"Leao", 150 + rand() % 100, 60 + rand() % 40, 10 + rand() % 10, 7 + rand() % 3},
        {"Elefante", 4000 + rand() % 3000, 20 + rand() % 15, 60 + rand() % 20, 8 + rand() % 3},
        {"Guepardo", 60 + rand() % 30, 100 + rand() % 30, 8 + rand() % 7, 6 + rand() % 3}
    };

    int c1, c2, a1, a2;

    printf("=== TRUNFO DE ANIMAIS ===\n\n");
    printf("1 - Leao\n2 - Elefante\n3 - Guepardo\n");

    do {
        printf("\nCarta 1: ");
        scanf("%d", &c1);
    } while (c1 < 1 || c1 > 3);
    c1--;

    do {
        printf("Carta 2 (diferente da primeira): ");
        scanf("%d", &c2);
    } while (c2 < 1 || c2 > 3 || c2 - 1 == c1);
    c2--;

    do {
        printf("\nEscolha o PRIMEIRO atributo:\n");
        mostrarAtributos(0);
        printf("Opcao: ");
        scanf("%d", &a1);
    } while (a1 < 1 || a1 > 4);

    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        mostrarAtributos(a1);
        printf("Opcao: ");
        scanf("%d", &a2);
    } while (a2 < 1 || a2 > 4 || a2 == a1);

    float v1 = obterValor(cartas[c1], a1) + obterValor(cartas[c1], a2);
    float v2 = obterValor(cartas[c2], a1) + obterValor(cartas[c2], a2);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n\n");

    printf("Carta 1: %s\n", cartas[c1].nome);
    printf("Carta 2: %s\n\n", cartas[c2].nome);

    printf("Atributos escolhidos: ");
    nomeAtributo(a1);
    printf(" e ");
    nomeAtributo(a2);
    printf("\n\n");

    printf("Soma %s: %.2f\n", cartas[c1].nome, v1);
    printf("Soma %s: %.2f\n\n", cartas[c2].nome, v2);

    if (v1 > v2)
        printf("Vencedor: %s\n", cartas[c1].nome);
    else if (v2 > v1)
        printf("Vencedor: %s\n", cartas[c2].nome);
    else
        printf("Empate!\n");

    return 0;
}
