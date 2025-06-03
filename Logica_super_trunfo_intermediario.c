#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Cálculo da densidade demográfica
void calcularDensidade(Carta* c) {
    c->densidadeDemografica = c->populacao / c->area;
}

// Leitura da carta
void lerCarta(Carta* c, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Nome do país: ");
    getchar(); // Limpa o buffer
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0'; // Remove o '\n'

    printf("População: ");
    scanf("%d", &c->populacao);

    printf("Área (em km²): ");
    scanf("%f", &c->area);

    printf("PIB (em trilhões): ");
    scanf("%f", &c->pib);

    printf("Pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    calcularDensidade(c);
}

// Exibição do resultado
void exibirResultado(const char* atributo, const Carta* c1, const Carta* c2, float v1, float v2, int menorVence) {
    int vencedor = 0;
    if (v1 != v2)
        vencedor = (menorVence ? (v1 < v2 ? 1 : 2) : (v1 > v2 ? 1 : 2));

    printf("\n--- Resultado da Comparação ---\n");
    printf("Atributo: %s\n", atributo);
    printf("%s: %.2f\n", c1->nome, v1);
    printf("%s: %.2f\n", c2->nome, v2);
    if (vencedor == 1) printf("Vencedor: %s\n", c1->nome);
    else if (vencedor == 2) printf("Vencedor: %s\n", c2->nome);
    else printf("Empate!\n");
    printf("-------------------------------\n");
}

int main() {
    Carta carta1, carta2;
    int opcao;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    printf("\n=== Super Trunfo - Comparação de Cartas ===\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (vence o MENOR valor)\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            exibirResultado("População", &carta1, &carta2, carta1.populacao, carta2.populacao, 0);
            break;
        case 2:
            exibirResultado("Área", &carta1, &carta2, carta1.area, carta2.area, 0);
            break;
        case 3:
            exibirResultado("PIB", &carta1, &carta2, carta1.pib, carta2.pib, 0);
            break;
        case 4:
            exibirResultado("Pontos Turísticos", &carta1, &carta2, carta1.pontosTuristicos, carta2.pontosTuristicos, 0);
            break;
        case 5:
            exibirResultado("Densidade Demográfica", &carta1, &carta2, carta1.densidadeDemografica, carta2.densidadeDemografica, 1);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}