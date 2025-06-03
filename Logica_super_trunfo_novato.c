#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Função para calcular a densidade populacional e o PIB per capita
void calcular_indicadores(struct Carta* c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para exibir os dados da carta
void exibir_carta(struct Carta c) {
    printf("%s (%s):\n", c.nome, c.estado);
    printf("  Código: %s\n", c.codigo);
    printf("  População: %d\n", c.populacao);
    printf("  Área: %.2f km²\n", c.area);
    printf("  PIB: R$ %.2f bilhões\n", c.pib);
    printf("  Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("  Densidade populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", c.pib_per_capita);
    printf("\n");
}

// Função para ler os dados da carta via entrada do usuário
void ler_carta(struct Carta* c, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    
    printf("  Nome: ");
    getchar(); // limpar o buffer
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0'; // remover newline

    printf("  Estado: ");
    scanf("%2s", c->estado);

    printf("  Código da carta: ");
    scanf("%s", c->codigo);

    printf("  População: ");
    scanf("%d", &c->populacao);

    printf("  Área (km²): ");
    scanf("%f", &c->area);

    printf("  PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("  Pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);

    calcular_indicadores(c);
}

int main() {
    struct Carta carta1, carta2;

    // Leitura das cartas
    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);

    // Exibição das cartas
    printf("\nCarta 1:\n");
    exibir_carta(carta1);
    printf("Carta 2:\n");
    exibir_carta(carta2);

    // Comparação por população
    printf("Comparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s: %d habitantes\n", carta1.nome, carta1.populacao);
    printf("Carta 2 - %s: %d habitantes\n", carta2.nome, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}